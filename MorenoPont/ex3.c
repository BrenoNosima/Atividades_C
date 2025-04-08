#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main()
{
  int n1, *ptr;

  printf("Informe o valor de n1: ");
  scanf("%d", &n1);

  ptr = &n1;

  printf("Valor de n1: %d\n", n1);
  printf("Endereco de memoria de n1: %p\n", &n1);
  printf("Valor da variavel ptr (endereco que ela guarda): %p\n", ptr);
  printf("Endereço de memória de ptr: %p\n", &ptr);
  printf("Valor de ptr está apontando: %d\n", *ptr);
  printf("Endereco para o qual ptr aponta: %p\n", ptr);
  printf("Tamanho em bytes da variavel n1: %d\n", sizeof(n1));
  printf("Tamanho em bytes da variavel ptr: %d\n", sizeof(ptr));
  printf("Tamanho em bytes do valor apontado por ptr: %d\n", sizeof(*ptr));

  return 0;
}