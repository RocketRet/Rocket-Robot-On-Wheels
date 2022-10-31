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

    funcs_matched = 0
    funcs_unmatched = 0
    total_matched = 0
    total_unmatched = 0
    next_nonmatched = False

    nonmatchings = set()

    # Pass 1: get all nonmatchings
    for line in nm_lines:
        if "g       *ABS*" in line:
            components = line.split()
            name = components[-1]
            if name.endswith("_NONMATCHING"):
                nonmatchings.add(name[:-12])

    # Pass 2: sum size of nonmatchings
    for line in nm_lines:
        if "g     F ." in line:
            components = line.split()
            size = int(components[-2], 16)
            name = components[-1]
            if name in nonmatchings:
                total_unmatched += size
                funcs_unmatched += 1
            elif not name.endswith("_NONMATCHING"):
                # TODO calculate matched functions using ctags to find total and subtract nonmatchings instead of this
                # This method misses static functions
                funcs_matched += 1
                total_matched += size

    return funcs_matched, funcs_unmatched, total_matched, total_unmatched

def main(args):
    total_size = (
        # Add code segments
          (0x002090 - 0x0019D0) # codeseg0
        + (0x0189E0 - 0x004150) # codeseg1
        + (0x09FC70 - 0x01EA00) # codeseg2
        # Subtract asm files
        - (0x004D50 - 0x004CB0) # bzero
        - (0x004F10 - 0x004EB0) # padding
        - (0x005130 - 0x0050B0) # writebackdcache
        - (0x008A80 - 0x0089D0) # invaldcache
        - (0x00B370 - 0x00B340) # writebackdcacheall
        - (0x00B9F0 - 0x00B950) # setintmask
        - (0x00BE60 - 0x00BE20) # interrupt
        - (0x00C7F0 - 0x00BEA0) # exceptasm
        - (0x00E560 - 0x00E530) # getsr, setsr, setfpccsr
        - (0x00E740 - 0x00E660) # invalicache, maptlbrdb
        - (0x00E7F0 - 0x00E7E0) # getcount
        - (0x010AC0 - 0x0107A0) # bcopy
        - (0x015520 - 0x015460) # probetlb
        - (0x015550 - 0x015540) # setcompare
    )
    funcs_matched, funcs_unmatched, total_matched, total_unmatched = get_matching_stats()

    funcs_total = funcs_matched + funcs_unmatched
    total_matched = total_size - total_unmatched

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
