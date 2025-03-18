#include <stdio.h>
#include <string.h>

int main() {
    char autor1[50] = "Junin"; 
    char autor2[50] = "Amaral"; 
    char resu[100];
    char resu2[100];

    strcpy(resu, autor1);
    strncat(resu2, autor2, 3);
    
    printf("3 letras do ultimo nome concatenadas: %s\n", resu2);

    return 0;
}
