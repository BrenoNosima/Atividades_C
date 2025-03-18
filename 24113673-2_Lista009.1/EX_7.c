#include <stdio.h>

int main() {
    float temperatura, convertido;
    char opcao;

    while (opcao != 'C' || opcao != 'F' ) {
        printf("\nDigite a temperatura (exemplo: 25C ou 77F): ");
        scanf(" %f%c", &temperatura, &opcao); 

        if (opcao == 'C') {
            convertido = (temperatura * 9/5) + 32;
            printf("%.2f Celsius equivale a %.2f Fahrenheit\n", temperatura, convertido);
            break;
        } else if (opcao == 'F') {
            convertido = (temperatura - 32) * 5/9;
            printf("%.2f Fahrenheit equivale a %.2f Celsius\n", temperatura, convertido);
            break;
        } else {
            printf("Utilize 'C' ou 'F'.\n");
        }
    }

    return 0;
}
