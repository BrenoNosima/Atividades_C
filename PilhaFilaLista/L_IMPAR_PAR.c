#include <stdio.h>
#include <stdlib.h>

// Estrutura do n� da lista
typedef struct no {
    int dado;
    struct no* proximo;
} No;

// Fun��o para inserir no in�cio da lista
void inserir_inicio(No **lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = *lista;
    *lista = novo;
}

// Fun��o que verifica se um n�mero � par
int verifica_par_impar(int numero) {
    return numero % 2 == 0; // Retorna 1 se par, 0 se �mpar
}

// Fun��o para imprimir uma lista
void imprimir_lista(No* lista, const char* nome) {
    printf("%s: ", nome);
    while (lista != NULL) {
        printf("%d -> ", lista->dado);
        lista = lista->proximo;
    }
    printf("NULL\n");
}

// Fun��o que separa os n�meros em pares e �mpares
void separar_par_impar(No* lista, No** pares, No** impares) {
    while (lista != NULL) {
        if (verifica_par_impar(lista->dado)) {
            inserir_inicio(pares, lista->dado);
        } else {
            inserir_inicio(impares, lista->dado);
        }
        lista = lista->proximo;
    }
}

int main() {
    No* lista = NULL;
    No* pares = NULL;
    No* impares = NULL;

    inserir_inicio(&lista, 10);
    inserir_inicio(&lista, 7);
    inserir_inicio(&lista, 3);
    inserir_inicio(&lista, 8);
    inserir_inicio(&lista, 5);

    separar_par_impar(lista, &pares, &impares);

    imprimir_lista(lista, "Lista original");
    imprimir_lista(pares, "Lista de pares");
    imprimir_lista(impares, "Lista de �mpares");

    return 0;
}
