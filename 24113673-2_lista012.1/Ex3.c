#include <stdio.h>
#include <string.h>

int main() {
    char biblioteca[50] = "Junin"; 
    char copia[50] = " Amaral"; 

    strcat(biblioteca, copia);
    
    printf("Concatenada: %s\n", biblioteca);

    return 0;
}