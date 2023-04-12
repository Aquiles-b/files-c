#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Retorna um numero aleatorio.*/
long longAleat()
{
    return ((rand() << 4) + rand());
}

int escreveNumsAleat(FILE *arq)
{
    int n = rand() % 100 + 101;
    long *v = malloc(sizeof(long) * n);
    for (int i = 0; i < n; i++)
        v[i] = longAleat();
    int escrito = fwrite(v, sizeof(long), n, arq);

    free(v);

    return escrito;
}

int main()
{
    srand(time(NULL));

    FILE *arq = fopen("longsAleatorios", "w");
    if (!arq) {
        perror("Erro ao criar arquivo.");
        return 0;
    }

    int n = escreveNumsAleat(arq);
    printf ("%d\n", n);
    fclose(arq);

    return 0;
}
