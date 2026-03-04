#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} ListaEncadeada;

void inicializar(ListaEncadeada *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserirInicio(ListaEncadeada *lista, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

void inserirFim(ListaEncadeada *lista, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;
    
    if(lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *atual = lista->inicio;
        while(atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    lista->tamanho++;
}

int removerInicio(ListaEncadeada *lista) {
    if(lista->inicio == NULL) {
        return 0;
    }
    No *temp = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    free(temp);
    lista->tamanho--;
    return 1;
}

int removerValor(ListaEncadeada *lista, int valor) {
    if(lista->inicio == NULL) {
        return 0;
    }
    
    if(lista->inicio->dado == valor) {
        return removerInicio(lista);
    }
    
    No *atual = lista->inicio;
    while(atual->proximo != NULL && atual->proximo->dado != valor) {
        atual = atual->proximo;
    }
    
    if(atual->proximo == NULL) {
        return 0;
    }
    
    No *temp = atual->proximo;
    atual->proximo = temp->proximo;
    free(temp);
    lista->tamanho--;
    return 1;
}

No* buscar(ListaEncadeada *lista, int valor) {
    No *atual = lista->inicio;
    while(atual != NULL) {
        if(atual->dado == valor) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void exibir(ListaEncadeada *lista) {
    printf("Lista [%d elementos]: ", lista->tamanho);
    No *atual = lista->inicio;
    while(atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void liberar(ListaEncadeada *lista) {
    No *atual = lista->inicio;
    while(atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int main() {
    ListaEncadeada lista;
    inicializar(&lista);
    
    inserirFim(&lista, 10);
    inserirFim(&lista, 20);
    inserirFim(&lista, 30);
    exibir(&lista);
    
    inserirInicio(&lista, 5);
    exibir(&lista);
    
    removerValor(&lista, 20);
    exibir(&lista);
    
    No *encontrado = buscar(&lista, 30);
    if(encontrado != NULL) {
        printf("Elemento 30 encontrado!\n");
    }
    
    liberar(&lista);
    
    return 0;
}
