#include <stdio.h>

int main() {
  int p;
  char *n;

  printf("Informe a quantidade de pontos do funcionario: ");
  scanf("%d", &p);

  if (p >= 1000) {
      n = "A";
  } else if (p >= 750) {
      n = "B";
    } else if (p >= 500) {
      n = "C";
    } else if (p >= 250) {
      n = "D";
    } else {
      n = "Nenhuma premiação";
    }

  printf("A premiacao eh: %s\n", n);

  return 0;
}