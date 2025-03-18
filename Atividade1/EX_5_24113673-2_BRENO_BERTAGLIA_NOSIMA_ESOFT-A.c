#include <stdio.h>
#include <stdlib.h> // Para rand() e srand()
#include <time.h>   // Para time()

int main() {
    int num;
    int ten = 0;   
    int numS;

    srand(time(0));
    numS = rand() % 100 + 1;

    printf("Adivinhe um n�mero de 1 a 100.\nCom 10 tent.\n");

    while (ten < 10) {
        printf("Tent %d: ", ten + 1);
        scanf("%d", &num); 
        ten++;

        if (num == numS) {
            printf("Parab�ns! Voc� acertou o n�mero em %d tentativas!\n", ten);
            break;
        } else if (num < numS) {
            printf("Dica: O n�mero secreto � maior!\n\n");
        } else {
            printf("Dica: O n�mero secreto � menor!\n\n");
        }
    }

    if (num != numS) {
        printf("Voc� esgotou suas 10 tent. O num secreto eh %d.\n", numS);
    }

    return 0;
}
