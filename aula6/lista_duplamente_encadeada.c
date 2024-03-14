#include <stdio.h>
#include <stdlib.h>
#include <string.h>



ListaDpl* lstdpl_insere_final(ListaDpl* lista, item* x){
    CelulaDpl* nova = (CelulaDpl*)malloc(sizeof(CelulaDpl));

    nova->item = x;
    nova->ant = lista->ultimo;
    nova->prox = NULL;

    if(lista->prim != NULL) lista->ultimo->prox = nova;

    Lista->ultimo = lista->ultimo->prox;

    return lista;
    
}


