#include <stdio.h>

int main() {
  float l1, l2, l3;
    
  printf("Informe o valor do lado 1: ");
  scanf("%f", &l1);
  printf("Informe o valor do lado 2: ");
  scanf("%f", &l2);
  printf("Informe o valor do lado 3: ");
  scanf("%f", &l3);

  if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1) {
      if (l1 == l2 && l2 == l3) {
          printf("O tri�ngulo eh equil�tero.\n");
      } else if (l1 == l2 || l1 == l3 || l2 == l3) {
          printf("O tri�ngulo eh is�sceles.\n");
      } else {
          printf("O tri�ngulo eh escaleno.\n");
      }
  } else {
      printf("As medidas nao formam um triangulo.\n");
  }

  return 0;
}
