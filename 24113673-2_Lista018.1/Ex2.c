#include <stdio.h>

int main() {
    FILE *arquivo = fopen("meuarquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char carac;
    while ((carac = fgetc(arquivo)) != EOF) { 
        putchar(carac);
    }

    fclose(arquivo); 
    return 0;
}
