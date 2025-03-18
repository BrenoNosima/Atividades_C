#include <stdio.h>

int main(){
char nome[10];
float nota1, nota2, mediaAluno, somaMedias = 0;
int reprovados = 0, aprovados = 0;

    for (int i = 1; i <= 32; i++) {
        printf("Digite o nome do aluno: ");
        scanf("%s", nome);
        
        do {
            printf("Digite a nota 1: ");
            scanf("%f", &nota1);
            printf("Digite a nota 2: ");
            scanf("%f", &nota2);
            if (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10) {
                printf("Nota invalida! Digite NOVAMENTE. ^-^\n");
            }
        } while (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10);

        mediaAluno = (nota1 + nota2) / 2;
        somaMedias += mediaAluno;

        if (mediaAluno >= 6.0) {
            aprovados++;
        } else {
            reprovados++;
        }
    }

    float mediaTurma = somaMedias / 32;
    float percentualAprovados = ((float)aprovados / 32 * 100);
    float percentualReprovados = ((float)reprovados / 32 * 100);

    printf("\nMedia da turma: %.2f\n", mediaTurma);
    printf("Percentual de aprovados: %.2f%%\n", percentualAprovados);
    printf("Percentual de reprovados: %.2f%%\n", percentualReprovados);

  return 0;
}