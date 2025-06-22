#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct no {
    int num;
    struct no *proximo;
} No;

No *topo = NULL;

void push(int valor);
void imprimir();
void liberar_pilha();
int existe_na_pilha(int valor);

int main() {
    srand(time(NULL));
    int x = 0;
    while (x < 10) {
        int valor = rand() % 100 + 1;
        if (!existe_na_pilha(valor)) {
            push(valor);
            x++;
        }
    }
    printf("\nConteudo da pilha (do topo para a base):\n");
    imprimir();
    liberar_pilha();
    return 0;
}

void push(int valor) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->num = valor;
        novo->proximo = topo;
        topo = novo;
    } else {
        printf("Erro ao alocar memoria!\n");
    }
}

void imprimir() {
    if (!topo) {
        printf("Pilha vazia!\n");
        return;
    }
    No *temp = topo;
    while (temp) {
        printf("%d\n", temp->num);
        temp = temp->proximo;
    }
}

void liberar_pilha() {
    while (topo) {
        No *temp = topo;
        topo = topo->proximo;
        free(temp);
    }
}

int existe_na_pilha(int valor) {
    No *temp = topo;
    while (temp) {
        if (temp->num == valor) return 1;
        temp = temp->proximo;
    }
    return 0;
}
