#include <stdio.h>


int main() {
    int idades;
    int maisVelha, maisNovo;

    for (int i = 0; i < 5; i++) {
        printf("Digite a idade da pessoa: ");
        scanf("%d", &idades);

        if (i == 0) {
            maisVelha = idades;
            maisNovo = idades;
        }

        if (idades > maisVelha) {
            maisVelha = idades;
        }
        if (idades < maisNovo) {
            maisNovo = idades;
        }
    }

    printf("\nA pessoa mais velha tem %d anos.\n", maisVelha);
    printf("A pessoa mais jovem tem %d anos.\n", maisNovo);

    return 0;
}
