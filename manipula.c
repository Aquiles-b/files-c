#include <stdio.h>
#include <stdlib.h>
#define TAM 128

/*Conta todos os caracteres de um arquivo.*/
void conta_caracteres(FILE* arq)
{
    int i = 0;
    while(getc(arq) != EOF){
        i++;
    }
    printf ("%d\n", i-1);
}

/*Le os numeros em cada linha do arquivo e imprime a media deles.*/
void imprime_media(FILE* arq)
{
    float valor, valor_final = 0;
    int tam = 0;

    fscanf(arq, "%f", &valor);
    while(!feof(arq)){
        valor_final += valor;
        fscanf(arq, "%f", &valor);
        tam++;
    }
    printf ("%f\n", valor_final/tam);
}

/*Transforma letras minusculas de uma string em maiusculas.*/
void aumenta_caixa_str(char* str)
{
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        
        i++;
    }
}

/* Transforma todas as letras minusculas de um arquivo para maiusculas. */
void aumenta_caixa_arq(FILE* arq)
{
    FILE* maiusc = fopen("maiusc.txt", "w");
    char* linha = malloc(sizeof(char)*TAM);

    fgets(linha, TAM, arq);
    while(!feof(arq)){
        aumenta_caixa_str(linha);
        fputs(linha, maiusc);
        fgets(linha, TAM, arq);
    }

    free(linha);
}

int main(){
    FILE* texto = fopen("minusc.txt", "r+");
    aumenta_caixa_arq(texto);
    fclose(texto);

    return 0;
}
