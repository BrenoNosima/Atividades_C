#include <stdio.h>
#include <stdlib.h>

int main(){
  int *valores, *nValores;
  int i = 0;

  valores = malloc(10 * sizeof(int));

  for (i = 0; i < 10; i++){
    valores[i] = rand() % 21 + 10;
  }

  int *endereco_original = valores;

  nValores = realloc(valores, 20 * sizeof(int));

  if (nValores == endereco_original){
    printf("O endere�o do vetor NAO mudou apos o realloc.\n");
  }
  else{
    printf("O endere�o do vetor MUDOU apos o realloc.\n");
  }
  free(valores);

  return 0;
}
