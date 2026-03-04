#include <stdio.h>

#define MAX 10

typedef struct {
    int elementos[MAX];
    int tamanho;
} Lista;

void inicializar(Lista *lista) {
    lista->tamanho = 0;
}

int inserir(Lista *lista, int valor) {
    if(lista->tamanho >= MAX) {
        return 0;
    }
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
    return 1;
}

int remover(Lista *lista, int posicao) {
    if(posicao < 0 || posicao >= lista->tamanho) {
        return 0;
    }
    for(int i = posicao; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
    return 1;
}

int buscar(Lista *lista, int valor) {
    for(int i = 0; i < lista->tamanho; i++) {
        if(lista->elementos[i] == valor) {
            return i;
        }
    }
    return -1;
}

void exibir(Lista *lista) {
    printf("Lista [%d elementos]: ", lista->tamanho);
    for(int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

int main() {
    Lista lista;
    inicializar(&lista);
    
    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);
    inserir(&lista, 40);
    inserir(&lista, 50);
    
    exibir(&lista);
    
    int pos = buscar(&lista, 30);
    if(pos != -1) {
        printf("Elemento 30 encontrado na posição %d\n", pos);
    }
    
    remover(&lista, 2);
    printf("Após remover posição 2:\n");
    exibir(&lista);
    
    inserir(&lista, 60);
    inserir(&lista, 70);
    exibir(&lista);
    
    return 0;
}
