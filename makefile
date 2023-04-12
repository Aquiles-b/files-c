CFLAGS= -g -Wall -std=c99

all: manipula carregaMapa mycp mygrep

%.c: %.c
	gcc $@ -o $@ $(CFLAGS)

clean:
	rm -f manipula carregaMapa mycp mygrep
