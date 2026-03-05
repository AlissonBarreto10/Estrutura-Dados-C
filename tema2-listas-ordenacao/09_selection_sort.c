#include <stdio.h>

void selectionSort(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho - 1; i++) {
        int indice_minimo = i;
        
        for(int j = i + 1; j < tamanho; j++) {
            if(vetor[j] < vetor[indice_minimo]) {
                indice_minimo = j;
            }
        }
        
        if(indice_minimo != i) {
            int temp = vetor[i];
            vetor[i] = vetor[indice_minimo];
            vetor[indice_minimo] = temp;
        }
    }
}

void selectionSortComEstatisticas(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    
    for(int i = 0; i < tamanho - 1; i++) {
        int indice_minimo = i;
        
        for(int j = i + 1; j < tamanho; j++) {
            (*comparacoes)++;
            if(vetor[j] < vetor[indice_minimo]) {
                indice_minimo = j;
            }
        }
        
        if(indice_minimo != i) {
            int temp = vetor[i];
            vetor[i] = vetor[indice_minimo];
            vetor[indice_minimo] = temp;
            (*trocas)++;
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
    int vetor1[] = {64, 25, 12, 22, 11};
    int tamanho = sizeof(vetor1) / sizeof(vetor1[0]);
    
    printf("Vetor original: ");
    exibirVetor(vetor1, tamanho);
    
    selectionSort(vetor1, tamanho);
    
    printf("Vetor ordenado: ");
    exibirVetor(vetor1, tamanho);
    
    int vetor2[] = {64, 25, 12, 22, 11};
    int comparacoes, trocas;
    
    selectionSortComEstatisticas(vetor2, tamanho, &comparacoes, &trocas);
    
    printf("\n=== Estatísticas ===\n");
    printf("Comparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
    
    int vetor3[] = {1, 2, 3, 4, 5};
    int tamanho3 = sizeof(vetor3) / sizeof(vetor3[0]);
    
    printf("\n=== Melhor Caso (já ordenado) ===\n");
    printf("Vetor: ");
    exibirVetor(vetor3, tamanho3);
    
    selectionSortComEstatisticas(vetor3, tamanho3, &comparacoes, &trocas);
    printf("Comparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
    
    int vetor4[] = {5, 4, 3, 2, 1};
    int tamanho4 = sizeof(vetor4) / sizeof(vetor4[0]);
    
    printf("\n=== Pior Caso (ordem inversa) ===\n");
    printf("Vetor: ");
    exibirVetor(vetor4, tamanho4);
    
    selectionSortComEstatisticas(vetor4, tamanho4, &comparacoes, &trocas);
    printf("Comparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
    
    return 0;
}
