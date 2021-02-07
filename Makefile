# Config
VERSION ?= us
TARGET := NSUE

BASEROM := baserom.$(VERSION).z64
BUILD_ROOT := build
ROM_SIZE := 0xC00000


# Folders
BUILD_DIR := $(BUILD_ROOT)/$(VERSION)
SRC_DIR := src
ASM_DIR := asm
BIN_DIR := bin
SRC_DIRS := $(filter-out $(wildcard $(SRC_DIR)/*.*), $(wildcard src/*))
SRC_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(SRC_DIRS))
ASM_BUILD_DIR := $(BUILD_DIR)/$(ASM_DIR)
BIN_BUILD_DIR := $(BUILD_DIR)/$(BIN_DIR)

# Files
C_SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
C_ASMS := $(addprefix $(BUILD_DIR)/, $(C_SRCS:.c=.s))
C_OBJS := $(C_ASMS:.s=.o)
AS_SRCS := $(wildcard $(ASM_DIR)/*.s)
AS_OBJS := $(addprefix $(BUILD_DIR)/, $(AS_SRCS:.s=.o))
BINS := $(wildcard $(BIN_DIR)/*.bin)
BIN_OBJS := $(addprefix $(BUILD_DIR)/, $(BINS:.bin=.o))
OBJS := $(C_OBJS) $(AS_OBJS) $(BIN_OBJS)
LD_SCRIPT := NSUE.ld
Z64 := $(BUILD_DIR)/$(TARGET).z64
ELF := $(Z64:.z64=.elf)

# Tools
CPP := mips-linux-gnu-cpp
CC := tools/sn/gnu/cc1n64.exe # TODO figure out how to make this work outside WSL
AS := mips-linux-gnu-as
OBJCOPY := mips-linux-gnu-objcopy
LD := mips-linux-gnu-ld

# Flags
CPPFLAGS := -Iinclude -Iinclude/2.0I -DF3DEX_GBI_2 -D_FINALROM
CFLAGS := -quiet -G0 -mcpu=vr4300 -mips3 -mgp32 -mfp32
WARNFLAGS := -Wuninitialized -Wshadow
OPTFLAGS := -O2
ASFLAGS := -G0 -EB -mtune=vr4300 -march=vr4300 -mabi=o64 -I. -Iinclude -O1
BINOFLAGS := -I binary -O elf32-big
CPP_LDFLAGS := -P -Wno-trigraphs -DBUILD_DIR=$(BUILD_DIR)
LDFLAGS := -T $(BUILD_DIR)/$(LD_SCRIPT) -mips3 --accept-unknown-input-arch --no-check-sections -T tools/undefined_syms.txt -T tools/undefined_syms_auto.txt
Z64OFLAGS := -O binary --pad-to=$(ROM_SIZE) --gap-fill=0x00

MKDIR := mkdir -p
RMDIR := rm -rf
DIFF := diff

all: check

$(SRC_BUILD_DIRS) : | $(SRC_DIR)

$(SRC_DIR) : | $(BUILD_DIR)

$(BUILD_DIR) : | $(BUILD_ROOT)

$(BUILD_ROOT) $(BUILD_DIR) $(SRC_DIR) $(SRC_BUILD_DIRS) $(ASM_BUILD_DIR) $(BIN_BUILD_DIR) :
	$(MKDIR) $@

$(BUILD_DIR)/%.s : %.c | $(SRC_BUILD_DIRS)
	$(CPP) $(CPPFLAGS) $< -o - | $(CC) $(CFLAGS) $(WARNFLAGS) $(OPTFLAGS) - -o $@

$(BUILD_DIR)/%.o : $(BUILD_DIR)/%.s
	$(AS) $(ASFLAGS) $< -o $@
	
$(BUILD_DIR)/%.o : %.s | $(ASM_BUILD_DIR)
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD_DIR)/%.o : %.bin | $(BIN_BUILD_DIR)
	$(OBJCOPY) $(BINOFLAGS) $< $@

$(BUILD_DIR)/$(LD_SCRIPT) : $(LD_SCRIPT) | $(BUILD_DIR)
	$(CPP) $(CPP_LDFLAGS) $< -o $@

$(ELF) : $(OBJS) $(BUILD_DIR)/$(LD_SCRIPT)
	$(LD) $(LDFLAGS) -Map $(@:.elf=.map) -o $@

$(Z64) : $(ELF)
	$(OBJCOPY) $(Z64OFLAGS) $< $@

# $(BUILD_DIR)/src/codeseg1/codeseg1_35.s: OPTFLAGS := -O0
# $(BUILD_DIR)/src/codeseg1/codeseg1_35.s: WARNFLAGS := 
# $(BUILD_DIR)/src/codeseg0/codeseg0_0.s: CC := tools/sn/gnun64280/cc1n64.exe
# $(BUILD_DIR)/src/codeseg0/codeseg0_0.s: CC := /mnt/c/n64/n64sdk/ultra/GCC/MIPSE/BIN/CC1.EXE
# $(BUILD_DIR)/src/codeseg0/codeseg0_0.o: AS := ../papermario/tools/linux/mips-nintendo-nu64-as
# $(BUILD_DIR)/src/codeseg0/codeseg0_0.o: ASFLAGS := -G0 -EB -I. -Iinclude -O0 -mcpu=vr4300 -g
# $(BUILD_DIR)/src/codeseg0/codeseg0_0.o: AS := /mnt/c/sn_n64/bin/asn64.exe
# $(BUILD_DIR)/src/codeseg0/codeseg0_0.o: ASFLAGS := /l
# $(BUILD_DIR)/src/codeseg0/codeseg0.s: OPTFLAGS := -O0
# $(BUILD_DIR)/src/codeseg0/codeseg0.s: CC := ../papermario/tools/linux/cc1
# $(BUILD_DIR)/src/codeseg2/codeseg2_144.s: CC := tools/gcc/mips-cc1
# $(BUILD_DIR)/src/codeseg2/codeseg2_148.s: CC := tools/gcc/mips-cc1 -fkeep-static-consts -msplit-addresses
# $(BUILD_DIR)/src/codeseg1/codeseg1_117.s: CC := tools/gcc/mips-cc1
# $(BUILD_DIR)/src/codeseg1/codeseg1_117.s: CC := ../papermario/tools/linux/cc1
# $(BUILD_DIR)/src/codeseg1/codeseg1_117.s: CC := tools/sn/gnun64280/cc1n64.exe
# $(BUILD_DIR)/src/codeseg1/codeseg1_117.s: OPTFLAGS := -O2
# $(BUILD_DIR)/src/codeseg1/codeseg1_117.o: ASFLAGS := -G0 -EB -mtune=vr4300 -march=vr4300 -mabi=o64 -I. -Iinclude -O0

clean:
	$(RMDIR) $(BUILD_ROOT)

check: $(Z64)
	@$(DIFF) $(BASEROM) $(Z64) && printf "OK\n"

setup:
	tools/splat/split.py baserom.$(VERSION).z64 tools/NSUE.00.yaml .

# tools/splat/split.py baserom.us.z64 tools/NSUE.00.yaml .

.SUFFIXES:
MAKEFLAGS += --no-builtin-rules

keep-asm: $(C_ASMS)

.PHONY: all keep-asm clean check setup

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

