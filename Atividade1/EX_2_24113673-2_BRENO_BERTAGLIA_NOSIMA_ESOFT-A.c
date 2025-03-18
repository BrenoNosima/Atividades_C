#include <stdio.h>

int main(){
  int valor, n100, n50, n20, n10, n5;

    printf("Informe um valor: ");
    scanf("%d", &valor);
      
      n100 = 0;
      n50 = 0;
      n20 = 0;
      n10 = 0;
      n5 = 0;

      while (valor >= 100){
        n100 ++;
        valor -= 100;
      }
      while (valor >= 50){
        n50 ++;
        valor -= 50;
      }
      while (valor >= 20){
        n20 ++;
        valor -= 20;
      }
      while (valor >= 10){
        n10 ++;
        valor -= 10;
      }
      while (valor >= 5){
        n5 ++;
        valor -= 5;
      }
     printf("Notas de 100: %d\n Notas de 50: %d\n Notas de 20: %d\n Notas de 10: %d\n Notas de 5: %d\n", n100, n50, n20, n10, n5);

  return 0;
}