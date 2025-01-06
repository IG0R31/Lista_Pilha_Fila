
#include <stdio.h>
#include <stdlib.h>
#define MAX 50 
typedef struct 
{
    int dados[MAX];
    int topo;    
}PILHA;

void inicializarPilha(PILHA* p) {
    p->topo = 0;
}

int tamanhoPilha(PILHA* p) {
    return p->topo;
}

int empilhar(PILHA* p, int valor) {
    if(p->topo >= MAX){
        return 0;
    }
    p->dados[p->topo]= valor; 
    p->topo++; 
    return 1; 
    

}
void exibirPilha(PILHA* p) {
    printf("Pilha:(do topo para base) ");
    for (int i = p->topo; i >= 0; i--) {
        printf("(%d) ", p->dados[i]);
    }
    printf("\"\n");
}

void exibirPilhaInvertida(PILHA* p) {
    printf("Pilha (da base para o topo): \" ");
    for(int i = 0; i < p->topo; i++) {
        printf("(%d)", p->dados[i]);
    }
    printf("\"\n");
}



int  main(){
    PILHA p;
    inicializarPilha(&p);

    empilhar(&p, 11);
    empilhar(&p, 49);
    empilhar(&p, 9);

    exibirPilhaInvertida(&p);
    exibirPilha(&p);
    return 0; 
}









