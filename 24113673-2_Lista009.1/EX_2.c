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

void limpaTela() {
    system("clear || cls");
}

void pausa() {
    printf("Pressione ENTER para voltar ao menu.");
    getchar();
    getchar();
}

// Fun��es de criptografia
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

// Fun��o para salvar usu�rios no arquivo
void salvarUsuarios() {
    FILE *file = fopen("usuarios.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }

    for (int i = 0; i < totuser; i++) {
        // Criptografamos o nome e a senha antes de salvar
        char cripNome[MAX_LENGTH], cripSenha[MAX_LENGTH];
        strcpy(cripNome, usuarios[i].nome);
        strcpy(cripSenha, usuarios[i].senha);
        crip2(cripNome);
        crip2(cripSenha);

        fprintf(file, "%s %s\n", cripNome, cripSenha);
    }
    fclose(file);
}

// Fun��o para carregar usu�rios do arquivo
void carregarUsuarios() {
    FILE *file = fopen("usuarios.txt", "r");
    if (file == NULL) {
        printf("Nenhum arquivo de dados encontrado. Continuando sem carregar usu�rios.\n");
        return;
    }

    totuser = 0;
    while (fscanf(file, "%s %s", usuarios[totuser].nome, usuarios[totuser].senha) != EOF) {
        // Descriptografamos o nome e a senha ap�s carregar
        descrip2(usuarios[totuser].nome);
        descrip2(usuarios[totuser].senha);
        totuser++;
    }
    fclose(file);
}

// Fun��es principais de gerenciamento
int buscaUsuario(char *chave) {
    for (int i = 0; i < totuser; i++) {
        if (strcmp(usuarios[i].nome, chave) == 0) {
            return i;
        }
    }
    return -1;
}

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

void inserir() {
    limpaTela();
    printf("I N S E R I R\n");

    if (totuser >= MAX_USERS) {
        printf("Limite de usu�rios atingido!\n");
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
    salvarUsuarios();  // Salva ao inserir
    printf("Usu�rio cadastrado com sucesso!\n");
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
        printf("Usu�rio n�o encontrado!\n");
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
    salvarUsuarios();  // Salva ao alterar
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
        printf("Usu�rio n�o encontrado!\n");
        pausa();
        return;
    }

    printf("Confirma exclus�o? (S/N): ");
    scanf(" %c", &confirmacao);
    if (toupper(confirmacao) == 'S') {
        for (int i = pos; i < totuser - 1; i++) {
            usuarios[i] = usuarios[i + 1];
        }
        totuser--;
        salvarUsuarios();  // Salva ao excluir
        printf("Usu�rio exclu�do com sucesso!\n");
    }
    pausa();
}


void listar2() {
    int tipo;
    printf("Escolha uma op��o de listagem:\n");
    printf("0 - Listar apenas os nomes dos usu�rios\n");
    printf("1 - Listar nomes com senhas descriptografadas\n");
    printf("2 - Criptografar todas as senhas e listar\n");
    printf("Op��o: ");
    scanf("%d", &tipo);

    // Limpa a tela para exibir o resultado da escolha
    system("clear || cls");
    printf("---------------------------------------------------------\n");
    printf("Usu�rio         Senha\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < totuser; i++) {
        if (tipo == 0) {
            // Exibir apenas o nome do usu�rio
            printf("%-15s\n", usuarios[i].nome);
        } else if (tipo == 1) {
            // Descriptografar temporariamente para exibir
            descrip2(usuarios[i].senha);
            printf("%-15s %s\n", usuarios[i].nome, usuarios[i].senha);
            crip2(usuarios[i].senha); // Recriptografa para manter o estado original
        } else if (tipo == 2) {
            // Criptografa todas as senhas e exibe
            crip2(usuarios[i].senha);
            printf("%-15s %s\n", usuarios[i].nome, usuarios[i].senha);
        } else {
            printf("Op��o inv�lida! Por favor, escolha 0, 1 ou 2.\n");
            return;
        }
    }

    printf("---------------------------------------------------------\n");
    printf("Listagem conclu�da.\n");
}
void listar(int tipo) {
    limpaTela();
    printf("---------------------------------------------------------\n");
    printf("Usu�rio         Senha\n");
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
    printf("Programa desenvolvido pelo professor Alexandre Moreno.\n");
    printf("Exemplo que contempla requisitos pr�ticos da AEP.\n");
    pausa();
}

void menu() {
    char op;
    do {
        setlocale(LC_ALL, "Portuguese_Brazil");
        limpaTela();
        printf("M E N U\n");
        printf("1 - Inserir\n");
        printf("2 - Alterar\n");
        printf("3 - Excluir\n");
        printf("4 - Listar (Usu�rios)\n");
        printf("5 - Cr�ditos\n");
        printf("6 - Fim\n");
        printf("Op��o: ");
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
                listar(0);
                break;
            case '5':
                creditos();
                break;
            case '7':
                listar2();
                break;
            case '6':
                break;
            default:
                printf("Op��o inv�lida!\n");
                pausa();
        }
    } while (op != '6');
}

int main() {
    carregarUsuarios();
    menu();
    return 0;
}
