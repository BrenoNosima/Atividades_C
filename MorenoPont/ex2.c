#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main(){
  char ***mat; 
  int i, j, x = 0;

  char nomes[12][20] = {"Ana", "Beto", "Carlos", "Diana", 
                        "Eduardo", "Fernanda", "Gustavo", "Helena", 
                        "Igor", "Juliana", "Karla", "Lucas"};

  mat = malloc(3 * sizeof(char**));
    
  // Aloca espaço para 4 inteiros em cada linha
  for (i = 0; i < 3; i++) {
      mat[i] = malloc(4 * sizeof(char*));
      for (j = 0; j < 4; j++) {
          mat[i][j] = malloc(strlen(nomes[x]) + 1);
          strcpy(mat[i][j], nomes[x++]);
      }
  }

  // Exibindo a matriz
  printf("Matriz gerada:\n");
  for (i = 0; i < 3; i++) {
      for (j = 0; j < 4; j++) {
          printf("%s ", mat[i][j]);
      }
      printf("\n");
  }

  // Liberando a memória alocada
  for (i = 0; i < 3; i++) {
      for (j = 0; j < 4; j++) {
          free(mat[i][j]);
      }
      free(mat[i]);
  }
  free(mat);

  return 0;
}