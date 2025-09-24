#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 50
#define TAM_STR 100

typedef struct {
    char nome[TAM_STR];
    char curso[TAM_STR];
    float notas[3];
    float media;
} Aluno;

// --- Funções ---
void calcularMedia(Aluno *a) {
    float soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += a->notas[i];
    }
    a->media = soma / 3.0f;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void salvarCSV(Aluno alunos[], int n, const char *nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "w");
    if (!f) {
        perror("Erro ao abrir arquivo para escrita");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s;%s;%.2f;%.2f;%.2f;%.2f\n",
                alunos[i].nome,
                alunos[i].curso,
                alunos[i].notas[0],
                alunos[i].notas[1],
                alunos[i].notas[2],
                alunos[i].media);
    }

    fclose(f);
}

void imprimirCSV(const char *nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "r");
    if (!f) {
        perror("Erro ao abrir arquivo para leitura");
        exit(1);
    }

    char linha[200];
    printf("\n--- Conteúdo do boletim.csv ---\n");
    while (fgets(linha, sizeof(linha), f)) {
        printf("%s", linha);
    }
    fclose(f);
}

void buscarPorNome(Aluno alunos[], int n, const char *nomeBusca) {
    for (int i = 0; i < n; i++) {
        if (strcmp(alunos[i].nome, nomeBusca) == 0) {
            printf("\nAluno encontrado:\n");
            printf("Nome: %s\nCurso: %s\nNotas: %.2f, %.2f, %.2f\nMédia: %.2f\n",
                   alunos[i].nome, alunos[i].curso,
                   alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2],
                   alunos[i].media);
            return;
        }
    }
    printf("\nAluno '%s' não encontrado.\n", nomeBusca);
}

Aluno* encontrarMaiorMedia(Aluno *alunos, int n) {
    Aluno *melhor = alunos; // ponteiro para o primeiro
    for (int i = 1; i < n; i++) {
        if ((alunos + i)->media > melhor->media) {
            melhor = (alunos + i);
        }
    }
    return melhor;
}

// --- Programa Principal ---
int main() {
    int n;
    Aluno alunos[MAX_ALUNOS];

    printf("Quantos alunos deseja cadastrar (1-50)? ");
    scanf("%d", &n);
    limparBuffer();

    if (n < 1 || n > MAX_ALUNOS) {
        printf("Número inválido de alunos.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Cadastro do aluno %d ---\n", i + 1);

        printf("Nome: ");
        fgets(alunos[i].nome, TAM_STR, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;

        printf("Curso: ");
        fgets(alunos[i].curso, TAM_STR, stdin);
        alunos[i].curso[strcspn(alunos[i].curso, "\n")] = 0;

        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
        limparBuffer();

        calcularMedia(&alunos[i]);
    }

    // Grava no arquivo CSV
    salvarCSV(alunos, n, "boletim.csv");

    // Reabre e imprime
    imprimirCSV("boletim.csv");

    // Busca por nome
    char nomeBusca[TAM_STR];
    printf("\nDigite um nome para buscar: ");
    fgets(nomeBusca, TAM_STR, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;
    buscarPorNome(alunos, n, nomeBusca);

    // Maior média
    Aluno *top = encontrarMaiorMedia(alunos, n);
    printf("\nAluno com maior média:\n");
    printf("Nome: %s\nCurso: %s\nMédia: %.2f\n",
           top->nome, top->curso, top->media);

    return 0;
}
