#include <stdio.h>

int main(){
  float n;

  printf("Informe o valor da compra: ");
  scanf("%f",&n);
     
     if ((n >= 100) && (n <= 500)) {
      printf("O valor total a pagar, com 10 porcento de desconto �: %.2f", n - (n * 0.1));
     } else if (n > 500) {
      printf("O valor total a pagar, com 20 porcento de desconto �: %.2f", n - (n * 0.2));
     } else {
      printf("O valor a pagar �: %.2f. N�o possui desconto. ", n);
     }
  
  return 0;
}