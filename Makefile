# Config
VERSION ?= us
TARGET := NSUE

BASEROM := baserom.$(VERSION).z64
BUILD_ROOT := build
ROM_SIZE := 0xC00000

# TODO add check for extraction being complete

RFILTER_OUT = $(foreach v,$(2),$(if $(findstring $(1),$(v)),,$(v)))
# $(call RFILTER_OUT,g, seven eight nine ten)
# Folders
BUILD_DIR := $(BUILD_ROOT)/$(VERSION)
SRC_DIR := src
ASM_DIR := asm
BIN_DIR := bin
LIBULTRA_DIRS := audio gu io n_audio os sched
SRC_DIRS := $(shell find $(SRC_DIR)/ -type d) $(addprefix ultra/src/,$(LIBULTRA_DIRS))
ASM_DIRS := $(call RFILTER_OUT,nonmatching,$(shell find $(ASM_DIR)/ -type d))
SRC_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(SRC_DIRS)) # Don't search libultra dirs, but generate them for manual specifying of libultra asm files
ASM_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(ASM_DIRS) $(LIBULTRA_DIRS))
BIN_BUILD_DIR := $(BUILD_DIR)/$(BIN_DIR)
KMCGCCDIR := tools/kmc/gcc

# Files
C_SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
C_ASMS := $(addprefix $(BUILD_DIR)/, $(C_SRCS:.c=.s))
C_OBJS := $(C_ASMS:.s=.o)
LIBULTRA_ASMS := gu/libm_vals.s
AS_SRCS := $(wildcard $(ASM_DIR)/*.s) $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s)) $(addprefix ultra/src/,$(LIBULTRA_ASMS))
AS_OBJS := $(addprefix $(BUILD_DIR)/, $(AS_SRCS:.s=.o))
BINS := $(wildcard $(BIN_DIR)/*.bin)
BIN_OBJS := $(addprefix $(BUILD_DIR)/, $(BINS:.bin=.o))
OBJS := $(C_OBJS) $(AS_OBJS) $(BIN_OBJS)
LD_SCRIPT := NSUE.ld
Z64 := $(BUILD_DIR)/$(TARGET).z64
ELF := $(Z64:.z64=.elf)

# Tools
CPP := mips-linux-gnu-cpp
CC := tools/sn/gcc-2.8.0-rocket/cc1
AS := mips-linux-gnu-as
OBJCOPY := mips-linux-gnu-objcopy
LD := mips-n64-ld
WINE := wine
EXEW32 := exew32.exe
KMCGCCBINDIR := $(KMCGCCDIR)/mipse/bin
KMC_CC := $(WINE) $(EXEW32) gcc

export gccdir = $(KMCGCCDIR)
export WINEPATH := $(KMCGCCBINDIR)

# Flags
CPPFLAGS := -Iinclude -Iinclude/2.0I -Iinclude/2.0I/PR -Iultra/src/audio -Iultra/src/n_audio -DF3DEX_GBI_2 -D_FINALROM -DTARGET_N64 -DSUPPORT_NAUDIO -DN_MICRO
CFLAGS := -quiet -G0 -mcpu=vr4300 -mips3 -mgp32 -mfp32 -msplit-addresses -mgas -mrnames
KMC_CFLAGS := -c -G0 -mgp32 -mfp32 -mips3
WARNFLAGS := -Wuninitialized -Wshadow -Wall
OPTFLAGS := -O2
ASFLAGS := -G0 -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I. -Iinclude -O1
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

$(BUILD_ROOT) $(BUILD_DIR) $(SRC_DIR) $(SRC_BUILD_DIRS) $(ASM_BUILD_DIRS) $(BIN_BUILD_DIR) :
	$(MKDIR) $@

$(BUILD_DIR)/ultra/%.i : ultra/%.c | $(SRC_BUILD_DIRS)
	$(CPP) $(CPPFLAGS) $< -o $@

$(BUILD_DIR)/ultra/%.o : $(BUILD_DIR)/ultra/%.i | $(SRC_BUILD_DIRS)
	$(KMC_CC) $(KMC_CFLAGS) $(OPTFLAGS) $< -o $@

$(BUILD_DIR)/$(SRC_DIR)/rocket/%.i : $(SRC_DIR)/rocket/%.c | $(SRC_BUILD_DIRS)
	$(CPP) $(CPPFLAGS) $< -o $@

$(BUILD_DIR)/$(SRC_DIR)/rocket/%.s : $(BUILD_DIR)/$(SRC_DIR)/rocket/%.i $(SRC_DIR)/rocket/%.c
	$(CC) $(CFLAGS) $(WARNFLAGS) $(OPTFLAGS) $< -o $@ || rm -f $@

$(BUILD_DIR)/$(SRC_DIR)/lib/codeseg1/%.i : $(SRC_DIR)/lib/codeseg1/%.c | $(SRC_BUILD_DIRS)
	$(CPP) $(CPPFLAGS) $< -o $@
	
$(BUILD_DIR)/$(SRC_DIR)/lib/codeseg1/%.s : $(BUILD_DIR)/$(SRC_DIR)/lib/codeseg1/%.i $(SRC_DIR)/lib/codeseg1/%.c
	$(CC) $(CFLAGS) $(WARNFLAGS) $(OPTFLAGS) $< -o $@ || rm -f $@

$(BUILD_DIR)/%.o : $(BUILD_DIR)/%.s
	$(AS) $(ASFLAGS) $< -o $@
	
$(BUILD_DIR)/%.o : %.s | $(ASM_BUILD_DIRS) $(SRC_BUILD_DIRS)
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD_DIR)/%.o : %.bin | $(BIN_BUILD_DIR)
	$(OBJCOPY) $(BINOFLAGS) $< $@

$(BUILD_DIR)/$(LD_SCRIPT) : $(LD_SCRIPT) | $(BUILD_DIR)
	$(CPP) $(CPP_LDFLAGS) $< -o $@

$(ELF) : $(OBJS) $(BUILD_DIR)/$(LD_SCRIPT)
	$(LD) $(LDFLAGS) -Map $(@:.elf=.map) -o $@

$(Z64) : $(ELF)
	$(OBJCOPY) $(Z64OFLAGS) $< $@
	
$(BUILD_DIR)/ultra/%.o: OPTFLAGS := -O3

# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_144.s: CC := tools/gcc/mips-cc1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_148.s: CC := tools/gcc/mips-cc1 -fkeep-static-consts -msplit-addresses
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_221.s: CC := tools/gcc/mips-cc1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_225.s: CC := tools/gcc/mips-cc1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_225.s: CC := tools/gcc-2.7.2/cc1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_237.s: CC := tools/sn/gcc-2.7.2/cc1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_237.s: CFLAGS := -quiet -G0 -mips3 -mgp32 -mfp32 -mgas
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_208.s: CC := tools/sn/gcc-2.7.2/cc1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_208.s: CFLAGS := -quiet -G0 -mips3 -mgp32 -mfp32 -mgas
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_103.s: CC := tools/sn/gcc-2.7.2/cc1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_103.s: CFLAGS := -quiet -G0 -mips3 -mgp32 -mfp32 -mgas
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_434.s: CC := tools/sn/gcc-2.7.2/cc1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_434.s: CFLAGS := -quiet -G0 -mips3 -mgp32 -mfp32 -mgas
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_434.s: ASFLAGS := -G0 -EB -mabi=32 -I. -Iinclude -O1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_235.s: CC := tools/sn/gcc-2.7.2/cc1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_378.s: OPTFLAGS := -O2 -g
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_3.s: CC := tools/sn/gcc-2.7.2/cc1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_378.s: CC := tools/sn/gcc-2.7.2/cc1
# $(BUILD_DIR)/src/rocket/codeseg2/codeseg2_225.s: OPTFLAGS := -O3 -g0

clean:
	$(RMDIR) $(BUILD_ROOT)

check: $(Z64)
	@$(DIFF) $(BASEROM) $(Z64) && printf "OK\n"

setup:
	tools/splat/split.py --rom baserom.$(VERSION).z64 tools/NSUE.00.yaml --outdir .

# tools/splat/split.py baserom.us.z64 tools/NSUE.00.yaml .

.SUFFIXES:
MAKEFLAGS += --no-builtin-rules

keep-asm: $(C_ASMS) $(C_ASMS:.s=.i)

.PHONY: all keep-asm clean check setup

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

