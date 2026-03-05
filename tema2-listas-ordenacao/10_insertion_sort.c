#include <stdio.h>

void insertionSort(int vetor[], int tamanho) {
    for(int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        
        while(j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        
        vetor[j + 1] = chave;
    }
}

void insertionSortComEstatisticas(int vetor[], int tamanho, int *comparacoes, int *movimentos) {
    *comparacoes = 0;
    *movimentos = 0;
    
    for(int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        
        while(j >= 0) {
            (*comparacoes)++;
            if(vetor[j] > chave) {
                vetor[j + 1] = vetor[j];
                (*movimentos)++;
                j--;
            } else {
                break;
            }
        }
        
        vetor[j + 1] = chave;
        if(j + 1 != i) {
            (*movimentos)++;
        }
    }
}

void exibirVetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor1[] = {12, 11, 13, 5, 6};
    int tamanho = sizeof(vetor1) / sizeof(vetor1[0]);
    
    printf("Vetor original: ");
    exibirVetor(vetor1, tamanho);
    
    insertionSort(vetor1, tamanho);
    
    printf("Vetor ordenado: ");
    exibirVetor(vetor1, tamanho);
    
    int vetor2[] = {12, 11, 13, 5, 6};
    int comparacoes, movimentos;
    
    insertionSortComEstatisticas(vetor2, tamanho, &comparacoes, &movimentos);
    
    printf("\n=== Estatísticas ===\n");
    printf("Comparações: %d\n", comparacoes);
    printf("Movimentos: %d\n", movimentos);
    
    int vetor3[] = {1, 2, 3, 4, 5};
    int tamanho3 = sizeof(vetor3) / sizeof(vetor3[0]);
    
    printf("\n=== Melhor Caso (já ordenado) ===\n");
    printf("Vetor: ");
    exibirVetor(vetor3, tamanho3);
    
    insertionSortComEstatisticas(vetor3, tamanho3, &comparacoes, &movimentos);
    printf("Comparações: %d\n", comparacoes);
    printf("Movimentos: %d\n", movimentos);
    
    int vetor4[] = {5, 4, 3, 2, 1};
    int tamanho4 = sizeof(vetor4) / sizeof(vetor4[0]);
    
    printf("\n=== Pior Caso (ordem inversa) ===\n");
    printf("Vetor: ");
    exibirVetor(vetor4, tamanho4);
    
    insertionSortComEstatisticas(vetor4, tamanho4, &comparacoes, &movimentos);
    printf("Comparações: %d\n", comparacoes);
    printf("Movimentos: %d\n", movimentos);
    
    return 0;
}
