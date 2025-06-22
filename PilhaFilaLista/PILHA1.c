#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[30];
    int idade;
    struct no *proximo;
} No;

No *topo = NULL;

void push();
void pop();
void imprimir();
void liberar_pilha();

int main() {
    int opcao;
    do {
        printf("\nMenu PILHA1\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n4 - Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                imprimir();
                break;
            case 4:
                liberar_pilha();
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
    return 0;
}


void push() {
    No *novo = malloc(sizeof(No));
    if (novo) {
        printf("Digite o nome: ");
        gets(novo->nome);

        printf("Digite a idade: ");
        scanf("%d", &novo->idade);
        getchar(); 

        novo->proximo = topo;
        topo = novo;

        printf("\nElemento %s empilhado com sucesso!\n", novo->nome);
    } else {
        printf("Erro ao alocar memoria!\n");
    }
}

void pop() {
    if (!topo) {
        printf("Pilha vazia!\n");
        return;
    }
    No *temp = topo;
    printf("Elemento (%s, %d) desempilhado.\n", temp->nome, temp->idade);
    topo = topo->proximo;
    free(temp);
}

void imprimir() {
    if (!topo) {
        printf("Pilha vazia!\n");
        return;
    }
    No *temp = topo;
    printf("Elementos da pilha (do topo para a base):\n");
    while (temp) {
        printf("Nome: %s, Idade: %d\n", temp->nome, temp->idade);
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
