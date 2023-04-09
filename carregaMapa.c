#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** cria_matriz(FILE* mapa, int* tam)
{
    int colunas, i = 0;
    char** matriz;
    fscanf(mapa, "%d %d", tam, &colunas);
    colunas++;

    matriz = malloc(sizeof(char*)*(*tam));
    while (i < (*tam)){
        matriz[i] = malloc(sizeof(char)*colunas+1);
        i++;
    }
    i = 0;

    fgets(matriz[i], colunas, mapa);
    while(i < (*tam)){
        fgets(matriz[i], colunas+1, mapa);
        matriz[i][strcspn(matriz[i], "\n")] = '\0';
        i++;
    }

    return matriz;
}

void imprime_matriz(char** matriz, int tam)
{
    for (int i = 0; i < tam; i++)
        printf ("%s\n", matriz[i]);
}

char** destroi_matriz(char** matriz, int tam)
{
    for (int i = 0; i < tam; i++){
        free(matriz[i]);
    }

    return NULL;
}

int main(){
    FILE* mapa = fopen("map.txt", "r");
    int tam;

    char** matriz = cria_matriz(mapa, &tam);
    imprime_matriz(matriz, tam);
    matriz = destroi_matriz(matriz, tam);

    return 0;
}
