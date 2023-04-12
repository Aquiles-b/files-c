#include <stdio.h>
#include <stdlib.h>

/* Retorna o numero de elementos no arquivo.*/
int numElementosArq(FILE *arq)
{
    fseek(arq, 0, SEEK_END);
    long ultimo = ftell(arq);
    int elems = ultimo / sizeof(long);
    rewind(arq);

    return elems;
}

 /* Imprime as 10 primeiras e ultimas linhas. */
void imprimeHeadTail(FILE *arq)
{
    long *dados = malloc(sizeof(long)*10);
    fread(dados, sizeof(long), 10, arq);
    for (int i = 0; i < 10; i++)
        printf ("%ld ", dados[i]);

    fseek(arq, -10, SEEK_END);

    fread(dados, sizeof(long), 10, arq);
    for (int i = 0; i < 10; i++)
        printf ("%ld ", dados[i]);
    printf ("\n");

    free(dados);
}

int main()
{
    FILE *arq = fopen("longsAleatorios", "w");
    if (!arq) {
        perror("Erro ao criar arquivo.");
        return 0;
    }

    imprimeHeadTail(arq);

    fclose(arq);

    return 0;
}
