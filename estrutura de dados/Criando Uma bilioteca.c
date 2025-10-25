//==============================================================================
// Prática: Sistema de biblioteca - Parte 1
//
// OBJETIVO:
// Implementar o cadastro e a listagem de livros usando um array estático.
// Foco em structs, entrada/saída de dados e organização básica.
//==============================================================================

#include <stdio.h>
#include <string.h>  // Para strcspn()
#include <stdlib.h>  // Para funções utilitárias

//---- Constantes Globais ---- 
#define MAX_LIVROS 50
#define TAM_STRING 100

//---- Definição da estrutura (struct) ----
struct livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

//---- Limpa buffer de entrada ----
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//---- Função Principal ----
int main() {
    struct livro biblioteca[MAX_LIVROS];
    int totallivros = 0;
    int opcao;

    //---- Laço Principal do Menu ----
    do {
        // Exibe o menu de opções 
        printf("==============================\n");
        printf("   BIBLIOTECA - PARTE 1\n");
        printf("==============================\n");
        printf("1 - Cadastrar Livro\n");
        printf("2 - Listar Livros\n");
        printf("0 - Sair\n");
        printf("------------------------------\n");
        printf("Escolha uma opção: ");

        //---- Lê a opção do usuário ----
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf

        //---- Processamento da opção ----
        switch (opcao) {
            case 1: // Cadastro de Livro
                printf("---- Cadastro do Novo Livro ----\n");

                if (totallivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totallivros].nome, TAM_STRING, stdin);
                    biblioteca[totallivros].nome[strcspn(biblioteca[totallivros].nome, "\n")] = 0;

                    printf("Digite o nome do autor: ");
                    fgets(biblioteca[totallivros].autor, TAM_STRING, stdin);
                    biblioteca[totallivros].autor[strcspn(biblioteca[totallivros].autor, "\n")] = 0;

                    printf("Digite o nome da editora: ");
                    fgets(biblioteca[totallivros].editora, TAM_STRING, stdin);
                    biblioteca[totallivros].editora[strcspn(biblioteca[totallivros].editora, "\n")] = 0;

                    printf("Digite a edição do livro: ");
                    scanf("%d", &biblioteca[totallivros].edicao);
                    limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf

                    totallivros++;
                    printf("\nLivro cadastrado com sucesso!\n");
                } else {
                    printf("Capacidade máxima de livros atingida!\n");
                }

                printf("Pressione Enter para continuar...");
                getchar(); // Pausa para o usuário ler a mensagem
                break;

            case 2: // Listagem de Livros
                printf("---- Lista de Livros Cadastrados ----\n\n");
                if (totallivros == 0) {
                    printf("Nenhum livro cadastrado.\n");
                } else {
                    for (int i = 0; i < totallivros; i++) {
                        printf("Livro %d:\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edição: %d\n\n", biblioteca[i].edicao);
                    }
                }

                printf("Pressione Enter para continuar...");
                getchar();
                break;

            case 0: // Sair do programa 
                printf("Saindo do programa...\n");
                break;

            default: // Opção inválida
                printf("Opção inválida! Tente novamente.\n");
                printf("Pressione Enter para continuar...");
                getchar();
                break;
        }
    } while (opcao != 0);

    return 0;
}
