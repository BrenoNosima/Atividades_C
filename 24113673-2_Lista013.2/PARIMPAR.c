#include <stdio.h>

int main(){
  int num[10];
  int par = 0, impar = 0;

  for (int i = 0; i < 10; i++){
    printf("Digite o %d num: ", i + 1);
    scanf("%d", &num[i]);
    if (num[i] % 2 == 0){
      par ++;
    } else {
      impar ++;
    }
  }

  printf("Apareceu %d numeros pares.\n", par);
  printf("Apareceu %d numeros impares.\n", impar);
  return 0;
}