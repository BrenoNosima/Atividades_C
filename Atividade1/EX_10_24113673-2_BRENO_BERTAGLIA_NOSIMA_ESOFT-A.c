#include <stdio.h>

int main (){
  float soma = 0;
  float n = 0;
  float m = 0;
  int i, qnt;

  printf("Informe qnt de alunos da turma: ");
  scanf("%d", &qnt);

  for (i = 1; i <= qnt; i++){
    printf("Informe a nota: ");
    scanf("%f", &n);
    soma += n;
  } 
  m = soma/qnt;

  if (m >= 6){ 
  printf ("Turma aprovada. A media da turma eh: %.2f", m);
  } else{
  printf ("Turma reprovada. A media da turma eh: %.2f", m);

  }
  return 0;
}