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
    int nivel; // N�vel do jogador no jogo Ex: 12
    int experiencia; // Pontua��o de experi�ncia Ex: 890
    personagem p; // Dados do personagem
} jogador;
//------------------------------------------------------------------------------
typedef struct apelido {
    jogador jog; //jog � uma vari�vel do tipo jogador
    struct apelido *proximo; //*proximo � um ponteiro do n�
} no;
//------------------------------------------------------------------------------
no *topo = NULL; //topo � ponteiro que indica o TOPO da pilha

void push(jogador j);     // procedimento Empilhar
void pop();               // procedimento Desempilhar
void mostra_pilha();      // procedimento Imprimir pilha
void liberar_pilha();     // procedimento Limpar mem�ria
jogador entrada_dados();  // fun��o Entrada de dados que retorna dados do jogador

//-------------------------------------------
int main() {
    setlocale(LC_ALL, ""); //ativa teclado padr�o do windows
    int opcao; //op��o para o MENU
    jogador dados; //dados � uma vari�vel do tipo jogador
    do {
        printf("\nMenu - Pilha de Jogadores");
        printf("\n1. Empilhar Jogador");
        printf("\n2. Desempilhar Jogador");
        printf("\n3. Apresenta Pilha");
        printf("\n4. Limpar Mem�ria");
        printf("\n5. Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        fflush(stdin); // limpa buffer do teclado

        switch (opcao) {
            case 1:
                dados = entrada_dados(); //vari�vel dados recebe informacoes do jogador
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
                printf("Op��o inv�lida");
        }
    } while (opcao != 5);
    liberar_pilha(); // limpeza final
    printf("\nFim do programa.\n");
    system("pause");
    return 0;
}
//-------------------------------------------
void push(jogador j) {
    no *novo = malloc(sizeof(no)); //aloca mem�ria para o novo n�
    if(novo) {
        novo->jog = j; //atribui os dados do jogador ao novo n�
        novo->proximo = topo; //o pr�ximo do novo n� � o topo atual
        topo = novo; //atualiza o topo para o novo n�
    } else {
        printf("Erro ao alocar mem�ria!\n");
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
        temp = topo; // armazena o n� atual
        topo = topo->proximo; // move o topo para o pr�ximo n�
        free(temp); // libera a mem�ria do n� atual
    }
    printf("\nMem�ria liberada com sucesso.\n");
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