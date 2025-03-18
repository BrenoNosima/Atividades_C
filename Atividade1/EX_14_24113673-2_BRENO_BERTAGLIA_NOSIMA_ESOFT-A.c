#include <stdio.h>
#include <ctype.h>

int main() {
  int  qnt = 0; 
  char *des, cate;
  float preco, total = 0;

  printf("Informe a categoria do livro: ");
  scanf("%c", &cate);
  printf("Informe a quantidade de livro: ");
  scanf("%d", &qnt);
  printf("Informe o preco uni do livro: ");
  scanf("%f", &preco);

  if(cate == 'A' && qnt >= 2){
    des = "20%";
    total = (preco * qnt) - ((preco * qnt) * 0.20 ); 
  } else if (cate == 'B' && qnt >= 5){
    des = "10%";
    total = preco + ((preco * qnt) * 0.10 ); 
  } else if (cate == 'C'){
    des = "0%";
    total = preco * qnt;
  }

  printf("O total a pagar eh: %.2f$.\nCom %s de desconto.", total, des);
return 0;
}