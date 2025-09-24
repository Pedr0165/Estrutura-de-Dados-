#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *arquivo;               
    char nome[50];
    float nota;

    // 1) Abrindo arquivo para escrita ("w" sobrescreve se já existir)
    arquivo = fopen("notas.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return 1;
    }

    // 2) Coletando dados do usuário
    printf("DIGITE O NOME DO ALUNO: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite a nota do aluno: ");
    if (scanf("%f", &nota) != 1) {
        fprintf(stderr, "Entrada inválida\n");
        fclose(arquivo);
        return 1;
    }

    // 3) Gravando nome e nota no arquivo
    fprintf(arquivo, "Nome: %sNota: %.1f\n", nome, nota);
    fclose(arquivo); // Corrigido: faltava ponto e vírgula

    printf("\nDados gravados em 'notas.txt'\n");

    // 4) Abrindo arquivo para leitura ("r")
    arquivo = fopen("notas.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 1;
    }

    // 5) Lendo e exibindo o conteúdo
    char linha[100];
    printf("\n--- Conteúdo do arquivo ---\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo);

    return 0;
}
