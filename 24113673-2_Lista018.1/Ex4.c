#include <stdio.h>

int main() {

    FILE *arquivo = fopen("numeros.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    for (int i = 1; i <= 10; i++) {
        fprintf(arquivo, "%d\n", i); 
    }
    fclose(arquivo); 

    arquivo = fopen("numeros.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numero, soma = 0;
    while (fscanf(arquivo, "%d", &numero) != EOF) { 
        soma += numero * 3; 
    }
    fclose(arquivo); 

    printf("A soma dos num de 1 ate 10, multiplicados por 3, eh: %d\n", soma);

    return 0;
}
