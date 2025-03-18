#include <stdio.h>

int main(){
  
  int m[4][4];
  
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("Elemento [%d][%d]: ", i, j);
      scanf("%d", &m[i][j]);
    }
  }


  for (int i = 0; i < 4; i++) {
    printf("%d ", m[i][i]);
  }
    printf("\n");

  return 0;
}