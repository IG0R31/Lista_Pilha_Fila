#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;
typedef struct {
TIPOCHAVE chave;
// outros campos...
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *ant, *prox;
} ELEMENTO;

typedef ELEMENTO* PONT;
typedef struct {
    PONT inicio;
} LISTA;

void inicializarLista(LISTA *l){
    l->inicio = NULL; 
}



bool inserirElemListaOrd(LISTA* l, REGISTRO reg)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if(novo==NULL) return false; 
    novo-> reg= reg;
    novo->ant = NULL;
    novo->prox = NULL;

    if(l->inicio == NULL){
        l->inicio = novo;
        return true;
    }
    PONT atual = l->inicio;
    PONT anterior = NULL; 

    while(atual != NULL && atual->reg.chave < reg.chave){
        anterior = atual;
        atual = atual->prox;
    }
    if(anterior == NULL){
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    else{
        novo->prox=  atual;
        novo->ant= anterior; 
        anterior ->prox = novo;

        if (atual != NULL){
            atual->ant = novo;
        }
    }
    return true;
    
}

void exibirLista(LISTA *l)
{
    PONT atual = l->inicio;
    while(atual != NULL){
        printf("(%d)", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\n");

}

int main(){
    LISTA l;
    inicializarLista(&l);
    REGISTRO r1 = {62};
    REGISTRO r2 = {19};
    REGISTRO r3 = {88};
    inserirElemListaOrd(&l, r1);
    inserirElemListaOrd(&l, r2);
    inserirElemListaOrd(&l, r3);

    printf("Lista após inserções ordenadas: ");
    exibirLista(&l);
    return 0; 
}