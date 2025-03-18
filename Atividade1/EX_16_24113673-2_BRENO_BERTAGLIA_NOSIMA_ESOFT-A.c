#include <stdio.h>
#include <ctype.h>

int main() {
    int pess;
    char tipoP;
    float pP = 0, total = 0, desconto = 0;

    printf("Informe a qntd de pessoas no grupo: ");
    scanf("%d", &pess);

    printf("Escolha o tipo de pacote (B: Basico, N: Normal, L: Luxo): ");
    scanf(" %c", &tipoP);

    switch (toupper(tipoP)) {
        case 'B':
            pP = 100;
            break;
        case 'I':
            pP = 200;
            break;
        case 'L':
            pP = 400;
            break;
        default:
            printf("Opção de pacote inválida.\n");
            return 1;
    }

    if (pess >= 5 && pess <= 10) {
        desconto = 0.05;  // 5% de desconto
    } else if (pess >= 11 && pess <= 20) {
        desconto = 0.10;  // 10% de desconto
    } else if (pess > 20) {
        desconto = 0.15;  // 15% de desconto
    }

    total = (pP * pess) * (1 - desconto);

    printf("O custo total da viagem para %d pessoas é: R$ %.2f\n", pess, total);

    return 0;
}
