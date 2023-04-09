manipula: manipula.c
	gcc manipula.c -o manipula -g -Wall -std=c99

mycp: mycp.c
	gcc mycp.c -o cp -g -Wall -std=c99

mygrep: mygrep.c
	gcc mygrep.c -o mygrep -g -Wall -std=c99

carregaMapa: carregaMapa.c
	gcc carregaMapa.c -o carregaMapa -g -Wall -std=c99

clean:
	rm -f manipula carregaMapa mycp mygrep
