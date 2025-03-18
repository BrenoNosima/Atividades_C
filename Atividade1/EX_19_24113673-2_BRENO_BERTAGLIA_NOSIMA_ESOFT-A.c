#include <stdio.h>


int main(){
    float temp, h, total;

    printf("Digite a tempera e a humidade do ar em porcentagem");
        scanf("%f %f", &temp, &H);
    total = temp + (0.55 * (humidade - 50));

    printf("O valor da sensação termica eh de %.2f graus celcius", total);

    



    return 0;
}