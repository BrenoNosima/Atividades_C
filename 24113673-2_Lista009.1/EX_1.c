#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_USERS 20
#define MAX_LENGTH 20


typedef struct {
    char nome[MAX_LENGTH];
    char senha[MAX_LENGTH];
} Usuario;

Usuario usuarios[MAX_USERS];
int totuser = 0;

// Funções de utilidade
void limpaTela() {
    system("clear || cls");
}

void tempox(int t) {
    for (int i = 0; i < t; i++);
}

void pausa() {
    printf("Pressione ENTER para voltar ao menu.");
    getchar();
    getchar();
}

// Funções de criptografia
void crip2(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = s[i] + i;
    }
}

void descrip2(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = s[i] - i;
    }
}

// Função de busca de usuário
int buscaUsuario(char *chave) {
    for (int i = 0; i < totuser; i++) {
        if (strcmp(usuarios[i].nome, chave) == 0) {
            return i;
        }
    }
    return -1;
}

// Função de validação de senha
int senhaValida(char *s) {
    int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0;
    if (strlen(s) >= 8 && strlen(s) <= 20) v1 = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i])) v2 = 1;
        if (islower(s[i])) v3 = 1;
        if (isdigit(s[i])) v4 = 1;
        if (ispunct(s[i])) v5 = 1;
    }
    return v1 && v2 && v3 && v4 && v5;
}

// Procedimentos principais
void inserir() {
    limpaTela();
    printf("I N S E R I R\n");

    if (totuser >= MAX_USERS) {
        printf("Limite de usuários atingido!\n");
        pausa();
        return;
    }

    char nome[MAX_LENGTH];
    char senha[MAX_LENGTH], senha2[MAX_LENGTH];

    do {
        printf("Nome do Usuario: ");
        scanf("%s", nome);
    } while (buscaUsuario(nome) != -1 || strlen(nome) < 3);

    do {
        printf("Senha: ");
        scanf("%s", senha);
    } while (!senhaValida(senha));

    do {
        printf("Repita a Senha: ");
        scanf("%s", senha2);
    } while (strcmp(senha, senha2) != 0);

    strcpy(usuarios[totuser].nome, nome);
    strcpy(usuarios[totuser].senha, senha);
    totuser++;
    printf("Usuário cadastrado com sucesso!\n");
    pausa();
}

void alterar() {
    limpaTela();
    printf("A L T E R A R\n");

    char nome[MAX_LENGTH], senha[MAX_LENGTH], senha2[MAX_LENGTH];
    printf("Nome do Usuario: ");
    scanf("%s", nome);

    int pos = buscaUsuario(nome);
    if (pos == -1) {
        printf("Usuário não encontrado!\n");
        pausa();
        return;
    }

    do {
        printf("Nova Senha: ");
        scanf("%s", senha);
    } while (!senhaValida(senha));

    do {
        printf("Repita a Senha: ");
        scanf("%s", senha2);
    } while (strcmp(senha, senha2) != 0);

    strcpy(usuarios[pos].senha, senha);
    printf("Senha alterada com sucesso!\n");
    pausa();
}

void excluir() {
    limpaTela();
    printf("E X C L U I R\n");

    char nome[MAX_LENGTH], confirmacao;
    printf("Nome do Usuario: ");
    scanf("%s", nome);

    int pos = buscaUsuario(nome);
    if (pos == -1) {
        printf("Usuário não encontrado!\n");
        pausa();
        return;
    }

    printf("Confirma exclusão? (S/N): ");
    scanf(" %c", &confirmacao);
    if (toupper(confirmacao) == 'S') {
        for (int i = pos; i < totuser - 1; i++) {
            usuarios[i] = usuarios[i + 1];
        }
        totuser--;
        printf("Usuário excluído com sucesso!\n");
    }
    pausa();
}

void listar(int tipo) {
    limpaTela();
    printf("---------------------------------------------------------\n");
    printf("Usuário         Senha\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < totuser; i++) {
        if (tipo == 0) {
            printf("%-15s\n", usuarios[i].nome);
        } else if (tipo == 1) {
            char cripNome[MAX_LENGTH], cripSenha[MAX_LENGTH];
            strcpy(cripNome, usuarios[i].nome);
            strcpy(cripSenha, usuarios[i].senha);
            crip2(cripNome);
            crip2(cripSenha);
            printf("%-15s %s\n", cripNome, cripSenha);
        } else if (tipo == 2) {
            printf("%-15s %s\n", usuarios[i].nome, usuarios[i].senha);
        }
    }
    printf("---------------------------------------------------------\n");
    pausa();
}

void creditos() {
    limpaTela();
    printf("Programa desenvolvido pelos alunos, Breno, Henrrque, Gustavo e Felipe.\n");
    printf("Cripitografia funcional para a resolução do problema da AEP.\n");
    pausa();
}

void menu() {
    char op;
    setlocale(LC_ALL, "Portuguese_Brazil");
    do {
        limpaTela();
        printf("M E N U\n");
        printf("1 - Inserir\n");
        printf("2 - Alterar\n");
        printf("3 - Excluir\n");
        printf("4 - Listar (Usuários)\n");
        printf("5 - Créditos\n");
        printf("6 - Fim\n");
        printf("Opção: ");
        scanf(" %c", &op);

        switch (op) {
            case '1':
                inserir();
                break;
            case '2':
                alterar();
                break;
            case '3':
                excluir();
                break;
            case '4':
                listar(1);
                break;
            case '5':
                creditos();
                break;
            case '6':
                break;
            default:
                printf("Opção inválida!\n");
                pausa();
        }
    } while (op != '6');
}

int main() {
    menu();
    return 0;
}
