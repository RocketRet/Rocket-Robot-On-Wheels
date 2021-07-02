CPPFLAGS := -I..
CFLAGS := -O3
CC := gcc

PROGRAMS := extract_texture

all: $(PROGRAMS)
clean:
	rm -f $(PROGRAMS)

extract_texture: extract_texture.c librocket.c librocket.h ../n64graphics.c ../n64graphics.h ../utils.c ../utils.h

$(PROGRAMS): % :
	$(CC) $(CFLAGS) $(CPPFLAGS) $(filter %.c,$^) -o $@

.PHONY: all clean
