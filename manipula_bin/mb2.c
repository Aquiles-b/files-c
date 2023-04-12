#include <stdio.h>
#include <stdlib.h>

/* Retorna o numero de elementos no arquivo.*/
int numElementosArq(FILE *arq)
{
    fseek(arq, 0, SEEK_END);
    int ultimo = ftell(arq);
    int elems = ultimo / sizeof(long);
    rewind(arq);

    return elems;
}

/* Retorna vetor contendo todos os elementos do arquivo.*/
long *leDados(FILE *arq, int elems)
{
    long *dados = malloc(sizeof(long)*elems);
    fread(dados, sizeof(long), elems, arq);

    return dados;
}

/* Troca os valores de dois enderecos.*/
void troca(long *a, long *b)
{
    long aux = *a;

    *a = *b;
    *b = aux;
}

int particiona(long vetor[], int a, int b, int x)
{
    int meio = a - 1;
    for (int i = a; i <= b; i++)
        if (vetor[i] <= x) {
            meio++;
            troca(&vetor[meio], &vetor[i]);
        }

    return meio;
}

void auxQuickSort(long vetor[], int a, int b)
{
    if (a >= b)
        return;
    int meio = particiona(vetor, a, b, vetor[b]);
    auxQuickSort(vetor, a, meio - 1);
    auxQuickSort(vetor, meio + 1, b);
}

void quickSort(long vetor[], int tam)
{
    auxQuickSort(vetor, 0, tam - 1);
}

int main()
{
    FILE *arq = fopen("longsAleatorios", "r");
    if (!arq) {
        perror("Erro ao ler o arquivo.");
        return 0;
    }

    int elems = numElementosArq(arq);
    long *dados = leDados(arq, elems);
    quickSort(dados, elems);
    freopen("longsAleatorios", "w", arq);
    int n = fwrite(dados, sizeof(long), elems, arq);
    printf ("%d\n", n);

    fclose(arq);
    free(dados);

    return 0;
}
