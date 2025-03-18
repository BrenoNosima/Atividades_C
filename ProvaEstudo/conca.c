#include <stdio.h>
#include <string.h>

int main() {
    char frase[200], caractere;
    int ocorrencias = 0;

    printf("Digite uma frase: ");
    gets(frase);

    printf("Digite o caractere que deseja buscar: ");
    scanf(" %c", &caractere);

    printf("Procurando '%c' em \"%s\"...\n", caractere, frase);

    printf("Posições: ");
    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] == caractere) {
            printf("%d ", i);
            ocorrencias++;
        }
    }

    printf("\nOcorrências: %d\n", ocorrencias);
    return 0;
}

