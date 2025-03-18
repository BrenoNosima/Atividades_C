#include <stdio.h>

int main(){

  int n;
  int maior = 0, menor = 9999;

    printf("Digite o tamanho do vet: ");
    scanf("%d", &n);

  int vetor[n];

  for (int i = 0; i < n; i++) {
        printf("Insira o %d num: ", i + 1);
        scanf("%d", &vetor[i]);
    }


  for (int i = 0; i < n; i++){
      if (vetor[i] > maior){
        maior = vetor[i];
      } 
      if (vetor[i] < menor){
        menor = vetor[i];
      }
    }
  
  
  printf("Maior num eh: %d\n",maior);
  printf("Menor num eh: %d\n",menor);
  
  return 0;
}