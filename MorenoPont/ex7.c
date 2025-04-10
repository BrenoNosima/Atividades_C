#include <stdio.h>
#include <string.h>

void inverte(char str[]){
  int i, j;
  char temp;
  int tam = strlen(str);

  for (i = 0, j = tam - 1; i < j; i++, j--)
  {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

int main()
{
  char texto[100];

  printf("Digite uma string: ");
  fgets(texto, sizeof(texto), stdin);

  texto[strcspn(texto, "\n")] = '\0';

  inverte(texto);

  printf("String invertida: %s", texto);

  return 0;
}
