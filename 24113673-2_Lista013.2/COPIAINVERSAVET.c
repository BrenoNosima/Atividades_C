#include <stdio.h>

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    float vetor[n];
    float vetor2[n];

    for (int i = 0; i < n; i++) {
        printf("Insira o %d numero: ", i + 1);
        scanf("%f", &vetor[i]);
        vetor2[i] = vetor[i];
    }

    printf("Segundo vetor copiado em ordem inversa eh: ");
    for (int i = n - 1; i >= 0; i--) { 
        printf("%.2f  ", vetor2[i]);
    }
    printf("\n");

    return 0;
}
