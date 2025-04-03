#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int **mat, i, j;
  srand(time(NULL));

  // Aloca espaço para 3 ponteiros para linhas
  mat = malloc(3 * sizeof(int *));
    
  // Aloca espaço para 4 inteiros em cada linha
  for (i = 0; i < 3; i++) {
      mat[i] = malloc(4 * sizeof(int));
  }

  // Preenchendo a matriz com valores aleatórios de 0 a 99
  for (i = 0; i < 3; i++) {
      for (j = 0; j < 4; j++) {
          mat[i][j] = rand() % 100;
      }
  }


  // Exibindo a matriz
  printf("Matriz gerada:\n");
  for (i = 0; i < 3; i++) {
      for (j = 0; j < 4; j++) {
          printf("%2d ", mat[i][j]);
      }
      printf("\n");
  }

  // Liberando a memória alocada
  for (i = 0; i < 3; i++) {
      free(mat[i]);
  }
  free(mat);

  return 0;
}