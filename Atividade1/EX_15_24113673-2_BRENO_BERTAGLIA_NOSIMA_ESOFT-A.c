#include <stdio.h>
#include <string.h>

 int main () {

    char s[100];
    char s2[100];

    printf("Digite uma senha que tem que ter no minimo 8 caracteres, conter uma maiuscula, uma minuscula, um numero e um caractere especial.:\n");
    scanf("%s", s);

    printf("Digite sua senha novamente:");
    scanf("%s", s2);

    if (strcmp(s, s2) == 0) {
        printf("Acesso concedido");
    }else{
        printf("Acesso negado");
    }


    return 0;
}