#include <stdio.h>
#include <stdlib.h>

void mostra(int k[], int tam)
{
  int i;
  for (i = 0; i < tam; i++)
  {
    printf("%d \n", *(k + i));
  }
}

int main()
{
  int tam = 5;
  int vet[tam];

  for (int i = 0; i < tam; i++)
  {
    printf("Informe o valor da posição %d: ", i);
    scanf("%d", &vet[i]);
  }

  printf("\nValores informados:\n");
  mostra(vet, tam);

  return 0;
}