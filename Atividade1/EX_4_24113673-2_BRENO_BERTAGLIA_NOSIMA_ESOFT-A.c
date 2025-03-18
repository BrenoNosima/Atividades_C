#include <stdio.h>
#include <math.h>

int main(){
  int n;
  float r;
  int q;

  printf("Digite um num: ");
  scanf("%d", &n);

  r = sqrt(n);
  q = r;
  r -= q;

  if (r == 0){
    printf("O numero eh um quadrado perfeito.");
  } else{
    printf("O numero nao eh um quadrado perfeito.");
  }


  return 0;
}