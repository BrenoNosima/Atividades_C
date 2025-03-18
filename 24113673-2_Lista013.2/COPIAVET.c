#include <stdio.h>

int main() {
    int n;

    printf("Digite o tamanho do vet: ");
    scanf("%d", &n);

    float vetor[n];
    float vetor2[n];

    for (int i = 0; i < n; i++) {
        printf("Insira o %d num: ", i + 1);
        scanf("%f", &vetor[i]);
        vetor2[i] = vetor[i];
    }

    printf("Segundo vetor copiado é: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f \t", vetor2[i]);  
    }
    

    return 0;
}
