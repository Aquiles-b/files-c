#include <stdio.h>

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

int main(){
    FILE* texto = fopen("teste.txt", "r+");
    imprime_media(texto);
    fclose(texto);

    return 0;
}
