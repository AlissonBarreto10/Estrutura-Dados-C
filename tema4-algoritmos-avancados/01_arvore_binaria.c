#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor[50];
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(char *valor) {
    No *novo = (No*) malloc(sizeof(No));
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void preOrdem(No *raiz) {
    if(raiz != NULL) {
        printf("%s ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(No *raiz) {
    if(raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void posOrdem(No *raiz) {
    if(raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s ", raiz->valor);
    }
}

int altura(No *raiz) {
    if(raiz == NULL) {
        return -1;
    }
    int alturaEsq = altura(raiz->esquerda);
    int alturaDir = altura(raiz->direita);
    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}

int contarNos(No *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

void liberar(No *raiz) {
    if(raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

int main() {
    No *raiz = criarNo("Sala");
    raiz->esquerda = criarNo("Cozinha");
    raiz->direita = criarNo("Quarto");
    raiz->esquerda->esquerda = criarNo("Despensa");
    raiz->esquerda->direita = criarNo("Lavanderia");
    raiz->direita->esquerda = criarNo("Banheiro");
    raiz->direita->direita = criarNo("Closet");
    
    printf("Pré-ordem: ");
    preOrdem(raiz);
    printf("\n");
    
    printf("Em ordem: ");
    emOrdem(raiz);
    printf("\n");
    
    printf("Pós-ordem: ");
    posOrdem(raiz);
    printf("\n");
    
    printf("\nAltura da árvore: %d\n", altura(raiz));
    printf("Total de nós: %d\n", contarNos(raiz));
    
    liberar(raiz);
    
    return 0;
}
