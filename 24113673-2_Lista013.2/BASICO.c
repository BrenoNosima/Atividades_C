#include <stdio.h>
//3 exr em 1
int main() {
    int vetor[10];
    int soma = 0;
    float media;
    int maior = 0, menor = 9999;

    for (int i = 0; i < 10; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    printf("\n");

    for (int i = 9; i >= 0; i--) {
        printf("Elemento %d: %d\n", i + 1, vetor[i]);
    }

    printf("\n");

    for (int i = 0; i < 10; i++){
      if (vetor[i] > maior){
        maior = vetor[i];
      } 
      if (vetor[i] < menor){
        menor = vetor [i];
      }
    }
    
    
    media = soma / 10.0;

    printf("Soma eh: %d\n", soma);
    printf("Menor numero eh %d\n", menor);
    printf("Maior numero eh %d\n", maior);
    printf("Media eh: %.2f\n", media);

    return 0;
}
