#include <stdio.h>
#include <ctype.h>

#include <stdio.h>
#include <ctype.h>

int main() {
    float temp, novaT;
    char graus;

    do {
        printf("Deseja transformar a medida fornecida em (C: Celsius / F: Fahrenheit):\n");
        scanf(" %c", &graus);  // Adiciona um espaço antes de %c para ignorar o '\n' anterior

        if (toupper(graus) == 'F') {
            printf("Informe a temperatura em Celsius: ");
            scanf("%f", &temp);
            novaT = (temp * 1.8) + 32;
            printf("%.2f graus Celsius é igual a %.2f graus Fahrenheit.\n", temp, novaT);
        } else if (toupper(graus) == 'C') {
            printf("Informe a temperatura em Fahrenheit: ");
            scanf("%f", &temp);
            novaT = (temp - 32) / 1.8;  // Fórmula corrigida
            printf("%.2f graus Fahrenheit é igual a %.2f graus Celsius.\n", temp, novaT);
        } else {
            printf("Escolha inválida. Por favor, digite 'C' ou 'F'.\n\n");
        }

    } while (toupper(graus) != 'F' && toupper(graus) != 'C');

    return 0;
}
