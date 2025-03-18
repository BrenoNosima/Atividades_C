#include <stdio.h>

int main() {

    char nome_arquivo[100];
    
        printf("Digite o nome do arquivo: ");
        scanf("%s", nome_arquivo);

        FILE *arquivo = fopen(nome_arquivo, "r"); 

        if (arquivo != NULL) {
            printf("O arquivo '%s' existe.\n", nome_arquivo);
            fclose(arquivo); 
        } else {
            printf("O arquivo '%s' nao existe.\n", nome_arquivo);
        }

    return 0;
}
