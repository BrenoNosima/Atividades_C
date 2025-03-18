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
        printf("C - Criar Conta\n");
        printf("A - Atualizar Senha\n");
        printf("D - Deletar Conta\n");
        printf("L - Listar Contas\n");
        printf("S - Sair\n");
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
            case 'S':
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção Inválida.\n");
        }

    } while (toupper(acao) != 'S');

    return 0;
}

void criarConta() {
    if (totuser >= MAX_USERS) {
        printf("  Limite de contas atingido!\n");
        return;
    }

    char usuario[50], senha[50], senhaConf[50], senhaCript[150];

    printf("  Digite o seu usuario: ");
    scanf("%s", usuario);
    limpaEntrada();

    // Verificar se o e-mail já está cadastrado
    for (int i = 0; i < totuser; i++) {
        if (strcmp(usuario, usuarioArmazenado[i]) == 0) {
            printf("\n  O usuario digitado já está cadastrado!\n");
            return;
        }
    }

    do {
        printf("  Digite a sua senha: ");
        scanf("%s", senha);
        limpaEntrada();

        if (!senhaValida(senha)) {
            printf("\n  Senha inválida! Exemplo: 'Usuario@123'\n\n");
        }

    } while (!senhaValida(senha));

    printf("  Digite a sua senha novamente: ");
    scanf("%s", senhaConf);
    limpaEntrada();

    if (strcmp(senha, senhaConf) != 0) {
        printf("\n  Senhas não conferem!\n");
        return;
    }

    criptografarASCII(senha, senhaCript);
    strcpy(usuarioArmazenado[totuser], usuario);
    strcpy(senhaArmazenada[totuser], senhaCript);
    totuser++;
    salvarOuCarregarArquivo(1);
    printf("\n  Conta criada com sucesso!\n");
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
                   limpaEntrada();
                } while (!senhaValida(novaSenha));

                criptografarASCII(novaSenha, senhaArmazenada[i]);
                salvarOuCarregarArquivo(1);
                printf("  Senha atualizada com sucesso!\n");
                return;
            }
        }
        printf("  Usuario ou senha incorreta.\n");

    } else {
        printf("  Digite a senha de administrador: ");
        fgets(confereSenhaAdmin, sizeof(confereSenhaAdmin), stdin);
        confereSenhaAdmin[strcspn(confereSenhaAdmin, "\n")] = '\0';

        if (strcmp(SENHA_ADMIN, confereSenhaAdmin) != 0){
            printf("\n  Senha incorreta!\n");
        } else {
            isAdmin = 1;
            atualizarSenha();
        }
    }
}

void deletarConta() {
    char usuario[50], senha[50], senhaCript[150], confereSenhaAdmin[50];

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
                for (int j = i; j < totuser - 1; j++) {
                    strcpy(usuarioArmazenado[j], usuarioArmazenado[j + 1]);
                    strcpy(senhaArmazenada[j], senhaArmazenada[j + 1]);
                }
                totuser--;
                salvarOuCarregarArquivo(1);
                printf("  Conta excluída com sucesso!\n");
                return;
            }
        }
        printf("  Conta não encontrada ou senha incorreta.\n");

    } else {
        printf("  Digite a senha de administrador: ");
        fgets(confereSenhaAdmin, sizeof(confereSenhaAdmin), stdin);
        confereSenhaAdmin[strcspn(confereSenhaAdmin, "\n")] = '\0';

        if (strcmp(SENHA_ADMIN, confereSenhaAdmin) != 0){
            printf("\n  Senha incorreta!\n");
        } else {
            isAdmin = 1;
            deletarConta();
        }
    }
}

void listarContas() {
    if (totuser == 0) {
        printf("  Nenhuma conta cadastrada.\n");
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

        printf("  Deseja ver a senha descriptografada? (S/N): ");
        scanf(" %c", &opcao);
        limpaEntrada();

        if (toupper(opcao) == 'S') {
            if(!isAdmin){
                printf("  Digite a senha de administrador: ");
                fgets(confereSenhaAdmin, sizeof(confereSenhaAdmin), stdin);
                confereSenhaAdmin[strcspn(confereSenhaAdmin, "\n")] = '\0';

                if(strcmp(confereSenhaAdmin, SENHA_ADMIN) == 0){
                    isAdmin = 1;
                    printf("  Senha (Descriptografada): %s\n", senhaDescript);
                } else {
                    printf("\n  Senha incorreta!\n");
                }

            } else {
                printf("  Senha (Descriptografada): %s\n", senhaDescript);
            }
        }
    }
}

void limpaEntrada() {
    while (getchar() != '\n');
}

void criptografarASCII(const char *input, char *output) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        // Multiplicamos o valor ASCII por 3 antes de converter para string
        sprintf(&output[i * 4], "%04d", (unsigned char)input[i] * 3);
    }
    output[i * 4] = '\0';
}

void descriptografarASCII(const char *input, char *output) {
    int i;
    for (i = 0; i < strlen(input); i += 4) {
        char temp[5];
        strncpy(temp, &input[i], 4);
        temp[4] = '\0';
        output[i / 4] = (char)(atoi(temp) / 3);
    }
    output[i / 4] = '\0';
}

void salvarOuCarregarArquivo(int tp) {
    FILE *arquivo;
    if (tp == 0) {
        arquivo = fopen("contas.txt", "r");
        if (arquivo != NULL) {
            while (fscanf(arquivo, "%s %s", usuarioArmazenado[totuser], senhaArmazenada[totuser]) != EOF) {
                totuser++;
            }
            fclose(arquivo);
        }
    } else {
        arquivo = fopen("contas.txt", "w");
        if (arquivo != NULL) {
            for (int i = 0; i < totuser; i++) {
                fprintf(arquivo, "%s %s\n", usuarioArmazenado[i], senhaArmazenada[i]);
            }
            fclose(arquivo);
        }
    }
}

void ordenaUsuarios() {
    // Função para ordenação dos usuarios
    for (int i = 0; i < totuser - 1; i++) {
        for (int j = i + 1; j < totuser; j++) {
            if (strcmp(usuarioArmazenado[i], usuarioArmazenado[j]) > 0) {
                char tempUser[50], tempSenha[150];
                strcpy(tempUser, usuarioArmazenado[i]);
                strcpy(usuarioArmazenado[i], usuarioArmazenado[j]);
                strcpy(usuarioArmazenado[j], tempUser);

                strcpy(tempSenha, senhaArmazenada[i]);
                strcpy(senhaArmazenada[i], senhaArmazenada[j]);
                strcpy(senhaArmazenada[j], tempSenha);
            }
        }
    }
}

int senhaValida(char *s) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i])) hasUpper = 1;
        if (islower(s[i])) hasLower = 1;
        if (isdigit(s[i])) hasDigit = 1;
        if (ispunct(s[i])) hasSpecial = 1;
    }

    return (hasUpper && hasLower && hasDigit && hasSpecial);
}
