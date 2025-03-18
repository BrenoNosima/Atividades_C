#include <stdio.h>
#include <string.h>

int main() {
    char autor[50] = "aalibra"; 

    char *ocorrencia = strstr(autor, "lib");

    if (ocorrencia != NULL) {   
        printf("Substring 'lib' esta em: %s\n", ocorrencia);
    } else {
        printf("Nao foi encontrado.");
    }

    return 0;
}