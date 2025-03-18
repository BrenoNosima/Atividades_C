#include <stdio.h>

int main() {
    float preco, par, taxa;

    printf("Informe o valor do empréstimo: R$ ");
    scanf("%f", &preco);
    printf("Informe o qntd de parcelas: ");
    scanf("%f", &par);
    printf("Informe o valor dos juros: ");
    scanf("%f", &taxa);
    
    printf("O total sera: $ %.2f\n", (((taxa / 100) * (preco / par)) + (preco / par))*par);
 
    return 0;
}