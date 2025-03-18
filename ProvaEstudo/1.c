#include <stdio.h>



int main() {
    float notas[3][3];
    float maior, menor;

    for (int i = 0; i < 3; i++) {
        printf("\nNotas para a disciplina %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Digite a nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        maior = notas[i][0];
        menor = notas[i][0];
        for (int j = 1; j < 3; j++) {
            if (notas[i][j] > maior) {
                maior = notas[i][j];
            }
            if (notas[i][j] < menor) {
                menor = notas[i][j];
            }
        }
        printf("\nDisciplina %d - Maior nota: %.2f, Menor nota: %.2f\n", i + 1, maior, menor);
    }

    return 0;
}
