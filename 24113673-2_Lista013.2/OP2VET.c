#include <stdio.h>

int main(){
  int vet1[3];
  int vet2[3];
  int vet3[3];
  int sub = 0, soma = 0, soma1 = 0;
  int igual;

  for (int i = 0; i < 3; i++){
    printf("Informe um num do vetor 1: ");
    scanf("%d", &vet1[i]);
    soma += vet1[i];
    sub -= vet1[i];
  }

  for (int i = 0; i < 3; i++){
    printf("Informe um num do vetor 2: ");
    scanf("%d", &vet2[i]);
    soma += vet2[i];
    soma1 +=vet2[i];
    sub -= vet2[i];
  }

  printf("Soma dos vet eh: %d\n", soma);
  printf("Sub dos vet eh: %d\n", sub);


  for (int i = 0; i < 2; i++){
    printf("Informe um num do vetor 3: ");
    scanf("%d", &vet3[i + 1]);
    soma1 += vet3[i + 1];
  }

  printf("Soma do terceiro vet com segundo vet eh: %d.\n",soma1);

  for (int i = 0; i < 3; i++){
    if(vet1[i] == vet2[i]){
      igual += 1;
    } else {
      igual = -1;
    }
  }

  if (igual >= 3){
      printf("Vetores 1 e 2 eh igual.\n");
    } else{
      printf("Vetores 1 e 2 nao sao iguais.\n");
    }
  

  return 0;
}