#include <stdio.h>

// Prot�tipos das fun��es
void carregaM(int matriz[3][3]);
void mostraM(int matriz[3][3]);
int diagonalP(int matriz[3][3]);
int diagonalS(int matriz[3][3]);
void salvaEmArquivo(int matriz[3][3], int somaPrincipal, int somaSecundaria);

int main() {
    int matriz[3][3];

    // Carrega a matriz com valores fornecidos pelo usu�rio
    carregaM(matriz);
    mostraM(matriz);

    // Calcula as somas das diagonais
    int somaPrincipal = diagonalP(matriz);
    int somaSecundaria = diagonalS(matriz);

    // Exibi��o dos resultados no console
    printf("\nSoma da diagonal principal: %d\n", somaPrincipal);
    printf("Soma da diagonal secund�ria: %d\n", somaSecundaria);

    // Salva os dados no arquivo
    salvaEmArquivo(matriz, somaPrincipal, somaSecundaria);

    return 0;
}

// Fun��o para carregar a matriz
void carregaM(int matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Informe o num [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Fun��o para exibir a matriz
void mostraM(int matriz[3][3]) {
    printf("\nMatriz inserida:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Fun��o para calcular a soma da diagonal principal
int diagonalP(int matriz[3][3]) {
    int soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += matriz[i][i];
    }
    return soma;
}

// Fun��o para calcular a soma da diagonal secund�ria
int diagonalS(int matriz[3][3]) {
    int soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += matriz[i][3 - 1 - i]; // 3 � o tamanho da matriz
    }
    return soma;
}

// Fun��o para salvar os dados em um arquivo
void salvaEmArquivo(int matriz[3][3], int somaPrincipal, int somaSecundaria) {
    FILE *arquivo = fopen("resultados.txt", "w"); // Abre o arquivo em modo escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Escreve a matriz no arquivo
    fprintf(arquivo, "Matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fprintf(arquivo, "%3d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    // Escreve os resultados no arquivo
    fprintf(arquivo, "\nSoma da diagonal principal: %d\n", somaPrincipal);
    fprintf(arquivo, "Soma da diagonal secund�ria: %d\n", somaSecundaria);

    fclose(arquivo); // Fecha o arquivo
    printf("\nResultados salvos no arquivo 'resultados.txt'.\n");
}
