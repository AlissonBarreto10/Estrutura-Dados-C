#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno;

int main() {
    Aluno aluno1;
    
    strcpy(aluno1.nome, "João Silva");
    aluno1.idade = 20;
    aluno1.media = 8.5;
    
    printf("Nome: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Média: %.2f\n", aluno1.media);
    
    Aluno turma[3];
    
    for(int i = 0; i < 3; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]", turma[i].nome);
        printf("Idade: ");
        scanf("%d", &turma[i].idade);
        printf("Média: ");
        scanf("%f", &turma[i].media);
    }
    
    printf("\n=== LISTA DE ALUNOS ===\n");
    for(int i = 0; i < 3; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Nome: %s\n", turma[i].nome);
        printf("Idade: %d\n", turma[i].idade);
        printf("Média: %.2f\n", turma[i].media);
    }
    
    return 0;
}
