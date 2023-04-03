manipula: manipula.c
	gcc manipula.c -o manipula -g -Wall -std=c99

run: manipula 
	./manipula

vrun: manipula
	valgrind --leak-check=full ./manipula
