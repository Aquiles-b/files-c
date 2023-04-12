CFLAGS= -g -Wall -std=c99

FILES= manipula carregaMapa mycp mygrep le_poema

all: $(FILES)

%.c: %.c
	gcc $@ -o $@ $(CFLAGS)

clean:
	rm -f $(FILES)
