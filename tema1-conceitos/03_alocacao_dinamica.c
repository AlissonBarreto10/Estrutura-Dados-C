#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int tamanho;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    vetor = (int*) malloc(tamanho * sizeof(int));
    
    if(vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    
    printf("\nPreenchendo o vetor:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &vetor[i]);
    }
    
    printf("\nVetor alocado:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    
    int novo_tamanho;
    printf("\nDigite o novo tamanho: ");
    scanf("%d", &novo_tamanho);
    
    vetor = (int*) realloc(vetor, novo_tamanho * sizeof(int));
    
    if(vetor == NULL) {
        printf("Erro ao realocar memória!\n");
        return 1;
    }
    
    if(novo_tamanho > tamanho) {
        printf("\nPreenchendo novos elementos:\n");
        for(int i = tamanho; i < novo_tamanho; i++) {
            printf("Elemento %d: ", i);
            scanf("%d", &vetor[i]);
        }
    }
    
    printf("\nVetor realocado:\n");
    for(int i = 0; i < novo_tamanho; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    
    free(vetor);
    
    int *matriz;
    int linhas, colunas;
    
    printf("\nDigite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);
    
    matriz = (int*) calloc(linhas * colunas, sizeof(int));
    
    if(matriz == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    
    printf("\nMatriz inicializada com zeros:\n");
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i * colunas + j]);
        }
        printf("\n");
    }
    
    free(matriz);
    
    return 0;
}
