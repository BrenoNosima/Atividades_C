#include <stdio.h>
#include <string.h>

int main() {

    char nomes[5][50];
    float notas[5];
    float soma = 0, media;
    float nMaior = -1, nMenor = 101;
    int maior = 0, menor = 0;

 
    for (int i = 0; i < 5; i++) {
        printf("Informe o nome do aluno %d: ", i + 1);
        scanf(" %[^\n]s", nomes[i]); 

        printf("Informe a nota do aluno %s: ", nomes[i]);
        scanf("%f", &notas[i]);

        soma += notas[i];


        if (notas[i] > nMaior) {
            nMaior = notas[i];
            maior = i;
        }

        if (notas[i] < nMenor) {
            nMenor = notas[i];
            menor = i;
        }
    }

    media = soma / 5;


    printf("\nMédia das notas: %.2f\n", media);
    printf("Maior nota: %.2f - Aluno: %s\n", nMaior, nomes[maior]);
    printf("Menor nota: %.2f - Aluno: %s\n", nMenor, nomes[menor]);

    return 0;
}
