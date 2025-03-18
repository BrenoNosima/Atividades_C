#include <stdio.h>
#include <string.h>

int main() {
    char nome[] = "Capeu";
    char nome2[] = "Amarelo";

    int resultado = strcmp(nome, nome2, 4);
    if (resultado == 0) {
        printf("Sao dos mesmo tamanho.\n");
    } else if (resultado > 0) {
        printf("%s Viria primeiro.\n", nome);
    } else {
        printf("%s Viria primeiro.\n", nome2);
    }

    return 0;
}