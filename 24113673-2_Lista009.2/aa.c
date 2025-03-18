#include <stdio.h>
#include <ctype.h>
int main(){
  char nome[100];

  printf("informe um nome: ");
  scanf("%s", nome);

  for(int i = 0; i < strlen(nome); i++){
    printf("\n%c", toupper(nome[i]));
  }
  return 0;
}