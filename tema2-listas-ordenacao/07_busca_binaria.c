#include <stdio.h>

int buscaBinariaIterativa(int vetor[], int tamanho, int valor) {
    int esquerda = 0;
    int direita = tamanho - 1;
    
    while(esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        if(vetor[meio] == valor) {
            return meio;
        }
        
        if(vetor[meio] < valor) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    
    return -1;
}

int buscaBinariaRecursiva(int vetor[], int esquerda, int direita, int valor) {
    if(esquerda > direita) {
        return -1;
    }
    
    int meio = esquerda + (direita - esquerda) / 2;
    
    if(vetor[meio] == valor) {
        return meio;
    }
    
    if(vetor[meio] < valor) {
        return buscaBinariaRecursiva(vetor, meio + 1, direita, valor);
    } else {
        return buscaBinariaRecursiva(vetor, esquerda, meio - 1, valor);
    }
}

int buscaBinariaComparacoes(int vetor[], int tamanho, int valor, int *comparacoes) {
    *comparacoes = 0;
    int esquerda = 0;
    int direita = tamanho - 1;
    
    while(esquerda <= direita) {
        (*comparacoes)++;
        int meio = esquerda + (direita - esquerda) / 2;
        
        if(vetor[meio] == valor) {
            return meio;
        }
        
        if(vetor[meio] < valor) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    
    return -1;
}

int main() {
    int vetor[] = {11, 12, 22, 25, 34, 45, 50, 64, 88, 90};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    printf("Vetor ordenado: ");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");
    
    int valor = 45;
    int posicao = buscaBinariaIterativa(vetor, tamanho, valor);
    
    if(posicao != -1) {
        printf("Busca Iterativa: Valor %d encontrado na posição %d\n", valor, posicao);
    } else {
        printf("Busca Iterativa: Valor %d não encontrado\n", valor);
    }
    
    posicao = buscaBinariaRecursiva(vetor, 0, tamanho - 1, valor);
    
    if(posicao != -1) {
        printf("Busca Recursiva: Valor %d encontrado na posição %d\n", valor, posicao);
    } else {
        printf("Busca Recursiva: Valor %d não encontrado\n", valor);
    }
    
    printf("\n=== Análise de Comparações ===\n");
    int comparacoes;
    
    valor = 50;
    posicao = buscaBinariaComparacoes(vetor, tamanho, valor, &comparacoes);
    printf("Buscar %d: %d comparações\n", valor, comparacoes);
    
    valor = 11;
    posicao = buscaBinariaComparacoes(vetor, tamanho, valor, &comparacoes);
    printf("Buscar %d: %d comparações\n", valor, comparacoes);
    
    valor = 90;
    posicao = buscaBinariaComparacoes(vetor, tamanho, valor, &comparacoes);
    printf("Buscar %d: %d comparações\n", valor, comparacoes);
    
    valor = 999;
    posicao = buscaBinariaComparacoes(vetor, tamanho, valor, &comparacoes);
    printf("Buscar %d (não existe): %d comparações\n", valor, comparacoes);
    
    return 0;
}
