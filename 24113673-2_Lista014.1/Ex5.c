#include <stdio.h>

int main(){

    int num1 [10][10];
    int num2 [10][10];
    int num3 [10][10];


    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        printf("Informe um num1: ");
        scanf("%d", &num1[i][j]);
      }
    }

    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        printf("Informe um num2: ");
        scanf("%d", &num2[i][j]);
      }
    }

      for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
          num3[i][j] = num1[i][j] * num2 [i][j];
        }
    }


    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        printf("%d ", num3[i][j]);
      }
      printf("\n");
    }

return 0;
}