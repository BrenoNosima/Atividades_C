#include <stdio.h>

int main(){

    int cod;

    printf("Digite um codigo (8 caracteres e ser divisivel por 6)");
    scanf("%d", &cod);

    if (cod % 6 == 0){
        printf("COD VALIDO");
    }else{
        printf("COD INVALIDO");
    }

    return 0;
}