#include <stdio.h>
#include <string.h>

void COPIA(char s1[], char s2[]) {
  int i = 0;
  while (s1[i] != '\0') {
      s2[i] = s1[i];
      i++;
  }
  s2[i] = '\0'; 
}

int main()
{
  char s1[100];
  char s2[100];

  printf("Digite uma string: ");
  gets(s1);

  COPIA(s1,s2);

  printf("Conteúdo de s1: %s\n", s1);
    printf("Conteúdo copiado para s2: %s\n", s2);

  return 0;
}