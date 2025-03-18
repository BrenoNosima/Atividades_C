#include <stdio.h>

int main() {
  int dia, mes, ano;
  char continuar = 'S';

    while(continuar == 'S'){
      //DIA
      do {
          printf("Digite o dia de nascimento (1-31): ");
          scanf("%d", &dia);
          if (dia < 1 || dia > 31) {
              printf("Dia invalido.\n");
          }
      } while (dia < 1 || dia > 31);


      //MES
      do {
          printf("Digite o mes de nascimento (1-12): ");
          scanf("%d", &mes);
          if (mes < 1 || mes > 12) {
              printf("Mes invalido.\n");
          }
      } while (mes < 1 || mes > 12);

      //ANO
      do {
          printf("Digite o ano de nascimento (por exemplo, 1990): ");
          scanf("%d", &ano);
          if (ano < 1900 || ano > 2100) {
              printf("Ano invalido.\n");
          }
      } while (ano < 1900 || ano > 2100);

      if ((mes == 1 && dia >= 21) || (mes == 2 && dia <= 19)){
        printf("Seu singno eh Aquario!\n");
      }else if ((mes == 2 && dia >= 20) || (mes == 3 && dia <= 20)){
        printf("Seu singno eh Peixes!\n");
      }else if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 20)){
        printf("Seu singno eh Aries!\n");
      }else if ((mes == 4 && dia >= 21) || (mes == 5 && dia <= 20)){
        printf("Seu singno eh Touro!\n");
      }else if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20)){
        printf("Seu singno eh Gemeos!\n");
      }else if ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 21)){
        printf("Seu singno eh Cancer!\n");
      }else if ((mes == 7 && dia >= 22) || (mes == 8 && dia <= 22)){
        printf("Seu singno eh Leao!\n");
      }else if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22)){
        printf("Seu singno eh Virgem!\n");
      }else if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22)){
        printf("Seu singno eh Libra!\n");
      }else if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21)){
        printf("Seu singno eh Escorpiao!\n");
      }else if ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21)){
        printf("Seu singno eh Sagitario!\n");
      }else if ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 20)){
        printf("Seu singno eh Capricornio!\n");
      }

      printf("Deseja continuar?(S/N) ");
      scanf(" %c", &continuar); //espaço antes, para ignorar o caracter de nova linha
    }
    return 0;
}
