#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;
typedef struct{
    TIPOCHAVE chave;
}REGISTRO; 

typedef struct aux{
    REGISTRO reg;
    struct aux* ant;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT inicio;
    PONT fim;
}DEQUE; 

void  inicializarDeque(DEQUE* d){
    d->inicio = NULL;
    d->fim =  NULL;
}
bool inserirNoFim(DEQUE* d, REGISTRO reg){
    PONT novo =  (PONT)malloc(sizeof(ELEMENTO)); 
    if(novo== NULL) return false; 

    novo-> reg = reg; 
    novo ->prox = NULL;
    novo -> ant=  d->fim;
    if(d->fim ==NULL){
        d->inicio = novo;
    }else{
        d->fim->prox = novo;
    }
    d->fim = novo; 
    return true; 
}
bool encontrarMAX(DEQUE* d, int* max){
    if(d->inicio == NULL){
        return false;
    }
    PONT atual = d-> inicio;
    *max = atual->reg.chave;
    while (atual != NULL){
        if (atual-> reg.chave > *max){
            *max = atual-> reg.chave;
        }
        atual = atual -> prox;
    }
    return true;
}

int main(){
    DEQUE d;
    inicializarDeque(&d);

    REGISTRO r1 = {99};
    REGISTRO r2 = {56};
    REGISTRO r3 = {75};
    REGISTRO r4 = {109};

    inserirNoFim(&d, r1);
    inserirNoFim(&d, r2);
    inserirNoFim(&d, r3);
    inserirNoFim(&d, r4);

    int max; 
    if(encontrarMAX(&d, &max)){
        printf("O maior valor é %d\n", max);
    }else{
        printf("Não há valores no deque\n");
    }
    return 0; 
}