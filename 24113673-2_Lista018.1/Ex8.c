#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAM 100


int main() {
    char nome_arquivo[100];
    char pProcurada[MAX_TAM];
    char palavra[MAX_TAM];
    int contador = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);
    
    printf("Digite a palavra a ser contada: ");
    scanf("%s", pProcurada);


    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", nome_arquivo);
        return 1; 
    }

    while (fscanf(arquivo, "%s", palavra) != EOF) {
        if (strcmp(palavra, pProcurada) == 0) {
            contador++; 
        }
    }


    printf("A palavra '%s' apareceu %d vezes.\n", pProcurada, contador);

    fclose(arquivo);

    return 0;
}
