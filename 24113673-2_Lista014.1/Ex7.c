#include <stdio.h>

int main() {
    int m[3][3];


    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        printf("Elemento [%d][%d]: ", i, j);
        scanf("%d", &m[i][j]);
      }
    }


    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        printf("%d ", m[j][i]);
      }
        printf("\n");
    }

 

    return 0;
}
