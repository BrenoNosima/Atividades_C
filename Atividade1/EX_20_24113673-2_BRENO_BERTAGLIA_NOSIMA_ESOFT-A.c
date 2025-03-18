#include <stdio.h>

int main() {
    int ano;

    printf("Informe o ano: ");
    scanf("%d", &ano);

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        printf("%d eh ano bissexto.", ano);
    } else {
        printf("%d nao eh ano bissexto.", ano);
    }

    return 0;
}
