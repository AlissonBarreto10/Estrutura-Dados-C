#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int elementos[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *pilha) {
    pilha->topo = -1;
}

int vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void empilhar(Pilha *pilha, int valor) {
    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;
}

int desempilhar(Pilha *pilha) {
    int valor = pilha->elementos[pilha->topo];
    pilha->topo--;
    return valor;
}

int avaliarPosFixa(char *expressao) {
    Pilha pilha;
    inicializar(&pilha);
    
    int i = 0;
    while(expressao[i] != '\0') {
        if(expressao[i] == ' ') {
            i++;
            continue;
        }
        
        if(isdigit(expressao[i])) {
            int num = 0;
            while(isdigit(expressao[i])) {
                num = num * 10 + (expressao[i] - '0');
                i++;
            }
            empilhar(&pilha, num);
        } else {
            int operando2 = desempilhar(&pilha);
            int operando1 = desempilhar(&pilha);
            int resultado;
            
            switch(expressao[i]) {
                case '+':
                    resultado = operando1 + operando2;
                    break;
                case '-':
                    resultado = operando1 - operando2;
                    break;
                case '*':
                    resultado = operando1 * operando2;
                    break;
                case '/':
                    resultado = operando1 / operando2;
                    break;
            }
            
            empilhar(&pilha, resultado);
            i++;
        }
    }
    
    return desempilhar(&pilha);
}

int verificarParenteses(char *expressao) {
    Pilha pilha;
    inicializar(&pilha);
    
    for(int i = 0; expressao[i] != '\0'; i++) {
        if(expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            empilhar(&pilha, expressao[i]);
        } else if(expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') {
            if(vazia(&pilha)) {
                return 0;
            }
            
            char topo = desempilhar(&pilha);
            
            if((expressao[i] == ')' && topo != '(') ||
               (expressao[i] == ']' && topo != '[') ||
               (expressao[i] == '}' && topo != '{')) {
                return 0;
            }
        }
    }
    
    return vazia(&pilha);
}

int main() {
    char expressao1[] = "5 3 + 2 *";
    printf("Expressão pós-fixa: %s\n", expressao1);
    printf("Resultado: %d\n", avaliarPosFixa(expressao1));
    
    char expressao2[] = "10 2 / 3 +";
    printf("\nExpressão pós-fixa: %s\n", expressao2);
    printf("Resultado: %d\n", avaliarPosFixa(expressao2));
    
    char expressao3[] = "15 7 1 1 + - / 3 * 2 1 1 + + -";
    printf("\nExpressão pós-fixa: %s\n", expressao3);
    printf("Resultado: %d\n", avaliarPosFixa(expressao3));
    
    printf("\n=== Verificador de Parênteses ===\n");
    
    char teste1[] = "((a + b) * c)";
    printf("Expressão: %s\n", teste1);
    printf("Balanceada: %s\n", verificarParenteses(teste1) ? "Sim" : "Não");
    
    char teste2[] = "((a + b) * c";
    printf("\nExpressão: %s\n", teste2);
    printf("Balanceada: %s\n", verificarParenteses(teste2) ? "Sim" : "Não");
    
    char teste3[] = "{[()]}";
    printf("\nExpressão: %s\n", teste3);
    printf("Balanceada: %s\n", verificarParenteses(teste3) ? "Sim" : "Não");
    
    return 0;
}
