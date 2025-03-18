#include <stdio.h>

  int main(){

  char nome[10][50];


  for(int i = 0; i < 10; i++){
    printf("Informe um nome: ");
    gets(nome[i]);
  }


  for(int i = 0; i < 10; i++){
    printf("%s ", nome[i]);
    printf("\n");
  }

  return 0;
}