#include <stdio.h>

int main(){

int num1 [3][3];
int num2 [3][3];
int num3 [3][3];


for(int i = 0; i < 3; i++){
for(int j = 0; j < 3; j++){
printf("Informe um num1: ");
scanf("%d", &num1[i][j]);
     }
}

for(int i = 0; i < 3; i++){
for(int j = 0; j < 3; j++){
printf("Informe um num2: ");
scanf("%d", &num2[i][j]);
     }
}

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      num3[i][j] = num1[i][j] + num2 [i][j];
    }
  }


  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", num3[i][j]);
  }
    printf("\n");
    }

return 0;
}