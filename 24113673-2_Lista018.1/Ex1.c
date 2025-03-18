#include <stdio.h>

int main() {
    FILE *arquivo = fopen("meuarquivo.txt", "w"); 

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "Helo, Mundo!"); 
    fclose(arquivo);

    return 0;
}
