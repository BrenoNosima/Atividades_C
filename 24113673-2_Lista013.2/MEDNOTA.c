#include <stdio.h>

int main() {
    int n;
    float media = 0;

    printf("Digite a quantidade de notas: ");
    scanf("%d", &n);

    float vetor[n];

    for (int i = 0; i < n; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &vetor[i]);
        media += vetor[i] / n;
    }

    printf("A media das notas eh: %.2f", media);

    return 0;
}
