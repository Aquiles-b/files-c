#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Retorna o numero de caracteres da maior linha de um arquivo.*/
int maior_linha(FILE* arq)
{
    int maior = 0, atual;
    char letra;
    while(!feof(arq)){
        atual = 0;
        letra = fgetc(arq);
        while(letra != '\n' && letra != EOF){
            atual++;
            letra = fgetc(arq);
        }
        if(atual > maior)
            maior = atual;
    }
    rewind(arq);

    return maior;
}

void mygrep(FILE* arq, char** argv)
{
    int maior = maior_linha(arq);
    char* linha = malloc(sizeof(char)*maior);

    fgets(linha, maior+1, arq);
    linha[strcspn(linha, "\n")] = '\0';
    while(!feof(arq)){
        if(strstr(linha, argv[2]) != NULL)
            printf ("%s\n", linha);

        fgets(linha, maior+1, arq);
        linha[strcspn(linha, "\n")] = '\0';
    }
    free(linha);
}

int main(int argc, char** argv)
{
    FILE* arq = fopen(argv[1], "r");
    if(!arq){
        printf ("Arquivo nao existe.\n");
        return 1;
    }

    mygrep(arq, argv);

    return 0;
}
