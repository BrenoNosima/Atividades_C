#include <stdio.h>
#include <string.h>

int main() {
    char nome[20];
    char nome2[20];

    printf("Informe o priemiro nome: ");
    scanf("%s", nome);
    printf("Informe segundo nome: ");
    scanf("%s", nome2);

    int resultado = strcmp(nome, nome2);
    if (resultado == 0) {
        printf("Sao dos mesmo tamanho.\n");
    } else if (resultado > 0) {
        printf("%s Viria primeiro.\n", nome);
    } else {
        printf("%s Viria primeiro.\n", nome2);
    }

    return 0;
}