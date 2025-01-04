#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;
typedef struct 
{
TIPOCHAVE chave;
// outros campos...
} REGISTRO;

typedef struct aux 
{
    REGISTRO reg;
    struct aux *ant, *prox;
} ELEMENTO;

typedef ELEMENTO* PONT;
typedef struct 
{
    PONT inicio;
} LISTA;

void inicializar(LISTA *l)
{
    l->inicio = NULL; 
}
int inserirElemListaOrd(LISTA* l, REGISTRO reg);
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
    
}