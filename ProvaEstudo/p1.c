#include <stdio.h>
#include <locale.h>

/*Pegar nome de no max 10 alunos, cada aluno tem 3 notas, exibir aprovado ou reprovado se for maior que 7, 
imprimir media e notas, colocar td num arquivo texto.*/
float calculaMedia(float soma);
int verificaAprovacao(float med);
void rArq(char nome[][50], float nota[][3], float med[], int aprovado[], int n);

int main(){
  setlocale(LC_ALL, "Portuguese");
  char nome[10][50];
  float nota[10][3], soma[10] = {0}, med[10];
  int aprovado[10], num;

  do {
    printf("Quantos alunos deseja cadastrar (máximo 10): ");
    scanf("%d", &num);
  } while (num <= 0 || num > 10);

  for (int i = 0; i < num; i++) {
    printf("Informe Nome[%d]: ", i + 1);
    scanf("%s", nome[i]);
    for (int j = 0; j < 3; j++) {
      printf("Qual a nota[%d]: ", j + 1);
      scanf("%f", &nota[i][j]);
      soma[i] += nota[i][j];
    }
    med[i] = calculaMedia(soma[i]);
    aprovado[i] = verificaAprovacao(med[i]);
  }

  rArq(nome, nota, med, aprovado, num);

  return 0;
}

float calculaMedia(float soma) {
  return soma / 3;
}

int verificaAprovacao(float med) {
  return med >= 7 ? 1 : 0;
}

void rArq(char nome[][50], float nota[][3], float med[], int aprovado[], int num){
  FILE *arquivo = fopen("aula.txt", "w");
  if(arquivo == NULL){
    printf("Erro ao abrir arquivo!");
    return;
  }

  for (int i = 0; i < num; i++) {
    fprintf(arquivo, "\nNOME: %s", nome[i]);
      for (int j = 0; j < 3; j++){
        fprintf(arquivo, "\nNOTA[%d]: %f", j + 1, nota[i][j]);
      }
    fprintf(arquivo, "\nMEDIA: %.2f", med[i]);
    if (aprovado[i]) {
      fprintf(arquivo, "\nSituação: APROVADO!!!");
    } else {
      fprintf(arquivo, "\nSituação: REPROVADO!!!");
    }
    fprintf(arquivo, "\n============================");
  }

  fclose(arquivo);
  printf("Dados registrados no arquivo com sucesso!\n");

}