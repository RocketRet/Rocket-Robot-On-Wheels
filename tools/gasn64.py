#!/usr/bin/env python3
# Preprocesses an input asm file to match asn64's reordering and macro expansion, then passes it to the provided assembler.

import sys
import subprocess
from typing import *

assembler: str = sys.argv[1]
input_filename: str = sys.argv[2]
flags: List[str] = sys.argv[3:]

branch_mnemonics: Set[str] = {
    "bc1f", "bc1fl", "bc1t", "bc1tl", # cop1
    "beq", "beql", # ==
    "bgez", "bgezal", "bgezall", "bgezl", # >= 0
    "bgtz", "bgtzl", # > 0
    "blez", "blezl", # <= 0
    "bltz", "bltzal", "bltzall", "bltzl", # < 0
    "bne", "bnel", # !=
    "j", "jal", "jalr", "jr" # unconditional absolute jumps
    "blt", "ble", "bgt", "bge" # pseudo instructions
}

cop1_branch_mnemonics: Set[str] = {
    "bc1f", "bc1fl", "bc1t", "bc1tl" # cop1
}

# There are many more than these, but cc1 only generates these
compare_mnemonics: Set[str] = {
    "c.lt.s", "c.le.s", "c.eq.s",
    "c.lt.d", "c.le.d", "c.eq.d"
}

def get_line_tokens(line: str) -> List[str]:
    stripped: str = line.strip().split("#")[0].strip()
    return [s.strip() for s in stripped.split()]

with open(input_filename, mode="r") as input_file:
    input_lines: List[str] = input_file.readlines()
    preprocessed: List[str] = [
        "\t.include \"gasn64.inc\"\n",
        "\t.set noreorder\n"
    ]
    line: str
    is_reorder: bool = True
    generated_symbol_count: int = 0
    at_common: bool = False
    mfhilo_delay_count: int = 0
    mfhilo_delay_location: int = 0
    prev_mul: bool = False
    comm_symbols: List[Tuple] = []
    lcomm_symbols: List[Tuple] = []
    # Holds the branch target string if the current instruction is a delay slot
    delay_slot: bool = False
    file_count: int = 0
    prev_instruction_index: int = 0

    for line_index, line in enumerate(input_lines):
        tokens: List[str] = get_line_tokens(line)
        # SN64 inserts nops when it sees a commented out nop directly after a cop1 compare instruction
        if line[1:5] == "#nop":
            prev_instruction_tokens: List[str] = get_line_tokens(input_lines[prev_instruction_index])
            if prev_instruction_tokens[0] in compare_mnemonics:
                line = "\tnop\n"
        if len(tokens) == 0:
            preprocessed.append(line)
            continue
        identifier: str = tokens[0]
        operands: List[str]
        new_prev_mul: bool = False
        is_branch: bool = False
        is_instruction: bool = False

        if identifier[0] == ".": # Directives
            directive: str = identifier[1:]
            if directive == "set":
                setting: str = tokens[1]
                if setting == "noreorder":
                    is_reorder = False
                    continue # skip noreorder directives
                elif setting == "reorder":
                    is_reorder = True
                    continue # skip reorder directives
            elif directive == "comm":
                # Record .comm symbols and sizes to emit to bss later
                comm_symbol: str
                comm_size: str
                comm_symbol, comm_size = [s.strip() for s in tokens[1].split(",")]
                comm_symbols.append((comm_symbol, comm_size))
                line = ""
            elif directive == "lcomm":
                # Record .lcomm symbols and sizes to emit to bss later
                lcomm_symbol: str
                lcomm_size: str
                lcomm_symbol, lcomm_size = [s.strip() for s in tokens[1].split(",")]
                lcomm_symbols.append((lcomm_symbol, lcomm_size))
                line = ""
            elif directive == "file":
                # SN's cc1 has issues reusing file numbers in .file directives, so fix them up
                file_count += 1
                line = f"\t.file\t{file_count} {tokens[2]}\n"
            elif directive in ["def", "begin", "bend"]:
                # Modern gas doesn't understand these directives, so get rid of them
                line = ""
        elif identifier[-1] == ":": # Labels
            # Nothing to do here, but it might be handy to have in the future
            label_name: str = identifier[:-1]
            pass
        else: # Macros or instructions
            is_instruction = True
            if identifier in branch_mnemonics:
                is_branch = True
                if is_reorder:
                    line += "\tnop\n" # insert a nop after the instruction
            elif identifier == "li.s":
                float_sym_name: str = f"RODATA_SYM_{generated_symbol_count}"
                operands = [s.strip() for s in tokens[1].split(",")]
                if operands[0][1] == "f": # Only expand for float register targets
                    line = (
                        "\t.section .rodata\n"
                        f"{float_sym_name}:\n"
                        "\t.align 2\n"
                        f"\t.float {operands[1]}\n"
                        "\t.text\n"
                        "\t.set\tnoat\n"
                        f"\tlui $at, %hi({float_sym_name})\n"
                        f"\tlwc1 {operands[0]}, %lo({float_sym_name})($at)\n"
                        "\t.set\tat\n"
                    )
                    generated_symbol_count += 1
            elif identifier == "li.d":
                double_sym_name: str = f"RODATA_SYM_{generated_symbol_count}"
                operands = [s.strip() for s in tokens[1].split(",")]
                if operands[0][1] == "f": # Only expand for float register targets
                    line = (
                        "\t.section .rodata\n"
                        f"{double_sym_name}:\n"
                        "\t.align 3\n"
                        f"\t.double {operands[1]}\n"
                        "\t.text\n"
                        "\t.set\tnoat\n"
                        f"\tlui $at, %hi({double_sym_name})\n"
                        f"\tldc1 {operands[0]}, %lo({double_sym_name})($at)\n"
                        "\t.set\tat\n"
                    )
                    generated_symbol_count += 1
                # TODO expand li.d correctly in the case of a GPR target
                # addiu zero, 0 (word 2); lui (word 1) for a halfword double
                # addiu zero, 0 (word 2); lui + ori (word 1) for a full word double
                # lui (word 2); lui + ori (word 1) for a 1.5 word double,
                # lui + ori (word 2); lui + ori (word 1) for a 2 word double
            elif identifier in "div":
                # Insert nops if there was a mflo/mfhi recently right after it
                while mfhilo_delay_count > 0:
                    preprocessed.append("\tnop\n")
                    mfhilo_delay_count -= 1
                # Manually expand div operations, since modern gnu assembler expands them slightly differently
                operands = [s.strip() for s in tokens[1].split(",")]
                if operands[0] != "$0":
                    div_branch_label_1: str = f"BRANCH_LABEL_{generated_symbol_count}"
                    div_branch_label_2: str = f"BRANCH_LABEL_{generated_symbol_count + 1}"
                    generated_symbol_count += 2
                    line = (
                         "\t.set noat\n"
                        f"\tdiv $0,{operands[1]},{operands[2]}\n"
                        f"\tbnez {operands[2]},{div_branch_label_1}\n"
                         "\tnop\n"
                         "\tbreak 0x7\n"
                        f"{div_branch_label_1}:\n"
                         "\taddiu $1,$0,-1\n"
                        f"\tbne {operands[2]},$1,{div_branch_label_2}\n"
                         "\tlui $1,0x8000\n"
                        f"\tbne {operands[1]},$1,{div_branch_label_2}\n"
                         "\tnop\n"
                         "\tbreak 0x6\n"
                        f"{div_branch_label_2}:\n"
                        f"\tmflo {operands[0]}\n"
                         "\t.set at\n"
                    )
                    mfhilo_delay_count = 3 # Set to 3 so it becomes 2 after the decrement
                    mfhilo_delay_location = len(preprocessed) + 1
            elif identifier in "divu":
                # Insert nops if there was a mflo/mfhi recently right after it
                while mfhilo_delay_count > 0:
                    preprocessed.append("\tnop\n")
                    mfhilo_delay_count -= 1
                # Manually expand divu operations, since modern gnu assembler expands them slightly differently
                operands = [s.strip() for s in tokens[1].split(",")]
                if operands[0] != "$0":
                    divu_branch_label: str = f"BRANCH_LABEL_{generated_symbol_count}"
                    generated_symbol_count += 1
                    line = (
                         "\t.set noat\n"
                        f"\tdivu $0,{operands[1]},{operands[2]}\n"
                        f"\tbnez {operands[2]},{divu_branch_label}\n"
                         "\tnop\n"
                         "\tbreak 0x7\n"
                        f"{divu_branch_label}:\n"
                        f"\tmflo {operands[0]}\n"
                         "\t.set at\n"
                    )
                    mfhilo_delay_count = 3 # Set to 3 so it becomes 2 after the decrement
                    mfhilo_delay_location = len(preprocessed) + 1
            elif identifier == "rem":
                # Insert nops if there was a mflo/mfhi recently right after it
                while mfhilo_delay_count > 0:
                    preprocessed.append("\tnop\n")
                    mfhilo_delay_count -= 1
                # Manually expand rem operations, since modern gnu assembler expands them slightly differently
                operands = [s.strip() for s in tokens[1].split(",")]
                if operands[0] != "$0":
                    rem_branch_label_1: str = f"BRANCH_LABEL_{generated_symbol_count}"
                    rem_branch_label_2: str = f"BRANCH_LABEL_{generated_symbol_count + 1}"
                    generated_symbol_count += 2
                    line = (
                         "\t.set noat\n"
                        f"\tdiv $0,{operands[1]},{operands[2]}\n"
                        f"\tbnez {operands[2]},{rem_branch_label_1}\n"
                         "\tnop\n"
                         "\tbreak 0x7\n"
                        f"{rem_branch_label_1}:\n"
                         "\taddiu $1,$0,-1\n"
                        f"\tbne {operands[2]},$1,{rem_branch_label_2}\n"
                         "\tlui $1,0x8000\n"
                        f"\tbne {operands[1]},$1,{rem_branch_label_2}\n"
                         "\tnop\n"
                         "\tbreak 0x6\n"
                        f"{rem_branch_label_2}:\n"
                        f"\tmfhi {operands[0]}\n"
                         "\t.set at\n"
                    )
                    mfhilo_delay_count = 3 # Set to 3 so it becomes 2 after the decrement
                    mfhilo_delay_location = len(preprocessed) + 1
            elif identifier in ["mflo", "mfhi"]:
                mfhilo_delay_count = 3 # Set to 3 so it becomes 2 after the decrement
                mfhilo_delay_location = len(preprocessed) + 1
            elif identifier == "mult":
                # SN64 reorders delay slot mult instructions in noreorder to prevent mulmul bugs if the branch target starts with a multiply
                # However, it doesn't do it needs to insert nops after a mfhi/mflo
                if delay_slot and not is_reorder and mfhilo_delay_count <= 0:
                    preprocessed.insert(len(preprocessed) - 1, line)
                    line = "\tnop\n"
                # Insert nops if there was a mflo/mfhi recently right after it
                while mfhilo_delay_count > 0:
                    if delay_slot:
                        preprocessed.insert(mfhilo_delay_location, "\tnop\n")
                    else:
                        preprocessed.append("\tnop\n")
                    mfhilo_delay_count -= 1
                if prev_mul:
                    line = "\tnop\n" + line
                new_prev_mul = True
            elif identifier in ["mul.s", "mul.d"]:
                # SN64 reorders delay slot mul.s/mul.d instructions in noreorder
                if delay_slot and not is_reorder and mfhilo_delay_count <= 0:
                    preprocessed.insert(len(preprocessed) - 1, line)
                    line = "\tnop\n"
                if prev_mul:
                    line = "\tnop\n" + line
                new_prev_mul = True

            # This isn't great as it doesn't account for macros correctly, but it should be fine for the subset of inputs actually used
            if mfhilo_delay_count > 0:
                mfhilo_delay_count -= 1
            
            prev_mul = new_prev_mul
            delay_slot = is_branch
            prev_instruction_index = line_index


        preprocessed.append(line)

    if len(comm_symbols) > 0 or len(lcomm_symbols) > 0:
        preprocessed.append("\t.section\t.bss\n")
    for (symbol, size) in lcomm_symbols:
        if int(size) > 4:
            preprocessed.append("\t.align 3\n")
        preprocessed.append(
            f"\t.globl {symbol}\n"
            f"{symbol}:\n"
            f"\t.space {size}\n"
        )
    for (symbol, size) in comm_symbols:
        if int(size) > 4:
            preprocessed.append("\t.align 3\n")
        preprocessed.append(
            f"\t.globl {symbol}\n"
            f"{symbol}:\n"
            f"\t.space {size}\n"
        )

    assembler_input: str = "".join(preprocessed)
    # print(assembler_input)
    p = subprocess.run([assembler, *flags, "-"], stdout=subprocess.PIPE, input=assembler_input, encoding='ascii')
    sys.exit(p.returncode)
