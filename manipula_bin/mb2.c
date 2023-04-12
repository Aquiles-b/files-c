#include <stdio.h>
#include <stdlib.h>

/* Retorna o numero de elementos no arquivo.*/
int numElementosArq(FILE *arq)
{
    fseek(arq, 0, SEEK_END);
    long ultimo = ftell(arq);
    int elems = ultimo / sizeof(long);

    return elems;
}

/* Retorna vetor contendo todos os elementos do arquivo.*/
long *leDados(FILE *arq, int elems)
{
    long *dados = malloc(sizeof(long)*elems);
    fread(dados, sizeof(long), elems, arq);

    return dados;
}

int main()
{
    FILE *arq = fopen("longsAleatorios", "r+");
    if (!arq) {
        perror("Erro ao ler o arquivo.");
        return 0;
    }

    int elems = numElementosArq(arq);
    long *dados = leDados(arq, elems);

    free(dados);

    return 0;
}
