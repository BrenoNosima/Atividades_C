#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char **nomes, temp[100];
  int i;

  nomes = malloc(5 * sizeof(char *));

  for (i = 0; i < 5; i++){
    printf("Digite o nome %d: ", i + 1);
    gets(temp);
    nomes[i] = malloc((strlen(temp) + 1) * sizeof(char));
    strcpy(*(nomes + i), temp);
  }

  for (i = 0; i < 5; i++) {
    printf("%s\n", nomes[i]);
  }

  for (i = 0; i < 5; i++) {
    free(nomes[i]);
  }
  free(nomes);
  return 0;
}