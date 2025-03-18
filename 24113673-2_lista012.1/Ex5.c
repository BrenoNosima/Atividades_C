#include <stdio.h>
#include <string.h>

int main() {
    char titulo[50] = "Chapeuzinho Verde"; 
    char copia[6];

    
    strncpy(copia, titulo, 5);
    
    copia[5] = '\0';


    printf("5 caracteres: %s\n", copia);

    return 0;
}
