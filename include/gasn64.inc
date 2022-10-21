# Assembly Macros

.macro glabel label
    .global \label
    \label:
.endm

.macro move a, b
    addu \a, \b, $0
.endm

.macro b target
    bgez $0, \target
.endm
