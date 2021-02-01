HOST_ENV := $(shell uname 2>/dev/null || echo Unknown)
HOST_ENV := $(patsubst MINGW%,MinGW,$(HOST_ENV))

CC           := gcc
CXX          := g++
CFLAGS       := -I . -Wall -Wextra -Wno-unused-parameter -O2 -s
LDFLAGS      := -lm
ALL_PROGRAMS := iplfontutil armips

# Only build armips from tools if it is not found on the system
ifeq ($(shell which armips 2>/dev/null),)
  BUILD_PROGRAMS := $(ALL_PROGRAMS)
else
  BUILD_PROGRAMS := $(filter-out armips,$(ALL_PROGRAMS))
endif

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

all: $(BUILD_PROGRAMS)

clean:
	$(RM) $(ALL_PROGRAMS)

define COMPILE
$(1): $($1_SOURCES)
	$$(CC) $(CFLAGS) $($1_CFLAGS) $$^ -o $$@ $($1_LDFLAGS) $(LDFLAGS)
endef

$(foreach p,$(BUILD_PROGRAMS),$(eval $(call COMPILE,$(p))))

.PHONY: all clean default
