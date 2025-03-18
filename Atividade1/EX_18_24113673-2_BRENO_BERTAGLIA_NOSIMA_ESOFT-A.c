#include <stdio.h>
#include <math.h>

int main() {
    float valor, taxa, montante;
    int mes;

    printf("Informe o valor do investimento inicial: R$ ");
    scanf("%f", &valor);

    printf("Informe a taxa de juros (em %% por período): ");
    scanf("%f", &taxa);

    printf("Informe a qntd de mes: ");
    scanf("%d", &mes);
    montante = valor * pow((1 + taxa / 100), mes);

    printf("O montante de %d meses (J compostos), sera: $ %.2f\n", mes, montante);

    return 0;
}
