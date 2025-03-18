#include <stdio.h>

int main() {
    int m[4][3];
    int linha;


    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
          printf("Elemento [%d][%d]: ", i, j);
          scanf("%d", &m[i][j]);
      }
    }

      for (int i = 0; i < 4; i++) {
        linha = 0; 
          for (int j = 0; j < 3; j++) {
            linha += m[i][j]; 
          }
          printf("Soma da linha %d: %d\n", i, linha);
      }
  
    return 0;
}
