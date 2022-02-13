# Config
VERSION ?= us
TARGET := NSUE

BASEROM := baserom.$(VERSION).z64
BUILD_ROOT := build
ROM_SIZE := 0xC00000

RFILTER_OUT = $(foreach v,$(2),$(if $(findstring $(1),$(v)),,$(v)))
BUILD_DIR := $(BUILD_ROOT)/$(VERSION)
SRC_DIR := src
ASM_DIR := asm
BIN_DIR := bin
LIBULTRA_DIRS := audio gu io n_audio os sched
ROCKET_SRC_DIRS   := $(shell find $(SRC_DIR)/ -type d)
LIBULTRA_SRC_DIRS := $(addprefix ultra/src/,$(LIBULTRA_DIRS))
SRC_DIRS := $(ROCKET_SRC_DIRS) $(LIBULTRA_SRC_DIRS)
ASM_DIRS := $(call RFILTER_OUT,nonmatching,$(shell find $(ASM_DIR)/ -type d))
SRC_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(SRC_DIRS)) # Don't search libultra dirs, but generate them for manual specifying of libultra asm files
ASM_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(ASM_DIRS) $(LIBULTRA_DIRS))
BIN_BUILD_DIR := $(BUILD_DIR)/$(BIN_DIR)
KMCGCCDIR := tools/kmc/gcc

# Files
FILTERED_OUT_SRCS := src/lib/codeseg1/player_commands.c src/lib/codeseg1/player_api.c src/lib/codeseg1/player_fifo.c
C_SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
C_SRCS := $(filter-out $(FILTERED_OUT_SRCS),$(C_SRCS))
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

LIBULTRA_SRCS := $(foreach dir,$(LIBULTRA_SRC_DIRS),$(wildcard $(dir)/*.c))
SN_SRCS := $(foreach dir,$(shell find $(SRC_DIR)/rocket/ -type d) $(shell find $(SRC_DIR)/lib/ -type d),$(wildcard $(dir)/*.c))
SN_SRCS := $(filter-out $(FILTERED_OUT_SRCS),$(SN_SRCS))
SN_LNKS := $(addprefix $(BUILD_DIR)/, $(SN_SRCS:.c=.obj))
SN_OBJS := $(SN_LNKS:.obj=.o)

# Tools
CPP := mips-linux-gnu-cpp
AS := mips-linux-gnu-as
OBJCOPY := mips-linux-gnu-objcopy
LD := mips-linux-gnu-ld
STRIP := mips-linux-gnu-strip
KMC_CC := tools/kmc/gcc

export N64ALIGN := ON
export VR4300MUL := ON

PROC_VERSION != uname -a
IS_WSL := $(findstring microsoft,$(PROC_VERSION)) $(findstring Microsoft,$(PROC_VERSION))

ifneq ($(IS_WSL),)
CC1N64 := ./sn/cc1n64.exe
ASN64 := ./sn/asn64.exe
else
CC1N64 := wine ./sn/cc1n64.exe
ASN64 := wine ./sn/asn64.exe
endif

# Flags
CPPFLAGS := -Iinclude -Iinclude/2.0I -Iinclude/2.0I/PR -Iultra/src/audio -Iultra/src/n_audio -Iinclude/mus -DF3DEX_GBI_2 -D_FINALROM -DTARGET_N64 -DSUPPORT_NAUDIO -DN_MICRO
CC1N64_CFLAGS := -quiet -G0 -mcpu=vr4300 -mips3 -mhard-float -meb
ASN64FLAGS := -q -G0
KMC_CFLAGS := -c -G0  -mgp32 -mfp32 -mips3
WARNFLAGS := -Wuninitialized -Wshadow -Wall
OPTFLAGS := -O2
ASFLAGS := -G0 -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I. -Iinclude -O1 --no-construct-floats
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
	$(CPP) $(CPPFLAGS) -D__FILE__=\"$(notdir $<)\" -Wno-builtin-macro-redefined $< -o $@

$(BUILD_DIR)/ultra/%.o : $(BUILD_DIR)/ultra/%.i | $(SRC_BUILD_DIRS)
	$(KMC_CC) $(KMC_CFLAGS) $(OPTFLAGS) $< -o $@
	$(STRIP) $@ -N $(<:.i=.c)

$(SN_LNKS) : $(BUILD_DIR)/%.obj : %.c | $(SRC_BUILD_DIRS)
	@printf "Compiling $<\r\n"
	@$(CPP) $(CPPFLAGS) $< -o $@.i
	@$(CC1N64) $(CC1N64_CFLAGS) $(OPTFLAGS) $@.i -o $@.s
	@$(ASN64) $(ASN64FLAGS) $@.s -o $@

$(SN_OBJS) : $(BUILD_DIR)/%.o : $(BUILD_DIR)/%.obj
	@printf "Running obj parser on $< $<\r\n"
	@tools/psyq-obj-parser $< -o $@ -b -n > /dev/null

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

clean:
	$(RMDIR) $(BUILD_ROOT)

check: $(Z64)
	@$(DIFF) $(BASEROM) $(Z64) && printf "OK\n"

setup:
	tools/splat/split.py tools/NSUE.00.yaml
	make -C tools/kmc
	git checkout -q $(ASM_DIR)

.SUFFIXES:
MAKEFLAGS += --no-builtin-rules

keep-asm: $(C_ASMS) $(C_ASMS:.s=.i)

.PHONY: all keep-asm clean check setup

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

