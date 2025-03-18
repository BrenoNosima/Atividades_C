#include <stdio.h>

int main() {
    int vetor[10];
    int aparece, encontrou, contador = 0;
    int continuar;

    for (int i = 0; i < 10; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    do{
      printf("Informe o num que deseja encontrar: ");
      scanf("%d", &aparece);

      encontrou = 0;

      for (int i = 0; i < 10; i++){
        if (aparece == vetor[i]){
          printf("Numero %d aparece na posicao %d.\n", aparece, i + 1);
          encontrou = 1;
          contador += 1;
        } 
      }
      if (encontrou == 1){
        printf("Numero %d aparece %d vezes.\n", aparece, contador);
      }else {
        printf("Numero %d nao aparece.\n", aparece);
      } 

      printf("Deseja encontrou outro? Sim=1 Nao=2 ");
      scanf("%d", &continuar);
    }while(continuar == 1);
   
    printf("A primeira posicao do vetor eh o num: %d\n", vetor[0]);

    return 0;
}
