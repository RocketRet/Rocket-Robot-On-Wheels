CPPFLAGS := -I..
CFLAGS := -O3
CC := gcc

PROGRAMS := extract_texture archive

all: $(PROGRAMS)
clean:
	rm -f $(PROGRAMS)

extract_texture: extract_texture.c librocket.c librocket.h ../n64graphics.c ../n64graphics.h ../utils.c ../utils.h
archive: archive.cpp librocket.c librocket.h lib/fmtlib/src/format.cc bswap.h
archive: CC := g++-9
archive: CFLAGS += -std=c++2a
archive: CPPFLAGS += -Ilib/fmtlib/include

$(PROGRAMS): % :
	$(CC) $(CFLAGS) $(CPPFLAGS) $(filter %.c,$^) $(filter %.cc,$^) $(filter %.cpp,$^) -o $@

.PHONY: all clean
