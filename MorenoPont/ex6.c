#include <stdio.h>
#include <string.h>

int main() {
  char palavras[4][11]; 

  for (int i = 0; i < 4; i++) {
    printf("Digite a %da palavra (máx. 10 caracteres): ", i + 1);
    scanf("%10s", palavras[i]);\
  }
  
  printf("\n(a) Tamanho total do vetor (em bytes): %d\n", sizeof(palavras));
  
  for (int i = 0; i < 4; i++) {
    printf("Palavra %d: %d caracteres\n", i + 1, strlen(palavras[i]));
  }

  printf("\n(c) Endereço de memória do vetor: %p\n", &palavras);

  for (int i = 0; i < 4; i++) {
    printf("Palavra %d: %p\n", i + 1, &(palavras[i]));
  }

  return 0;
}