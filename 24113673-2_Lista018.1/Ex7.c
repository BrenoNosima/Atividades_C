#include <stdio.h>
#include <stdlib.h> 

int main() {
    char nome_arquivo[100];
    char caractere;
    int num, soma = 0, contador = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);
    FILE *arquivo = fopen(nome_arquivo, "r"); 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", nome_arquivo);
        return 1;
    }

    while (fscanf(arquivo, "%d%c", &num, &caractere) == 2) {
        soma += num; 
        contador++; 
        
        if (caractere != ',') {
            break; 
        }
    }

    if (contador > 0) {
        float med = (float) soma / contador; 
        printf("A med dos num eh: %.2f\n", med);
    } else {
        printf("Nenhum num valido encontrado no arquivo.\n");
    }

    fclose(arquivo); 

    return 0;
}
