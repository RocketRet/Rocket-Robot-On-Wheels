#!/usr/bin/python3

import sys

with open("tools/fixups.txt", "r") as file:
    cur_asm_file = None
    lines = None
    for line in file.readlines():
        if line.startswith("asm/"):
            if lines:
                with open(cur_asm_file, "w") as asm_file:
                    for linecontents in lines:
                        asm_file.write(linecontents.strip("\n") + "\r\n")
            cur_asm_file = line.strip()
            with open(cur_asm_file, "r") as asm_file:
                lines = list(asm_file.readlines())
        elif line.strip():
            tokens = line.split(":")
            line_num = int(tokens[0])
            line_contents = tokens[1]
            old_line_contents = lines[line_num - 1]
            if old_line_contents == line_contents:
                print(f"Identical @ {cur_asm_file}:{line_num}")
            elif old_line_contents[0:15] != line_contents[0:15]:
                print(f"Too different @ {cur_asm_file}:{line_num}")
            else:
                lines[line_num - 1] = line_contents
    
    if lines:
        with open(cur_asm_file, "w") as asm_file:
            for linecontents in lines:
                asm_file.write(linecontents.strip("\n") + "\r\n")
