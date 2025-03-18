#include <stdio.h>

int main() {
  int qntd;
  float media = 0, altura;
    printf("Informe a quantidade de alunos: ");
    scanf("%d", &qntd);

      for (int i = 1; i <= qntd; i++) {
        printf("Informe a altura: ");
        scanf("%f", &altura);
        media += altura;
      }
    printf("Media de altura eh: %.2f", media/qntd);
    return 0;
}
