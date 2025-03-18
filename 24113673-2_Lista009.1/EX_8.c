#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void limpaEntrada();
void criptografarASCII(const char *input, char *output);
void descriptografarASCII(const char *input, char *output);
void salvarOuCarregarArquivo(int tp);
void listarContas();
void criarConta();
void atualizarSenha();
void deletarConta();
void ordenaUsuarios();
int senhaValida(char *s);
void exibirAjuda();

#define MAX_USERS 15
#define SENHA_ADMIN "Admin@2201"
int totuser = 0;
int isAdmin = 0; 
char usuarioArmazenado[MAX_USERS][50];
char senhaArmazenada[MAX_USERS][150];

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Carregar dados do arquivo
    salvarOuCarregarArquivo(0);

    char acao;

    do {
        printf("\nEscolha uma ação:\n");
        printf("C - Criar Conta: Crie uma nova conta de usuário\n");
        printf("A - Atualizar Senha: Altere a senha de sua conta\n");
        printf("D - Deletar Conta: Exclua uma conta de usuário\n");
        printf("L - Listar Contas: Veja uma lista de todas as contas cadastradas\n");
        printf("H - Ajuda: Exibe informações sobre o uso do sistema\n");
        printf("S - Sair: Encerre o programa\n");
        printf("Digite sua escolha: ");
        scanf(" %c", &acao);
        limpaEntrada();

        switch (toupper(acao)) {
            case 'C':
                criarConta();
                break;
            case 'A':
                atualizarSenha();
                break;
            case 'D':
                deletarConta();
                break;
            case 'L':
                ordenaUsuarios();
                listarContas();
                break;
            case 'H':
                exibirAjuda();
                break;
            case 'S':
                printf("\033[1;32mPrograma encerrado.\n\033[0m");
                break;
            default:
                printf("\033[1;31mOpção Inválida.\n\033[0m");
        }

    } while (toupper(acao) != 'S');

    return 0;
}

void exibirAjuda() {
    printf("\nComandos:\n");
    printf("  C: Criar uma nova conta.\n");
    printf("  A: Atualizar a senha de uma conta.\n");
    printf("  D: Excluir uma conta.\n");
    printf("  L: Listar todas as contas cadastradas.\n");
    printf("  H: Exibir esta ajuda.\n");
    printf("  S: Sair do programa.\n");
}

void criarConta() {
    if (totuser >= MAX_USERS) {
        printf("\033[1;31mLimite de contas atingido!\033[0m\n");
        return;
    }

    char usuario[50], senha[50], senhaConf[50], senhaCript[150];

    printf("  Digite o seu usuario: ");
    scanf("%s", usuario);
    limpaEntrada();

    // Verificar se o e-mail já está cadastrado
    for (int i = 0; i < totuser; i++) {
        if (strcmp(usuario, usuarioArmazenado[i]) == 0) {
            printf("\n\033[1;31mO usuario digitado já está cadastrado!\033[0m\n");
            return;
        }
    }

    do {
        printf("  Digite a sua senha: ");
        scanf("%s", senha);
        limpaEntrada();

        if (!senhaValida(senha)) {
            printf("\n  \033[1;31mSenha inválida! Exemplo: 'Usuario@123'\033[0m\n\n");
        }

    } while (!senhaValida(senha));

    printf("  Digite a sua senha novamente: ");
    scanf("%s", senhaConf);
    limpaEntrada();

    if (strcmp(senha, senhaConf) != 0) {
        printf("\n\033[1;31mSenhas não conferem!\033[0m\n");
        return;
    }

    criptografarASCII(senha, senhaCript);
    strcpy(usuarioArmazenado[totuser], usuario);
    strcpy(senhaArmazenada[totuser], senhaCript);
    totuser++;
    salvarOuCarregarArquivo(1);
    printf("\033[1;32mConta criada com sucesso!\033[0m\n");
}

void atualizarSenha() {
    char usuario[50], senha[50], senhaCript[150], novaSenha[50], confereSenhaAdmin[50];

    if(isAdmin){

        printf("  Digite o seu usuario para atualizar a senha: ");
        scanf("%s", usuario);
        limpaEntrada();
        printf("  Digite a sua senha atual: ");
        scanf("%s", senha);
        limpaEntrada();
        criptografarASCII(senha, senhaCript);

        for (int i = 0; i < totuser; i++) {
            if (strcmp(usuario, usuarioArmazenado[i]) == 0 && strcmp(senhaCript, senhaArmazenada[i]) == 0) {
                do {
                   printf("  Digite a nova senha: ");
                   scanf("%s", novaSenha);
                } while (!senhaValida(novaSenha));
                limpaEntrada();
                criptografarASCII(novaSenha, senhaArmazenada[i]);
                salvarOuCarregarArquivo(1);
                printf("\033[1;32mSenha atualizada com sucesso!\033[0m\n");
                return;
            }
        }
        printf("\033[1;31mUsuario ou senha incorreta.\033[0m\n");

    } else {

        printf("  Digite a senha de administrador: ");
        fgets(confereSenhaAdmin, sizeof(confereSenhaAdmin), stdin);
        confereSenhaAdmin[strcspn(confereSenhaAdmin, "\n")] = '\0';     

        if (strcmp(SENHA_ADMIN, confereSenhaAdmin) != 0){
            printf("\n\033[1;31mSenha incorreta!\033[0m\n");
        } else {
            isAdmin = 1;
            atualizarSenha();
        }

    }
}

void deletarConta() {
    char usuario[50], senha[50], senhaCript[150], confereSenhaAdmin[50];
    char confirmacao;

    if(isAdmin){

        printf("  Digite o seu usuario para excluir a conta: ");
        scanf("%s", usuario);
        limpaEntrada();
        printf("  Digite a sua senha: ");
        scanf("%s", senha);
        limpaEntrada();
        criptografarASCII(senha, senhaCript);

        for (int i = 0; i < totuser; i++) {
            if (strcmp(usuario, usuarioArmazenado[i]) == 0 && strcmp(senhaCript, senhaArmazenada[i]) == 0) {
                printf("  Tem certeza de que deseja excluir sua conta? (S/N): ");
                scanf(" %c", &confirmacao);
                limpaEntrada();
                if (toupper(confirmacao) != 'S') {
                    printf("  Exclusão cancelada.\n");
                    return;
                }
                for (int j = i; j < totuser - 1; j++) {
                    strcpy(usuarioArmazenado[j], usuarioArmazenado[j + 1]);
                    strcpy(senhaArmazenada[j], senhaArmazenada[j + 1]);
                }
                totuser--;
                salvarOuCarregarArquivo(1);
                printf("\033[1;32mConta excluída com sucesso!\033[0m\n");
                return;
            }
        }
        printf("\033[1;31mConta não encontrada ou senha incorreta.\033[0m\n");

    } else {

        printf("  Digite a senha de administrador: ");
        fgets(confereSenhaAdmin, sizeof(confereSenhaAdmin), stdin);
        confereSenhaAdmin[strcspn(confereSenhaAdmin, "\n")] = '\0';     

        if (strcmp(SENHA_ADMIN, confereSenhaAdmin) != 0){
            printf("\n\033[1;31mSenha incorreta!\033[0m\n");
        } else {
            isAdmin = 1;
            deletarConta();
        }

    }
}

void listarContas() {
    if (totuser == 0) {
        printf("\033[1;31mNenhuma conta cadastrada.\033[0m\n");
        return;
    }

    char confereSenhaAdmin[50];
    char opcao;
    for (int i = 0; i < totuser; i++) {
        char senhaDescript[50];
        descriptografarASCII(senhaArmazenada[i], senhaDescript);

        printf("\nConta %d:\n", i + 1);
        printf("  Usuario: %s\n", usuarioArmazenado[i]);
        printf("  Senha (Criptografada): %s\n", senhaArmazenada[i]);
    }
}

void salvaOuCarregarArquivo(int tp) {
    FILE *arq;
    if (tp == 0) {
        arq = fopen("contas.txt", "r");
        if (arq == NULL) {
            printf("Arquivo não encontrado.\n");
            return;
        }

        while (fscanf(arq, "%s %s", usuarioArmazenado[totuser], senhaArmazenada[totuser]) != EOF) {
            totuser++;
        }
        fclose(arq);
    } else {
        arq = fopen("contas.txt", "w");
        if (arq == NULL) {
            printf("Erro ao salvar dados.\n");
            return;
        }

        for (int i = 0; i < totuser; i++) {
            fprintf(arq, "%s %s\n", usuarioArmazenado[i], senhaArmazenada[i]);
        }
        fclose(arq);
    }
}

void criptografarASCII(const char *input, char *output) {
    while (*input) {
        *output = *input + 3;  // Exemplo simples de criptografia
        input++;
        output++;
    }
    *output = '\0';
}

void descriptografarASCII(const char *input, char *output) {
    while (*input) {
        *output = *input - 3;  // Desfaz a criptografia
        input++;
        output++;
    }
    *output = '\0';
}

int senhaValida(char *s) {
    int maiuscula = 0, minuscula = 0, numero = 0, especial = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i])) maiuscula = 1;
        if (islower(s[i])) minuscula = 1;
        if (isdigit(s[i])) numero = 1;
        if (strchr("!@#$%^&*()", s[i])) especial = 1;
    }

    return maiuscula && minuscula && numero && especial;
}

void limpaEntrada() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
