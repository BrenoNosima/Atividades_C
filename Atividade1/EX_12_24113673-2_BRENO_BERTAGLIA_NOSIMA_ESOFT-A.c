#include <stdio.h>

int main() {
   float tb, tk, kr, vT;

  printf("Digite a taxa base do aluguel: ");
  scanf("%f", &tb);
  printf("Digite a taxa adicional por quilômetro rodado: ");
  scanf("%f", &tk);
  printf("Digite a quantidade de quilômetros rodados: ");
  scanf("%f", &kr);

  vT = tb + (tk * kr);

  printf("O valor total do aluguel é: R$ %.2f\n", vT);

  return 0;
}
