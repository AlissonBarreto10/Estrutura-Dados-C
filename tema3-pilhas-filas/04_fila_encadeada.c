#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

void inicializar(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int vazia(Fila *fila) {
    return fila->inicio == NULL;
}

void enfileirar(Fila *fila, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;
    
    if(vazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
    fila->tamanho++;
}

int desenfileirar(Fila *fila, int *valor) {
    if(vazia(fila)) {
        return 0;
    }
    No *temp = fila->inicio;
    *valor = temp->dado;
    fila->inicio = temp->proximo;
    
    if(fila->inicio == NULL) {
        fila->fim = NULL;
    }
    
    free(temp);
    fila->tamanho--;
    return 1;
}

int frente(Fila *fila, int *valor) {
    if(vazia(fila)) {
        return 0;
    }
    *valor = fila->inicio->dado;
    return 1;
}

void exibir(Fila *fila) {
    if(vazia(fila)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Fila [%d elementos]: ", fila->tamanho);
    No *atual = fila->inicio;
    while(atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void liberar(Fila *fila) {
    No *atual = fila->inicio;
    while(atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int main() {
    Fila fila;
    inicializar(&fila);
    
    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);
    enfileirar(&fila, 40);
    exibir(&fila);
    
    int valor;
    if(frente(&fila, &valor)) {
        printf("\nFrente: %d\n", valor);
    }
    
    printf("\nDesenfileirando:\n");
    while(desenfileirar(&fila, &valor)) {
        printf("Removido: %d\n", valor);
    }
    
    exibir(&fila);
    liberar(&fila);
    
    return 0;
}
