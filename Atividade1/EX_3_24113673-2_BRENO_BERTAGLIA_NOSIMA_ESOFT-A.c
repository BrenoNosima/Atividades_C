#include <stdio.h>

int main(){
  float s, sf;
  char n;
  printf ("Digite o valor do salario: ");
  scanf("%f", &s);
  printf ("Digita a classificacao: ");
  scanf("%s", &n); 
switch (n){
    case 'A':
        sf = s +  (s * 0.15);
        break;

    case 'B':
        sf = s +  (s * 0.10);
        break;

    case 'C':
        sf = s + (s * 0.05);
        break;
    default: 
        sf = s;
    break;
 }
 printf("Salario final eh: $%.2f", sf);
 
 return 0;
}