#include <stdio.h>

int main() {
    int m[4][4];
    int maiorValor;
    int linha = 0, coluna = 0;


    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
          printf("Elemento [%d][%d]: ", i, j);
          scanf("%d", &m[i][j]);

            if (i == 0 && j == 0) {
                maiorValor = m[i][j];
            }
            
            if (m[i][j] > maiorValor) {
                maiorValor = m[i][j];
                linha = i;
                coluna = j;
            }
      }
    }

    printf("\nMaior valor: %d\n", maiorValor);
    printf("Linha %d\nColuna %d\n", linha, coluna);

    return 0;
}
