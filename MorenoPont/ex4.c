#include <stdio.h>
#include <stdlib.h>

void mostra(int k[], int tam){
  int i;
  for(i = 0; i<tam; i++){
    printf("%d \n",k[i]);
  }
}

void altera(int k[], int tam) {
  for(int i = 0; i < tam; i++) {
      k[i] = k[i] * 2;
  }
}

int main(){
  int vet[]={10,20,30,40,50};
  int tam=sizeof(vet)/sizeof(int);
  mostra(vet,tam);
  altera(vet,tam);
  mostra(vet,tam);

  return 0;
}