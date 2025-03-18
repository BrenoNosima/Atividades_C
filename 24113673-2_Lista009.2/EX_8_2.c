#include <stdio.h>

int main(){
  int num;
  float par = 0, impar = 0;
  int i = 0;

  do{
    printf("\nInforme um numero: ");
    scanf("%d", &num);

    if(num % 2 == 0){
      printf("Numero Par.");
      par += num;
    }else{
      printf("Numero Impar.");
      impar += num;
    }
    i++;
  }while(i < 10);

  printf("\nA media dos numeros Pares eh: %.2f", par/10);
  printf("\nA media dos numeros Impares eh: %.2f", impar/10);

  return 0;
}