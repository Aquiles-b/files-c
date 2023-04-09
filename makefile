manipula: manipula.c
	gcc manipula.c -o manipula -g -Wall -std=c99

cp: mycp.c
	gcc mycp.c -o cp -g -Wall -std=c99

carregaMapa: carregaMapa.c
	gcc carregaMapa.c -o carregaMapa -g -Wall -std=c99

crun: carregaMapa
	./carregaMapa

run: cp 
	./cp

clean:
	rm -f manipula carregaMapa cp

vrun: manipula
	valgrind --leak-check=full ./manipula
