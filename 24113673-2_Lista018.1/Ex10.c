#include <stdio.h>

int main() {

    char caractere;


    FILE *arquivo_origem = fopen("meuarquivo.txt", "r");
    if (arquivo_origem == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; 
    }

    
    FILE *arquivo_destino = fopen("copia.txt", "w");
    if (arquivo_destino == NULL) {
        printf("Erro ao criar o arquivo 'copia.txt'.\n");
        fclose(arquivo_origem); 
        return 1; 
    }

 
    while ((caractere = fgetc(arquivo_origem)) != EOF) {
        fputc(caractere, arquivo_destino); 
    }

    printf("Copiado com sucesso para 'copia.txt'.\n");


    fclose(arquivo_origem);
    fclose(arquivo_destino);

    return 0;
}
