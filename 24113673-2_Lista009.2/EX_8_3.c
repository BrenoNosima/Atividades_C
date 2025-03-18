#include <stdio.h>

int main(){
  int num;
  float par = 0, impar = 0;

  for(int i = 0; i < 10; i++){
    printf("\nInforme um numero: ");
    scanf("%d", &num);

    if(num % 2 == 0){
      printf("Numero Par.");
      par += num;
    }else{
      printf("Numero Impar.");
      impar += num;
    }
  } 

  printf("\nA media dos numeros Pares eh: %.2f", par/10);
  printf("\nA media dos numeros Impares eh: %.2f", impar/10);

  return 0;
}