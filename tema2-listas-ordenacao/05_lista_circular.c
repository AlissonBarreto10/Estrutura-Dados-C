#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} ListaCircular;

void inicializar(ListaCircular *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserir(ListaCircular *lista, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    
    if(lista->inicio == NULL) {
        novo->proximo = novo;
        lista->inicio = novo;
    } else {
        No *atual = lista->inicio;
        while(atual->proximo != lista->inicio) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
        novo->proximo = lista->inicio;
    }
    lista->tamanho++;
}

int remover(ListaCircular *lista, int valor) {
    if(lista->inicio == NULL) {
        return 0;
    }
    
    No *atual = lista->inicio;
    No *anterior = NULL;
    
    do {
        if(atual->dado == valor) {
            if(anterior == NULL) {
                if(atual->proximo == atual) {
                    lista->inicio = NULL;
                } else {
                    No *ultimo = lista->inicio;
                    while(ultimo->proximo != lista->inicio) {
                        ultimo = ultimo->proximo;
                    }
                    lista->inicio = atual->proximo;
                    ultimo->proximo = lista->inicio;
                }
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            lista->tamanho--;
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    } while(atual != lista->inicio);
    
    return 0;
}

void exibir(ListaCircular *lista) {
    if(lista->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }
    
    printf("Lista Circular [%d]: ", lista->tamanho);
    No *atual = lista->inicio;
    do {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    } while(atual != lista->inicio);
    printf("(volta ao início)\n");
}

void liberar(ListaCircular *lista) {
    if(lista->inicio == NULL) {
        return;
    }
    
    No *atual = lista->inicio;
    No *proximo;
    
    do {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    } while(atual != lista->inicio);
    
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int main() {
    ListaCircular lista;
    inicializar(&lista);
    
    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);
    inserir(&lista, 40);
    exibir(&lista);
    
    remover(&lista, 20);
    exibir(&lista);
    
    inserir(&lista, 50);
    exibir(&lista);
    
    liberar(&lista);
    
    return 0;
}
