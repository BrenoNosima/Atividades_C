#include <stdio.h>

int main(){

  int maior = 0, menor = 999;
  
  FILE *arquivo = fopen("numeros.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numero;
    while (fscanf(arquivo, "%d", &numero) != EOF) { 
     
        if (numero > maior) {
            maior = numero;
        }
        if (numero < menor) {
            menor = numero;
        }
    }
    fclose(arquivo); 

    printf("O maior número no arquivo é: %d\n", maior);
    printf("O menor número no arquivo é: %d\n", menor);


  return 0;
}