#include <stdio.h>
#include <string.h>

int main (){
  char u[10], s[10];

  printf("Digite o usuario: ");
  scanf("%s", u);
  printf("Digite a senha: ");
  scanf("%s", s);

  if ((strcmp(u, "Admin") == 0) && (strcmp(s, "Admin") == 0)) {
    printf("Acesso Concedido.");
  } else{
    printf("Acesso negado.");
  }
  return 0;
}