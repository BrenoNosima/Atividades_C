#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void limpaEntrada();
void criptografarASCII(const char *input, char *output);
void descriptografarASCII(const char *input, char *output);
void arquivo(int tp);
void listarContas();

int totuser = 0;
char emailArmazenado[15][50];
char senhaArmazenada[15][150];

int main() {
    // Carregar dados do arquivo
    arquivo(0);

    char acao;
    char email[50], senha[50], senhaConf[50], senhaCript[150], senhaDescript[50];
    int conferencia;

    do {
        printf("\nEscolha uma ação:\n");
        printf("C - Criar Conta\n");
        printf("E - Entrar\n");
        printf("A - Atualizar Senha\n");
        printf("D - Deletar Conta\n");
        printf("L - Listar Contas\n");
        printf("S - Sair\n");
        printf("Digite sua escolha: ");
        scanf(" %c", &acao);  // Adicionei espaço antes de %c para ignorar espaços ou quebras de linha

        switch (toupper(acao)) {
            case 'C':
                // Criação de Conta
                {
                printf("Digite o seu email: ");
                scanf("%s", email);

                int existe = 0;
                for (int i = 0; i < totuser; i++) {
                    if (strcmp(email, emailArmazenado[i]) == 0) {
                        printf("O email digitado já está cadastrado!\n");
                        existe = 1;
                        break;
                    }
                }
                if (existe) continue;

                printf("Digite a sua senha: ");
                scanf("%s", senha);
                printf("Digite a sua senha novamente: ");
                scanf("%s", senhaConf);

                conferencia = strcmp(senha, senhaConf);
                if (conferencia != 0) {
                    printf("Senhas não conferem!\n");
                    continue;
                }

                criptografarASCII(senha, senhaCript);
                strcpy(emailArmazenado[totuser], email);
                strcpy(senhaArmazenada[totuser], senhaCript);
                totuser++;
                arquivo(1);
                printf("Conta criada com sucesso!\n");
                break;
                }
            //case 'E':
                // Login
                {
                printf("Digite o seu email: ");
                scanf("%s", email);
                printf("Digite a sua senha: ");
                scanf("%s", senha);
                criptografarASCII(senha, senhaCript);

                int loginSucesso = 0;
                for (int i = 0; i < totuser; i++) {
                    if (strcmp(email, emailArmazenado[i]) == 0 && strcmp(senhaCript, senhaArmazenada[i]) == 0) {
                        loginSucesso = 1;
                        descriptografarASCII(senhaArmazenada[i], senhaDescript);
                        printf("Login realizado com sucesso!\n");
                        break;
                    }
                }
                if (!loginSucesso) printf("Email ou senha incorretos.\n");
                break;
              }
            case 'A':
                // Atualização de Senha
                {
                printf("Digite o seu email para atualizar a senha: ");
                scanf("%s", email);
                printf("Digite a sua senha atual: ");
                scanf("%s", senha);
                criptografarASCII(senha, senhaCript);

                int encontrado = 0;
                for (int i = 0; i < totuser; i++) {
                    if (strcmp(email, emailArmazenado[i]) == 0 && strcmp(senhaCript, senhaArmazenada[i]) == 0) {
                        printf("Digite a nova senha: ");
                        scanf("%s", senha);
                        criptografarASCII(senha, senhaArmazenada[i]);
                        arquivo(1);
                        printf("Senha atualizada com sucesso!\n");
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) printf("Conta não encontrada ou senha incorreta.\n");
                break;
             }
            case 'D' :
                // Exclusão de Conta
                {
                printf("Digite o seu email para excluir a conta: ");
                scanf("%s", email);
                printf("Digite a sua senha: ");
                scanf("%s", senha);
                criptografarASCII(senha, senhaCript);

                int indice = -1;
                for (int i = 0; i < totuser; i++) {
                    if (strcmp(email, emailArmazenado[i]) == 0 && strcmp(senhaCript, senhaArmazenada[i]) == 0) {
                        indice = i;
                        break;
                    }
                }
                if (indice == -1) {
                    printf("Conta não encontrada ou senha incorreta.\n");
                } else {
                    for (int i = indice; i < totuser - 1; i++) {
                        strcpy(emailArmazenado[i], emailArmazenado[i + 1]);
                        strcpy(senhaArmazenada[i], senhaArmazenada[i + 1]);
                    }
                    totuser--;
                    arquivo(1);
                    printf("Conta excluída com sucesso!\n");
                }
                break;
             }  
            case 'L':
                {   
                listarContas();
                break;
                }
            case 'S':
              {
                printf("Programa encerrado.\n");
                break;
              }
            default:
                printf("Opção inválida.\n");
                
        } //switch

    } while (toupper(acao) != 'S');

    return 0;
}

void listarContas() {
    char opcao;
    do {
        printf("\nLista de Contas Criadas:\n");
        for (int i = 0; i < totuser; i++) {
            char senhaDescript[50];
            descriptografarASCII(senhaArmazenada[i], senhaDescript);

            printf("Conta %d:\n", i + 1);
            printf("  Email: %s\n", emailArmazenado[i]);
            printf("  Senha (Descriptografada): %s\n", senhaDescript);

            printf("  Deseja ver a senha criptografada? (S/N): ");
            scanf(" %c", &opcao); // Espaço antes de %c para ignorar espaços ou quebras de linha

            if (toupper(opcao) == 'S') {
                printf("  Senha (Criptografada): %s\n", senhaArmazenada[i]);
            }
            printf("\n");
        }

        printf("Deseja voltar à tela inicial? (S/N): ");
        scanf(" %c", &opcao); // Espaço antes de %c para ignorar espaços ou quebras de linha

    } while (toupper(opcao) != 'S');
}

void limpaEntrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void criptografarASCII(const char *input, char *output) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        sprintf(&output[i * 3], "%03d", (unsigned char)input[i]);
    }
    output[i * 3] = '\0';
}

void descriptografarASCII(const char *input, char *output) {
    int i;
    for (i = 0; i < strlen(input); i += 3) {
        char buffer[4];
        strncpy(buffer, &input[i], 3);
        buffer[3] = '\0';
        output[i / 3] = (char)atoi(buffer);
    }
    output[i / 3] = '\0';
}

void arquivo(int tp){ //0 - leitura / 1 - gravacao
  char linha[15],tmp[15]; 
  int x;
  FILE *file; //associa vari�vel file em tipo FILE (palavra reservada que caracteriza fim de string)
    file = fopen("emailesenha.txt", "r"); //Associa file em "emailesenha.txt" e tenta abrir arquivo para leitura
    if (file != NULL && tp == 0) { //se n�o deu erro na abertura e o TIPO for igual a 0
        totuser=0;
        x=0;
        while (fgets(linha, sizeof(linha), file) != NULL && strlen(linha)>0) { 
          linha[strlen(linha)-1]='\0'; //coloca caracter null no fim da string (caracteriza fim)
            if (x%2==1){ //linha impar
              totuser++; //incrementa o total de usuarios no vetor
              //aplicar o procedimento ou func�o que descritografa se quiser
              strcpy(emailArmazenado[totuser-1],linha); //copia linha em nome[]
              }
            else //linha par
              //aplicar o procedimento ou func�o que descritografa se quiser
              strcpy(senhaArmazenada[totuser-1],linha); //copia linha em senha[]
              x++; //incrementa x. Cada vez que passar pela leitura da linha, ser� lido ou nome ou senha (linha impar / linha par)
            
        }
    }
    else{ //caso nao tenha aberto o arquivo para leitura ou o tipo seja diferente de zero
      file = fopen("NomeArq.txt", "w"); //Associa file em "NomeArq.txt" e cria o arquivo (mesmo que ele j� exista - sobrescrevendo-o)
        for (x=0;x<totuser;x++){ //la�o de 0 at� total de usuarios no Vetor-1
          strcpy(tmp,emailArmazenado[x]); //copia o nome[x] em tmp
          //aplicar a criptografa tmp (nome) se quiser
          fprintf(file, "%s\n", tmp); //grava no arquivo
          strcpy(tmp,senhaArmazenada[x]); //copia o nome[x] em tmp 
          //aplicar a criptografa tmp (senha) se quiser
          fprintf(file, "%s\n", tmp); //grava no arquivo o conte�do de tmp
        } 
   }
    fclose(file); //fecha arquivo
}

