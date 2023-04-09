#include <stdio.h>
#include <stdlib.h>
#define TAM 128

int prepara_arquivos(FILE** arq1, FILE** arq2, int argc, char** argv)
{
    if (argc != 3){
        printf ("Erro.\nUso correto: %s <fonte> <destino>\n", argv[0]);
        return 1;
    }

    *arq1 = fopen(argv[1], "r+");
    if(!arq1){
        printf ("Arquivo %s nao existe.\n", argv[1]);
        return 1;
    }

    *arq2 = fopen(argv[2], "r");
    if(*arq2){
        printf ("Arquivo %s ja existe.\n", argv[2]);
        return 1;
    }
    *arq2 = fopen(argv[2], "w");

    return 0;
}

/*Devolve o numero de caracteres da maior linha.*/
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

    return maior;
}

/*Faz copia de um arquivo.*/
void faz_copia(FILE* arq1, FILE* arq2)
{
    char letra = fgetc(arq1);
    while (!feof(arq1)){
        fputc(letra, arq2);
        letra = fgetc(arq1);
    }
}

int main(int argc, char *argv[])
{
    FILE* arq1, *arq2;
    if(prepara_arquivos(&arq1, &arq2, argc, argv))
        return 1;

    faz_copia(arq1, arq2);

    fclose(arq1);
    fclose(arq2);

    return 0;
}
