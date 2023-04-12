CFLAGS= -g -Wall -std=c99

PROGS= mb1 mb2 mb3

all: $(PROGS)

%.c: %.c
	gcc $@.c -o $@ $(CFLAGS)

clean: 
	rm -f mb? $(PROGS)
