#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USUARIOS 10
#define TAM_MAX_SENHA 10

typedef struct {
    char nome[50];
    char senha[TAM_MAX_SENHA];
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int numUsuarios = 0;

// Fun��o para gerar uma senha aleat�ria
void gerarSenha(char senha[], int tamanho) {
    const char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    int i;
    for (i = 0; i < tamanho - 1; i++) {
        senha[i] = caracteres[rand() % (sizeof(caracteres) - 1)];
    }
    senha[i] = '\0';
}

// Fun��o para verificar se uma senha � segura
int senhaSegura(char senha[]) {
    int temLetra = 0, temNumero = 0, temEspecial = 0;
    for (int i = 0; senha[i] != '\0'; i++) {
        if (isalpha(senha[i])) {
            temLetra = 1;
        } else if (isdigit(senha[i])) {
            temNumero = 1;
        } else {
            temEspecial = 1;
        }
    }
    return temLetra && temNumero && temEspecial;
}

// Fun��o para adicionar um usu�rio
void adicionarUsuario() {
    if (numUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuarios atingido.\n");
        return;
    }

    printf("Digite o nome do usuario: ");
    scanf(" %[^\n]", usuarios[numUsuarios].nome);
    char novaSenha[TAM_MAX_SENHA];
    do {
        gerarSenha(novaSenha, TAM_MAX_SENHA);
    } while (!senhaSegura(novaSenha));
    strcpy(usuarios[numUsuarios].senha, novaSenha);

    numUsuarios++;
    printf("Usuario adicionado com sucesso.\n");
}

// Fun��o para visualizar todos os usu�rios
void visualizarUsuarios() {
    printf("Usuarios cadastrados:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("Nome: %s, Senha: %s\n", usuarios[i].nome, usuarios[i].senha);
    }
}

// Fun��o para editar a senha de um usu�rio
void editarSenha() {
    char nomeUsuario[50];
    printf("Digite o nome do usuario para editar a senha: ");
    scanf(" %[^\n]", nomeUsuario);

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].nome, nomeUsuario) == 0) {
            char novaSenha[TAM_MAX_SENHA];
            do {
                gerarSenha(novaSenha, TAM_MAX_SENHA);
            } while (!senhaSegura(novaSenha));
            strcpy(usuarios[i].senha, novaSenha);
            printf("Senha editada com sucesso.\n");
            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

// Fun��o para excluir um usu�rio
void excluirUsuario() {
    char nomeUsuario[50];
    printf("Digite o nome do usuario para excluir: ");
    scanf(" %[^\n]", nomeUsuario);

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].nome, nomeUsuario) == 0) {
            for (int j = i; j < numUsuarios - 1; j++) {
                strcpy(usuarios[j].nome, usuarios[j + 1].nome);
                strcpy(usuarios[j].senha, usuarios[j + 1].senha);
            }
            numUsuarios--;
            printf("Usuario deletado.\n");
            return;
        }
    }

    printf("Usuario n�o encontrado.\n");
}

int main() {
    printf("Sistema de cadastro de usuario\n");
	int opcao;
    do {
        printf("\nEscolha uma opcao:\n");
		printf("1. Adicionar usuario\n");
        printf("2. Visualizar usuarios\n");
        printf("3. Editar senha\n");
        printf("4. Excluir usuario\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarUsuario();
                break;
            case 2:
                visualizarUsuarios();
                break;
            case 3:
                editarSenha();
                break;
            case 4:
                excluirUsuario();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

