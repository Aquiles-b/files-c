#include <stdio.h>
#include <stdlib.h>

/* Retorna o numero de elementos no arquivo.*/
int numElementosArq(FILE *arq)
{
    fseek(arq, 0, SEEK_END);
    long ultimo = ftell(arq);
    int elems = ultimo / sizeof(int);
    rewind(arq);

    return elems;
}

/* Retorna um vetor com o poema escrito.*/
char *lePoema(FILE *poema)
{
    int posi;
    char letra;
    int tam = numElementosArq(poema);
    char *poemaOrdenado = malloc(sizeof(char) * (tam + 1));
    for (int i = 0; i < tam; i++) {
        fread(&posi, sizeof(int), 1, poema);
        fread(&letra, sizeof(char), 1, poema);
        poemaOrdenado[posi] = letra;
    }

    poemaOrdenado[tam] = '\0';

    return poemaOrdenado;
}

int main()
{
    FILE *poema = fopen("arquivos/poema.bin", "r");
    if (!poema){
        perror("Nao foi possivel ler o arquivo.");
        return 1;
    }

    char *poemaStr = lePoema(poema);
    printf ("%s\n", poemaStr);

    return 0;
}
