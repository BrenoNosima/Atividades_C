#include <stdio.h>

int main() {
   float tb, tk, kr, vT;

  printf("Digite a taxa base do aluguel: ");
  scanf("%f", &tb);
  printf("Digite a taxa adicional por quil�metro rodado: ");
  scanf("%f", &tk);
  printf("Digite a quantidade de quil�metros rodados: ");
  scanf("%f", &kr);

  vT = tb + (tk * kr);

  printf("O valor total do aluguel �: R$ %.2f\n", vT);

  return 0;
}
