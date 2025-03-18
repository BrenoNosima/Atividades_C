#include <stdio.h>
#include <stdlib.h> // Para rand() e srand()
#include <time.h>   // Para time()

int main() {
    int num;
    int ten = 0;   
    int numS;

    srand(time(0));
    numS = rand() % 100 + 1;

    printf("Adivinhe um número de 1 a 100.\nCom 10 tent.\n");

    while (ten < 10) {
        printf("Tent %d: ", ten + 1);
        scanf("%d", &num); 
        ten++;

        if (num == numS) {
            printf("Parabéns! Você acertou o número em %d tentativas!\n", ten);
            break;
        } else if (num < numS) {
            printf("Dica: O número secreto é maior!\n\n");
        } else {
            printf("Dica: O número secreto é menor!\n\n");
        }
    }

    if (num != numS) {
        printf("Você esgotou suas 10 tent. O num secreto eh %d.\n", numS);
    }

    return 0;
}
