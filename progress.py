#!/usr/bin/env python3

import argparse
import git
import os
import subprocess
import sys

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir
asm_dir = os.path.join(root_dir, "asm", "nonmatchings")
build_dir = os.path.join(root_dir, "build", "us")
elf_path = os.path.join(build_dir, "NSUE.elf")

def get_matching_stats():
    try:
        result = subprocess.run(['objdump', '-x', elf_path], stdout=subprocess.PIPE)
        nm_lines = result.stdout.decode().split("\n")
    except:
        print(f"Error: Could not run objdump on {elf_path} - make sure that the project is built")
        sys.exit(1)

    sizes = {}
    starts = {}
    ends = {}
    funcs_matched = 0
    funcs_unmatched = 0
    total_matched = 0
    total_unmatched = 0

    for line in nm_lines:
        if "g     F .code" in line or "g     F *ABS*	" in line:
            components = line.split()
            size = int(components[4], 16)
            name = components[5]
            total_matched += size
            funcs_matched += 1
        elif "g       .code" in line:
            components = line.split()
            addr = int(components[0], 16)
            name = components[4]
            startAddr = 0
            endAddr = 0
            if name.endswith("_end"):
                name = name[:-4]
                endAddr = int(components[0], 16)
                ends[name] = endAddr
                if name in starts:
                    startAddr = starts[name]
            else:
                startAddr = int(components[0], 16)
                starts[name] = startAddr
                if name in ends:
                    endAddr = ends[name]
            if startAddr != 0 and endAddr != 0:
                size = endAddr - startAddr
                total_unmatched += size
                funcs_unmatched += 1


    return funcs_matched, funcs_unmatched, total_matched, total_unmatched

def main(args):
    funcs_matched, funcs_unmatched, total_matched, total_unmatched = get_matching_stats()

    funcs_total = funcs_matched + funcs_unmatched
    total_size = total_matched + total_unmatched

    funcs_matching_ratio = (funcs_matched / funcs_total) * 100
    matching_ratio = (total_matched / total_size) * 100

    if args.csv:
        version = 1
        git_object = git.Repo().head.object
        timestamp = str(git_object.committed_date)
        git_hash = git_object.hexsha
        csv_list = [str(version), timestamp, git_hash, str(funcs_total), str(funcs_unmatched),
                    str(funcs_matched), str(total_size), str(total_unmatched), str(total_matched)]
        print(",".join(csv_list))
    elif args.shield_json:
        import json

        # https://shields.io/endpoint
        print(json.dumps({
            "schemaVersion": 1,
            "label": "progress",
            "message": f"{matching_ratio:.2f}%",
            "color": "yellow",
        }))
    else:
        print(f"{funcs_matched} matched functions / {funcs_total} total ({funcs_matching_ratio:.2f}%)")
        print(f"{total_matched} matching bytes / {total_size} total ({matching_ratio:.2f}%)")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Reports progress for the project")
    parser.add_argument("--csv", action="store_true")
    parser.add_argument("--shield-json", action="store_true")
    args = parser.parse_args()

    main(args)
