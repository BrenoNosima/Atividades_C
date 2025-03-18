#include <stdio.h>
#include <string.h>

int main(){
  char nome[20];

  printf("Informe uma string: ");
  gets(nome);

  for(int i = 0; i < strlen(nome); i++){
    if (nome[i] != ' '){
      printf("%c", nome[i]);
    }
  }

  return 0;
}