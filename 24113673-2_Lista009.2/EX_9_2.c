#include <stdio.h>

int main() {
    char nome[50], sexo, contin = 'S';
    int idade, idMulheres = 0, mulheres = 0;
    float media;

    while (contin != 'N' && contin != 'n') {
        printf("Informe o nome: ");
        scanf("%s", nome);
        
        printf("Informe a idade: ");
        scanf("%d", &idade);
        
        printf("Informe o sexo (F/M): ");
        scanf(" %c", &sexo);

        if (sexo == 'F' || sexo == 'f') {
            idMulheres += idade;
            mulheres++;
        }

        printf("Deseja continuar informando dados? (S/N): ");
        scanf(" %c", &contin);

    }

    media = idMulheres/mulheres;
    printf("A media da idade das Mulheres eh: %.2f", media);
    return 0;
}