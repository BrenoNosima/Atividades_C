#include <stdio.h>

int main(){
  
  FILE *arquivo = fopen("numeros.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numero, soma = 0;
    while (fscanf(arquivo, "%d", &numero) != EOF) { 
        soma += numero; 
    }
    fclose(arquivo); 

    printf("A soma dos num do arquivo 'numeros.txt' eh: %d\n", soma);


  return 0;
}