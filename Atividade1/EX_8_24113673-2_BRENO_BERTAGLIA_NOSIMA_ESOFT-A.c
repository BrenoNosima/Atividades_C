#include <stdio.h>

int main() {
    float dis, cM, pG, cT;

    printf("Digite a distancia percorrida em km: ");
    scanf("%f", &dis);

    printf("Digite o consumo medio do veiculo (km por litro): ");
    scanf("%f", &cM);

    printf("Digite o preco da gasolina por litro: ");
    scanf("%f", &pG);

    cT =  pG * (dis / cM);

    printf("Custo total da viagem eh: R$ %.2f\n", cT);

    return 0;
}
