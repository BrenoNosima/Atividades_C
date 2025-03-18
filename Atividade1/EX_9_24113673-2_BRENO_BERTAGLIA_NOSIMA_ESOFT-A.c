#include <stdio.h>

int main() {
    int num;
    int p = 1;
    int i;

    printf("Digite um número: ");
    scanf("%d", &num);

    if (num < 2) {
        p = 0;
    } else {
        for (i = 2; i < num; i++) {
            if (num % i == 0) { 
                p = 0;
                break;
            }
            }
        }
    if (p) {
        printf("%d eh um numero primo.\n", num);
    } else {
        printf("%d nao eh um numero primo.\n", num);
    }
    return 0;
}
