#!/bin/bash

SYM_ADDRS="tools/symbol_addrs.txt"

if [ "$#" -ne 4 ]; then
    echo "usage: $0 [source dir] [containing source file] [old function name] [new function name]"
    echo "e.g.: $0 codeseg1 initialize.c func_80007E80 osInitialize"
    exit 0
fi

SRC_BASE=$(echo "$2" | cut -f 1 -d '.')

grep -Fq $3 src/rocket/$1/$2
GREP_RET=$?
if [ $GREP_RET -eq 2 ]; then
    echo "Invalid parameters"
    exit 1
elif [ $GREP_RET -eq 1 ]; then
    echo "Function $3 not in file src/rocket/$1/$2"
    exit 1
fi

if [[ $3 =~ func_[0-9A-F]{8} ]]; then
    echo "Adding entry for function $4 to $SYM_ADDRS"
    echo "$4 = 0x${3:5:8}; // !" >> $SYM_ADDRS
fi

grep -rl "$3" tools/symbol_addrs.txt | xargs sed -i "s/$3/$4/g"
grep -rl "$3" src | xargs sed -i "s/$3/$4/g"
grep -rl "$3" asm | xargs sed -i "s/$3/$4/g"
grep -rl "$3" build/us/src | xargs sed -i "s/$3/$4/g"
grep -rl "$3" build/us/asm | xargs sed -i "s/$3/$4/g"

if [ -f "asm/nonmatchings/$1/$SRC_BASE/$3.s" ]; then
    echo "Renaming nonmatching func file: asm/nonmatchings/$1/$SRC_BASE/$3.s to asm/nonmatchings/$1/$SRC_BASE/$4.s"
    mv "asm/nonmatchings/$1/$SRC_BASE/$3.s" "asm/nonmatchings/$1/$SRC_BASE/$4.s"
fi



