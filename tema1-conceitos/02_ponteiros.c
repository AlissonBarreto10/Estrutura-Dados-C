#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void incrementar(int *valor) {
    (*valor)++;
}

int main() {
    int x = 10;
    int *p = &x;
    
    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Conteúdo de p: %p\n", p);
    printf("Valor apontado por p: %d\n", *p);
    
    *p = 20;
    printf("\nApós *p = 20:\n");
    printf("Valor de x: %d\n", x);
    
    int a = 5, b = 10;
    printf("\nAntes da troca: a = %d, b = %d\n", a, b);
    trocar(&a, &b);
    printf("Depois da troca: a = %d, b = %d\n", a, b);
    
    int contador = 0;
    printf("\nContador inicial: %d\n", contador);
    incrementar(&contador);
    incrementar(&contador);
    incrementar(&contador);
    printf("Contador final: %d\n", contador);
    
    int vetor[] = {10, 20, 30, 40, 50};
    int *ptr = vetor;
    
    printf("\nPercorrendo vetor com ponteiro:\n");
    for(int i = 0; i < 5; i++) {
        printf("Elemento %d: %d (endereço: %p)\n", i, *(ptr + i), (ptr + i));
    }
    
    return 0;
}
