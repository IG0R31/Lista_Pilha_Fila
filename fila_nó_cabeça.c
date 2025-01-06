#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio; 
    PONT fim;    
} FILA;


void inicializarFila(FILA* f) {
    f->inicio = (PONT)malloc(sizeof(ELEMENTO));
    f->inicio->prox = NULL;
    f->fim = f->inicio;
}

bool inserirNaFila(FILA* f, REGISTRO reg) {
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;

    novo->reg = reg;
    novo->prox = NULL;

    f->fim->prox = novo; 
    f->fim = novo;       
    return true;
}

bool excluirDaFila(FILA* f, REGISTRO* reg) {
    if (f->inicio->prox == NULL) return false; 

    PONT apagar = f->inicio->prox; 
    *reg = apagar->reg;   

    f->inicio->prox = apagar->prox; 

    if (f->inicio->prox == NULL) {
        f->fim = f->inicio; 
    }

    free(apagar); 
    return true;
}


void exibirFila(FILA* f) {
    PONT atual = f->inicio->prox;
    printf("Fila: ");
    while (atual != NULL) {
        printf("(%d) ", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\n");
}


int main() {
    FILA fila;
    inicializarFila(&fila);

    REGISTRO r1 = {10}, r2 = {20}, r3 = {30}, removido;

  
    inserirNaFila(&fila, r1);
    inserirNaFila(&fila, r2);
    inserirNaFila(&fila, r3);

    printf("Fila original: " );
    exibirFila(&fila);


    excluirDaFila(&fila, &removido);
    printf("Elemento removido: %d\n", removido.chave);
    printf("Após remoção: ");
    exibirFila(&fila);

    return 0;
}
