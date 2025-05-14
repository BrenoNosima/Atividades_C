#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
//------------------------------------------------------------------------------
typedef struct {
    char nome[50]; // Nome do Jogador Ex: Moreno
    int idade; // Idde do jogador Ex: 41
    char classe[20]; // Classe do Jogador Ex: "Guerreiro", "Mago", etc.
} personagem;
//------------------------------------------------------------------------------
typedef struct {
    int nivel; // Nível do jogador no jogo Ex: 12
    int experiencia; // Pontuação de experiência Ex: 890
    personagem p; // Dados do personagem
} jogador;
//------------------------------------------------------------------------------
typedef struct apelido {
    jogador jog; //jog é uma variável do tipo jogador
    struct apelido *proximo; //*proximo é um ponteiro do nó
} no;
//------------------------------------------------------------------------------
no *topo = NULL; //topo é ponteiro que indica o TOPO da pilha

void push(jogador j);     // procedimento Empilhar
void pop();               // procedimento Desempilhar
void mostra_pilha();      // procedimento Imprimir pilha
void liberar_pilha();     // procedimento Limpar memória
jogador entrada_dados();  // função Entrada de dados que retorna dados do jogador

//-------------------------------------------
int main() {
    setlocale(LC_ALL, ""); //ativa teclado padrão do windows
    int opcao; //opção para o MENU
    jogador dados; //dados é uma variável do tipo jogador
    do {
        printf("\nMenu - Pilha de Jogadores");
        printf("\n1. Empilhar Jogador");
        printf("\n2. Desempilhar Jogador");
        printf("\n3. Apresenta Pilha");
        printf("\n4. Limpar Memória");
        printf("\n5. Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        fflush(stdin); // limpa buffer do teclado

        switch (opcao) {
            case 1:
                dados = entrada_dados(); //variável dados recebe informacoes do jogador
                push(dados); //empilha dados do jogador
                break;
            case 2:
                pop(); //desempilha o jogador do topo
                break;
            case 3:
                mostra_pilha(); //apresenta a pilha toda
                break;
            case 4:
                liberar_pilha();
                break;
            default:
                printf("Opção inválida");
        }
    } while (opcao != 5);
    liberar_pilha(); // limpeza final
    printf("\nFim do programa.\n");
    system("pause");
    return 0;
}
//-------------------------------------------
void push(jogador j) {
    no *novo = malloc(sizeof(no)); //aloca memória para o novo nó
    if(novo) {
        novo->jog = j; //atribui os dados do jogador ao novo nó
        novo->proximo = topo; //o próximo do novo nó é o topo atual
        topo = novo; //atualiza o topo para o novo nó
    } else {
        printf("Erro ao alocar memória!\n");
        return;
    }
    printf("\nJogador %s empilhado com sucesso!\n", j.p.nome);
}
//-------------------------------------------
void pop() {
 if(topo == NULL) {
        printf("\nPilha vazia!\n");
        return;
    } else {
    no *temp = topo;
    topo = topo->proximo; 
    printf("\nJogador %s desempilhado com sucesso!\n", temp->jog.p.nome);
    free(temp); 
  }
}
//-------------------------------------------
void mostra_pilha() {
    no *temp;
    int x = 0;
    temp= topo;
    printf("Imprimindo a pilha(JOGADORES):\n");
    while(temp!=NULL){
      printf("\nJogador: %d\n", x+1);
      printf("Nome: %s\n", temp->jog.p.nome);
      printf("Idade: %d\n", temp->jog.p.idade);
      printf("Classe: %s\n", temp->jog.p.classe);
      printf("Nivel: %d\n", temp->jog.nivel);
      printf("Experiencia: %d\n", temp->jog.experiencia);
      temp=temp->proximo;
      x++;
    }
}
//-------------------------------------------
void liberar_pilha() {
    no *temp;
    while(topo != NULL) {
        temp = topo; // armazena o nó atual
        topo = topo->proximo; // move o topo para o próximo nó
        free(temp); // libera a memória do nó atual
    }
    printf("\nMemória liberada com sucesso.\n");
}
//-------------------------------------------
jogador entrada_dados() {
    jogador jog;
    printf("\nCadastro do Jogador:\n");
    printf("Nome: ");
    scanf("%s",jog.p.nome);
    fflush(stdin);
    printf("Idade: ");
    scanf("%d",&jog.p.idade);
    fflush(stdin);
    printf("Classe: ");
    scanf("%s",jog.p.classe);
    fflush(stdin);
    printf("Nivel: ");
    scanf("%d",&jog.nivel);
    fflush(stdin);
    printf("Experiencia: ");
    scanf("%d",&jog.experiencia);
    fflush(stdin);

    //concluir o restante dos dados
   
    return jog;
}