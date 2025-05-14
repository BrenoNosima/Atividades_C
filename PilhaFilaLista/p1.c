#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct apelido_no {
    int dado;
    struct apelido_no *proximo;
} no;

no *topo = NULL;

// Protótipos das funções
void push(int item);
void pop();
void imprimir();
int entrada_dados();
void liberar_pilha();

int main() {
    int opcao;

    do {
        system("cls||clear");
        printf("\n\nMenu\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n4 - Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                push(entrada_dados());
                break;
            case 2:
                pop();
                break;
            case 3:
                imprimir();
                system("pause"); // Windows
                break;
            case 4:
                printf("Saindo...\n");
                liberar_pilha();
                break;
            default:
                printf("Opcao invalida!\n");
                system("pause");
        }
    } while (opcao != 4);
    return 0;
}

void push(int item) {
    no *novo = malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    novo->dado = item;
    novo->proximo = topo;
    topo = novo;
    printf("Elemento %d empilhado com sucesso!\n", novo->dado);
    system("pause");
}

void pop() {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
    } else {
        no *temp = topo;
        printf("Elemento %d desempilhado.\n", temp->dado);
        topo = topo->proximo;
        free(temp);
    }
    system("pause");
}

void imprimir() {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }
    no *temp = topo;
    printf("Elementos da pilha (do topo para a base):\n");
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->proximo;
    }
    printf("\n");
}

int entrada_dados() {
    int dado;
    printf("Digite um numero: ");
    scanf("%d", &dado);
    return dado;
}

void liberar_pilha() {
    while (topo != NULL) {
        no *temp = topo;
        topo = topo->proximo;
        free(temp);
    }
}