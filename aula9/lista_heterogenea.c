
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ret 0;
#define tri 1;
#define cir 2;

typedef struct lista Lista;
struct lista{

    Celula* prim;
    Celula* Ultimo
    
};


Celula* cria_cel_ret (float b, float h){
    Retangulo* novo_retangulo = (Retangulo*)malloc(sizeof(Retangulo));
    novo_retangulo->b = b;
    novo_retangulo->h = h;
    
    Celula* nova_celula = (Celula*)malloc(sizeof(Celula));
    nova_celula->tipo = ret;
    nova_celula->item = novo_retangulo;
    nova_celula->prox = NULL;

    return nova_celula;
}


Celula* cria_cel_tri (float b, float h){
      Triangulo* novo_triangulo = (Triangulo*)malloc(sizeof(Triangulo));
    novo_triangulo->b = b;
    novo_retangulo->h = h;
    
    Celula* nova_celula = (Celula*)malloc(sizeof(Celula));
    nova_celula->tipo = tri;
    nova_celula->item = novo_triangulo;
    nova_celula->prox = NULL;

    return nova_celula;
}


Celula* cria_cel_cir (float r){
      Circulo* novo_circulo = (Circulo*)malloc(sizeof(Circulo));
    novo_circulo->r = r;
    
    Celula* nova_celula = (Celula*)malloc(sizeof(Celula));
    nova_celula->tipo = cir;
    nova_celula->item = novo_circulo;
    nova_celula->prox = NULL;

    return nova_celula;
}

