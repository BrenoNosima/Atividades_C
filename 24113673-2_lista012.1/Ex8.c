#include <stdio.h>
#include <string.h>

int main() {
    char autor[50] = "Ramon Dino"; 

    char *ocorrencia = strchr(autor, 'a');

    if (ocorrencia != NULL) {
        printf("'a' esta em: %s\n", ocorrencia);
    } else {
        printf("'a' nao foi encontrado.");
    }

    return 0;
}
