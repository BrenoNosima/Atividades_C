#include <stdio.h>
#include <string.h>

int main() {
    char nome[20];
    char nome2[20];

    printf("Informe uma string: ");
    scanf("%s", nome);
    printf("Informe outra string: ");
    scanf("%s", nome2);

    int resultado = strcmp(nome, nome2);
    if (resultado == 0) {
        printf("Eh iguais.\n");
    } else if (resultado > 0) {
        printf("%s eh maior.\n", nome);
    } else {
        printf("%s eh maior.\n", nome2);
    }

    return 0;
}
