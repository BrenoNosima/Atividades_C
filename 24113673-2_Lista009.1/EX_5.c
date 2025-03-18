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
int totuser = 0;
char emailArmazenado[MAX_USERS][50];
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
        printf("Limite de contas atingido!\n");
        return;
    }

    char email[50], senha[50], senhaConf[50], senhaCript[150];

    printf("Digite o seu email: ");
    scanf("%s", email);
    limpaEntrada();

    // Verificar se o e-mail já está cadastrado
    for (int i = 0; i < totuser; i++) {
        if (strcmp(email, emailArmazenado[i]) == 0) {
            printf("\nO email digitado já está cadastrado!\n");
            return;
        }
    }

    do {
        printf("Digite a sua senha: ");
        scanf("%s", senha);
        limpaEntrada();

        if (!senhaValida(senha)) {
            printf("\nSenha inválida! Exemplo: 'Usuario@123'\n\n");
        }

    } while (!senhaValida(senha));

    printf("Digite a sua senha novamente: ");
    scanf("%s", senhaConf);
    limpaEntrada();

    if (strcmp(senha, senhaConf) != 0) {
        printf("\nSenhas não conferem!\n");
        return;
    }

    criptografarASCII(senha, senhaCript);
    strcpy(emailArmazenado[totuser], email);
    strcpy(senhaArmazenada[totuser], senhaCript);
    totuser++;
    salvarOuCarregarArquivo(1);
    printf("\nConta criada com sucesso!\n");
}

void atualizarSenha() {
    char email[50], senha[50], senhaCript[150], novaSenha[50];

    printf("Digite o seu email para atualizar a senha: ");
    scanf("%s", email);
    limpaEntrada();
    printf("Digite a sua senha atual: ");
    scanf("%s", senha);
    limpaEntrada();
    criptografarASCII(senha, senhaCript);

    for (int i = 0; i < totuser; i++) {
        if (strcmp(email, emailArmazenado[i]) == 0 && strcmp(senhaCript, senhaArmazenada[i]) == 0) {
            do {
            printf("Digite a nova senha: ");
            scanf("%s", novaSenha);
            } while (!senhaValida(senha));
            limpaEntrada();
            criptografarASCII(novaSenha, senhaArmazenada[i]);
            salvarOuCarregarArquivo(1);
            printf("Senha atualizada com sucesso!\n");
            return;
        }
    }
    printf("Email ou senha incorreta.\n");
}

void deletarConta() {
    char email[50], senha[50], senhaCript[150];

    printf("Digite o seu email para excluir a conta: ");
    scanf("%s", email);
    limpaEntrada();
    printf("Digite a sua senha: ");
    scanf("%s", senha);
    limpaEntrada();
    criptografarASCII(senha, senhaCript);

    for (int i = 0; i < totuser; i++) {
        if (strcmp(email, emailArmazenado[i]) == 0 && strcmp(senhaCript, senhaArmazenada[i]) == 0) {
            for (int j = i; j < totuser - 1; j++) {
                strcpy(emailArmazenado[j], emailArmazenado[j + 1]);
                strcpy(senhaArmazenada[j], senhaArmazenada[j + 1]);
            }
            totuser--;
            salvarOuCarregarArquivo(1);
            printf("Conta excluída com sucesso!\n");
            return;
        }
    }
    printf("Conta não encontrada ou senha incorreta.\n");
}

void listarContas() {
    if (totuser == 0) {
        printf("Nenhuma conta cadastrada.\n");
        return;
    }

    char opcao;
    for (int i = 0; i < totuser; i++) {
        char senhaDescript[50];
        descriptografarASCII(senhaArmazenada[i], senhaDescript);

        printf("\nConta %d:\n", i + 1);
        printf("  Email: %s\n", emailArmazenado[i]);
        printf("  Senha (Descriptografada): %s\n", senhaDescript);

        printf("  Deseja ver a senha criptografada? (S/N): ");
        scanf(" %c", &opcao);
        limpaEntrada();

        if (toupper(opcao) == 'S') {
            printf("  Senha (Criptografada): %s\n", senhaArmazenada[i]);
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
        char buffer[5];
        strncpy(buffer, &input[i], 4);
        buffer[4] = '\0';
        
        // Convertemos de volta para inteiro e dividimos por 3
        output[i / 4] = (char)(atoi(buffer) / 3);
    }
    output[i / 4] = '\0';
}

void salvarOuCarregarArquivo(int tp) { // 0 - leitura / 1 - gravação
    FILE *file;

    if (tp == 0) {
        file = fopen("emailesenha.txt", "r");
        if (file != NULL) {
            totuser = 0;
            int x = 0;
            char linha[150];
            while (fgets(linha, sizeof(linha), file) != NULL && totuser < MAX_USERS) {
                linha[strlen(linha) - 1] = '\0'; // Remove o '\n' final
                if (x % 2 == 0) {
                    strcpy(emailArmazenado[totuser], linha);
                } else {
                    strcpy(senhaArmazenada[totuser], linha);
                    totuser++;
                }
                x++;
            }
            fclose(file);
        } else {
            printf("Erro ao abrir o arquivo para leitura.\n");
        }
    } else {
        file = fopen("emailesenha.txt", "w");
        if (file != NULL) {
            for (int i = 0; i < totuser; i++) {
                fprintf(file, "%s\n", emailArmazenado[i]);
                fprintf(file, "%s\n", senhaArmazenada[i]);
            }
            fclose(file);
        } else {
            printf("Erro ao abrir o arquivo para gravação.\n");
        }
    }
}

void ordenaUsuarios() {
    char tempUser[50], tempSenha[150];

    for (int i = 0; i < totuser - 1; i++) {
        for (int j = i + 1; j < totuser; j++) {
            if (strcmp(emailArmazenado[i], emailArmazenado[j]) > 0) {
                // Troca os emails
                strcpy(tempUser, emailArmazenado[i]);
                strcpy(emailArmazenado[i], emailArmazenado[j]);
                strcpy(emailArmazenado[j], tempUser);

                // Troca as senhas associadas
                strcpy(tempSenha, senhaArmazenada[i]);
                strcpy(senhaArmazenada[i], senhaArmazenada[j]);
                strcpy(senhaArmazenada[j], tempSenha);
            }
        }
    }
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