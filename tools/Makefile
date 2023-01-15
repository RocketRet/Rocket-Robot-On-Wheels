HOST_ENV := $(shell uname 2>/dev/null || echo Unknown)
HOST_ENV := $(patsubst MINGW%,MinGW,$(HOST_ENV))

GCC_272_DIR := gcc-2.7.2
GCC_272     := $(GCC_272_DIR)/gcc
GCC_272_AS  := $(GCC_272_DIR)/as

SN_GCC_DIR := modern-sn64
SN_GCC     := $(SN_GCC_DIR)/gcc
SN_ASN64   := $(SN_GCC_DIR)/modern-asn64.py

CC           := gcc
CXX          := g++
CFLAGS       := -I . -Wall -Wextra -Wno-unused-parameter -O2 -s
LDFLAGS      := -lm
ALL_PROGRAMS := iplfontutil armips $(GCC_272) $(GCC_272_AS) $(SN_GCC) $(SN_ASN64)

# Only build armips from tools if it is not found on the system
ifeq ($(shell which armips 2>/dev/null),)
  BUILD_PROGRAMS := $(ALL_PROGRAMS)
else
  BUILD_PROGRAMS := $(filter-out armips,$(ALL_PROGRAMS))
endif

COMPILE_PROGRAMS := $(filter-out $(GCC_272) $(GCC_272_AS) $(SN_GCC) $(SN_ASN64),$(BUILD_PROGRAMS))

default: all

iplfontutil_SOURCES := iplfontutil.c
iplfontutil_CFLAGS := -O2 # faster compile time

armips: CC := $(CXX)
armips_SOURCES := armips.cpp
armips_CFLAGS  := -std=c++11 -fno-exceptions -fno-rtti -pipe -Wno-maybe-uninitialized
armips_LDFLAGS := -pthread
ifeq ($(HOST_ENV),MinGW)
  armips_LDFLAGS += -municode
endif

$(GCC_272): | $(GCC_272_DIR)
	wget https://github.com/decompals/mips-gcc-2.7.2/releases/download/main/gcc-2.7.2-linux.tar.gz
	tar xf gcc-2.7.2-linux.tar.gz -C $(GCC_272_DIR)
	$(RM) gcc-2.7.2-linux.tar.gz

$(GCC_272_AS): | $(GCC_272_DIR)
	wget https://github.com/decompals/mips-binutils-2.6/releases/download/main/binutils-2.6-linux.tar.gz
	tar xf binutils-2.6-linux.tar.gz -C $(GCC_272_DIR)
	$(RM) binutils-2.6-linux.tar.gz

$(SN_GCC): | $(SN_GCC_DIR)
	wget https://github.com/decompals/SN64-gcc/releases/download/gcc-2.7.2-970404/SN64-gcc-2.7.2-970404-linux.tar.gz
	tar xf SN64-gcc-2.7.2-970404-linux.tar.gz -C $(SN_GCC_DIR)
	$(RM) SN64-gcc-2.7.2-970404-linux.tar.gz

$(SN_ASN64): | $(SN_GCC_DIR)
	wget https://github.com/RocketRet/modern-asn64/releases/download/main-release/modern-asn64.py -P $(SN_GCC_DIR)
	printf "#!/bin/bash\n\n$$" > $(SN_GCC_DIR)/as
	printf "( dirname -- \"$$" >> $(SN_GCC_DIR)/as
	printf "0\"; )/modern-asn64.py mips-linux-gnu-as \"$$" >> $(SN_GCC_DIR)/as
	printf "@\"" >> $(SN_GCC_DIR)/as
	chmod +x $(SN_GCC_DIR)/as
	chmod +x $(SN_GCC_DIR)/modern-asn64.py

$(GCC_272_DIR) $(SN_GCC_DIR):
	mkdir -p $@

all: $(BUILD_PROGRAMS)

clean:
	$(RM) $(ALL_PROGRAMS)

define COMPILE
$(1): $($1_SOURCES)
	$$(CC) $(CFLAGS) $($1_CFLAGS) $$^ -o $$@ $($1_LDFLAGS) $(LDFLAGS)
endef

$(foreach p,$(COMPILE_PROGRAMS),$(eval $(call COMPILE,$(p))))

.PHONY: all clean default
