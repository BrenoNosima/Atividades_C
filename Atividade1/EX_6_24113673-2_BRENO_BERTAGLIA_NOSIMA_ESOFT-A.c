#include <stdio.h>
#include <ctype.h>

int main() {
  int qnt, des; 
  char conf;
  float preco, total;

  do{
    printf("Digite a quantidade desejada: ");
    scanf("%d", &qnt);
    printf("Digite o preço unitário: ");
    scanf("%f", &preco);
    printf("Qual desconto: ");
    scanf("%d", &des);
    total = total + ((preco - ((preco / 100) * des)) * qnt);
    printf("Deseja continuar? (S/N): ");
    scanf(" %c", &conf);
    conf = toupper(conf);
    }     while (conf == 'S');

  printf("O total a pagar eh: %.2f", total);
return 0;
}