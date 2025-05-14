#include <stdio.h>
#include <stdlib.h>

int main(){
  int **valores;
  int i, j;

  valores = malloc(5 * sizeof(int *));

  for (i = 0; i < 5; i++){
    valores[i] = malloc(4 * sizeof(int));
      for(j = 0; j < 4; j++){
        *(*(valores + i) + j) = rand() % 101 + 100;
      }
  }

  for (i = 0; i < 5; i++){
    for(j = 0; j < 4; j++){
      printf("%d ", *(*(valores + i) + j));
    }
    printf("\n");
  }

  for (i = 0; i < 5; i++) {
    free(valores[i]);
  }
  free(valores);
  return 0;
}