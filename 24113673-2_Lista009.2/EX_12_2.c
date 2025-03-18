#include <stdio.h>

int main() {
    int idade, sexo, filhos;
    int tHomens = 0, tMulheres = 0, semFilho = 0; 
    int somaIdadeMulheresSemFilhos = 0;
    int maisJovem = 99; 
    float percentualHomens;

    int i = 0;
    while(i < 12) {

        do {
            printf("Digite a idade da pessoa %d: ", i + 1);
            scanf("%d", &idade);

        } while (idade < 0);

        if (idade < maisJovem) {
            maisJovem = idade;
        }

        do {
            printf("Digite o sexo da pessoa %d (1 para Masculino, 2 para Feminino): ", i + 1);
            scanf("%d", &sexo);
            if (sexo != 1 && sexo != 2) {
                printf("Sexo invalido.\n");
            }
        } while (sexo != 1 && sexo != 2);

        do {
            printf("Digite a quantidade de filhos da pessoa %d: ", i + 1);
            scanf("%d", &filhos);
            if (filhos < 0) {
                printf("Quantidade de filhos invalida.\n");
            }
        } while (filhos < 0);

        if (sexo == 1) {
            tHomens++;
        } else if (sexo == 2) {
            tMulheres++;
            if (filhos == 0) {
                semFilho++;
                somaIdadeMulheresSemFilhos += idade;
            }
        }
      i++;
    }


    percentualHomens = (tHomens / 12.0) * 100;

    float mediaIdadeMulheresSemFilhos = (somaIdadeMulheresSemFilhos / semFilho);

    printf("Percentual de homens: %.2f%%\n", percentualHomens);
    printf("Média de idade das mulheres sem filhos: %.2f\n", mediaIdadeMulheresSemFilhos);
    printf("Idade da pessoa mais jovem: %d\n", maisJovem);
    printf("Quantidade de mulheres entrevistadas: %d\n", tMulheres);

    return 0;
}
