#include <stdio.h>


int main() {
    char nome_arquivo[100];
    
        printf("Digite o nome do arquivo: ");
        scanf("%s", nome_arquivo);

        FILE *arquivo = fopen(nome_arquivo, "r"); 

        if (arquivo == NULL) {
            printf("O arquivo '%s' nao existe.\n", nome_arquivo);
            return 1;
        } 

        char palavra[100];
        int contador = 0;
          while (fscanf(arquivo, "%s", palavra) != EOF){
            contador ++;
          }
         

        printf("O arquivo possui %d palavras.\n", contador);

    return 0;
}