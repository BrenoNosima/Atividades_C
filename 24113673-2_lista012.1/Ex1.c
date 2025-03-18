#include <stdio.h>
#include <string.h>

int main(){
  char nome[20];

  printf("Informe uma string: ");
  gets(nome);

  printf("%d", strlen(nome));

  return 0;
}