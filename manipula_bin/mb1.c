#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Retorna um numero aleatorio.*/
long longAleat()
{
    return (rand() * rand());
}

void escreveNumsAleat(FILE *arq)
{
    int n = rand() % 100 + 101;
    long *v = malloc(sizeof(long)*n);
    for (int i = 0; i < n; i++)
        v[i] = longAleat();
    fwrite(v, sizeof(long), n, arq);

    free(v);
}

int main()
{
    srand(time(NULL));

    FILE *arq = fopen("longsAleatorios", "w");
    if (!arq) {
        perror("Erro ao criar arquivo.");
        return 0;
    }

    escreveNumsAleat(arq);
    fclose(arq);

    return 0;
}
