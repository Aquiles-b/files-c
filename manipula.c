#include <stdio.h>

void conta_caracteres(FILE* arq)
{
    int i = 0;
    while(getc(arq) != EOF){
        i++;
    }
    printf ("%d\n", i-1);
}

int main(){
    FILE* texto = fopen("teste.txt", "r+");
    conta_caracteres(texto);
    fclose(texto);

    return 0;
}
