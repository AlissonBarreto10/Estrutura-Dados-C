#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
    int tamanho;
} Pilha;

void inicializar(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

int vazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

void empilhar(Pilha *pilha, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

int desempilhar(Pilha *pilha, int *valor) {
    if(vazia(pilha)) {
        return 0;
    }
    No *temp = pilha->topo;
    *valor = temp->dado;
    pilha->topo = temp->proximo;
    free(temp);
    pilha->tamanho--;
    return 1;
}

int topo(Pilha *pilha, int *valor) {
    if(vazia(pilha)) {
        return 0;
    }
    *valor = pilha->topo->dado;
    return 1;
}

void exibir(Pilha *pilha) {
    if(vazia(pilha)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Pilha [%d elementos]:\n", pilha->tamanho);
    No *atual = pilha->topo;
    int pos = 0;
    while(atual != NULL) {
        printf("  [%d]: %d\n", pos, atual->dado);
        atual = atual->proximo;
        pos++;
    }
}

void liberar(Pilha *pilha) {
    No *atual = pilha->topo;
    while(atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

int main() {
    Pilha pilha;
    inicializar(&pilha);
    
    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);
    empilhar(&pilha, 40);
    exibir(&pilha);
    
    int valor;
    if(topo(&pilha, &valor)) {
        printf("\nTopo: %d\n", valor);
    }
    
    printf("\nDesempilhando:\n");
    while(desempilhar(&pilha, &valor)) {
        printf("Removido: %d\n", valor);
    }
    
    exibir(&pilha);
    liberar(&pilha);
    
    return 0;
}
