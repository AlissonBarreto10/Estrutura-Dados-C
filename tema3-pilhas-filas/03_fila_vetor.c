#include <stdio.h>

#define MAX 10

typedef struct {
    int elementos[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializar(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
}

int vazia(Fila *fila) {
    return fila->tamanho == 0;
}

int cheia(Fila *fila) {
    return fila->tamanho == MAX;
}

int enfileirar(Fila *fila, int valor) {
    if(cheia(fila)) {
        return 0;
    }
    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % MAX;
    fila->tamanho++;
    return 1;
}

int desenfileirar(Fila *fila, int *valor) {
    if(vazia(fila)) {
        return 0;
    }
    *valor = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->tamanho--;
    return 1;
}

int frente(Fila *fila, int *valor) {
    if(vazia(fila)) {
        return 0;
    }
    *valor = fila->elementos[fila->inicio];
    return 1;
}

void exibir(Fila *fila) {
    if(vazia(fila)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Fila [%d elementos]: ", fila->tamanho);
    int i = fila->inicio;
    for(int count = 0; count < fila->tamanho; count++) {
        printf("%d ", fila->elementos[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
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
    
    printf("\nTestando comportamento circular:\n");
    for(int i = 1; i <= 8; i++) {
        enfileirar(&fila, i * 10);
    }
    exibir(&fila);
    
    desenfileirar(&fila, &valor);
    desenfileirar(&fila, &valor);
    exibir(&fila);
    
    enfileirar(&fila, 90);
    enfileirar(&fila, 100);
    exibir(&fila);
    
    return 0;
}
