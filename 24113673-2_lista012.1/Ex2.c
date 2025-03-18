#include <stdio.h>
#include <string.h>

int main() {
    char biblioteca[50] = "Vazio"; 
    char copia[50]; 

    strcpy(copia, biblioteca);
    
    printf("Copia da string: %s\n", copia);

    return 0;
}
