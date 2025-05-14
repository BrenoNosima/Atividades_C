#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ***matriz;    // Ponteiro para a matriz 3x4 de strings
    int i, j;
    char buffer[11];   // Buffer para leitura de strings, com limite de 10 caracteres

    // Alocando memória para a matriz 3x4 (3 linhas, 4 colunas)
    matriz = malloc(3 * sizeof(char **));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para a matriz!\n");
        return 1;
    }

    // Alocando memória para cada linha da matriz
    for (i = 0; i < 3; i++) {
        matriz[i] = malloc(4 * sizeof(char *));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para a linha %d!\n", i);
            return 1;
        }

        // Alocando memória para cada string (coluna) de cada linha
        for (j = 0; j < 4; j++) {
            matriz[i][j] = malloc(11 * sizeof(char));  // Cada string pode ter até 10 caracteres + 1 para '\0'
            if (matriz[i][j] == NULL) {
                printf("Erro ao alocar memória para matriz[%d][%d]!\n", i, j);
                return 1;
            }

            // Leitura da string com limite de 10 caracteres
            printf("Digite a string para matriz[%d][%d] (máximo 10 caracteres): ", i, j);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';  // Remove o caractere de nova linha '\n'

            // Copiando a string para a matriz
            strncpy(matriz[i][j], buffer, 10);
            matriz[i][j][10] = '\0';  // Garantir que a string está terminada com '\0'
        }
    }

    // Exibindo a matriz 3x4 preenchida
    printf("\nMatriz 3x4 de strings:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("matriz[%d][%d] = %s\n", i, j, matriz[i][j]);
        }
    }

    // Liberando a memória
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
