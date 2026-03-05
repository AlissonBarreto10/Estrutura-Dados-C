#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct No {
    int vertice;
    struct No *proximo;
} No;

typedef struct {
    No **lista;
    int numVertices;
} Grafo;

No* criarNo(int vertice) {
    No *novo = (No*) malloc(sizeof(No));
    novo->vertice = vertice;
    novo->proximo = NULL;
    return novo;
}

void inicializar(Grafo *g, int numVertices) {
    g->numVertices = numVertices;
    g->lista = (No**) malloc(numVertices * sizeof(No*));
    for(int i = 0; i < numVertices; i++) {
        g->lista[i] = NULL;
    }
}

void adicionarAresta(Grafo *g, int origem, int destino) {
    No *novo = criarNo(destino);
    novo->proximo = g->lista[origem];
    g->lista[origem] = novo;
    
    novo = criarNo(origem);
    novo->proximo = g->lista[destino];
    g->lista[destino] = novo;
}

void dfsRecursivo(Grafo *g, int vertice, int visitado[]) {
    visitado[vertice] = 1;
    printf("%d ", vertice);
    
    No *atual = g->lista[vertice];
    while(atual != NULL) {
        if(!visitado[atual->vertice]) {
            dfsRecursivo(g, atual->vertice, visitado);
        }
        atual = atual->proximo;
    }
}

void dfs(Grafo *g, int inicio) {
    int visitado[MAX] = {0};
    printf("DFS a partir do vértice %d: ", inicio);
    dfsRecursivo(g, inicio, visitado);
    printf("\n");
}

void dfsIterativo(Grafo *g, int inicio) {
    int visitado[MAX] = {0};
    int pilha[MAX];
    int topo = -1;
    
    pilha[++topo] = inicio;
    
    printf("DFS Iterativo a partir do vértice %d: ", inicio);
    
    while(topo >= 0) {
        int vertice = pilha[topo--];
        
        if(!visitado[vertice]) {
            printf("%d ", vertice);
            visitado[vertice] = 1;
        }
        
        No *atual = g->lista[vertice];
        while(atual != NULL) {
            if(!visitado[atual->vertice]) {
                pilha[++topo] = atual->vertice;
            }
            atual = atual->proximo;
        }
    }
    printf("\n");
}

void liberar(Grafo *g) {
    for(int i = 0; i < g->numVertices; i++) {
        No *atual = g->lista[i];
        while(atual != NULL) {
            No *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(g->lista);
}

int main() {
    Grafo g;
    inicializar(&g, 7);
    
    adicionarAresta(&g, 0, 1);
    adicionarAresta(&g, 0, 2);
    adicionarAresta(&g, 1, 3);
    adicionarAresta(&g, 1, 4);
    adicionarAresta(&g, 2, 5);
    adicionarAresta(&g, 2, 6);
    
    dfs(&g, 0);
    dfsIterativo(&g, 0);
    
    liberar(&g);
    
    return 0;
}
