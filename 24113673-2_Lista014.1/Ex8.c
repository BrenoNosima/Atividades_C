#include <stdio.h>
#include <stdbool.h>

int main() {
    int m[3][3];
    int igual = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i; j++) { 
            if (m[i][j] != m[j][i]) {
                igual = 0;
                break;
            }
        }
        if (igual == 0) {
            break;
        }
    }


    if (igual == 1) {
        printf("\nEh simetrica.\n");
    } else {
        printf("\nNao eh simetrica.\n");
    }

    return 0;
}
