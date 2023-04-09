manipula: manipula.c
	gcc manipula.c -o manipula -g -Wall -std=c99

carregaMapa: carregaMapa.c
	gcc carregaMapa.c -o carregaMapa -g -Wall -std=c99

crun: carregaMapa
	./carregaMapa

run: manipula 
	./manipula

clean:
	rm manipula carregaMapa

vrun: manipula
	valgrind --leak-check=full ./manipula
