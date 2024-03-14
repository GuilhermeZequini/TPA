#include <stdio.h>
#include <stdlib.h>



// ESQUELETO PARA IMPLEMENTAÇÃO DE UMA LISTA SIMPLESMENTE ENCADEADA
// A LISTA ARMAZENA ITENS DO TIPO "ALUNO", COM NOME E MATRÍCULA

// ITENS DA LISTA. FAREMOS UM TIPO "ALUNO"



typedef struct aluno Aluno;
typedef struct aluno {
    int Matricula;
    char* Nome;
};

Aluno* criaraluno(char* Nome, int Matricula){
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    novo->Matricula = Matricula;
    novo->Nome = nome;
    return novo;
};

char* recuperaNome(Aluno* aluno){
    return aluno->Nome;
};

void imprimeAluno(Aluno* aluno){
    printf("Nome : %s",aluno->Nome);
    printf("Nome : %d",aluno->Matricula);

    printf("\n\n");

  //  char* nome = recuperaNome(aluno);
  //  printf("Nome : %s",aluno->Nome);
};

void excluiAluno(Aluno* aluno){
    free(aluno);
};




// A LISTA EM SI


// Vamos criar um tipo célula, que representa cada item da lista.
typedef struct celula Celula;
struct celula {
    Aluno* item;
    Celula* prox;
};

typedef struct lista Lista;
struct lista {
    Celula *prim;
    Celula *Ultimo;
};


//Iniciando a lista vazia

Lista* iniciaLista(){
    Lista* nova = (Lista*)malloc(sizeof(Lista));
    nova->prim = NULL;
    nova->Ultimo = NULL;
    return nova;
}

Lista* insereAluno(Lista* lista, Aluno* aluno){
    // criar uma nova celula
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->item = aluno;
    nova->prox = NULL;



    //se a lista esiver vazia 
     if (lista->prim  == NULL && lista->Ultimo = NULL){
        lista->prim = nova;
        lista->Ultimo = nova;
        return lista;
     }
     else{
        lista->Ultimo->prox = nova;
        lista->Ultimo = nova;
        return lista;
     }

}

// retira aluno por nome 
int retiraAluno(Lista* lista, char* nome){
    Celula* ant = NULL;
    Celula* p = lista->prim;

    while (p != NULL && strcmp(p->item->Nome ,nome))
    {
        
    }
    
}

// imprime a lista 
void imprimeLista(Lista* lista);

// liberação da memória alocada para a lista 
void liberaLista(Lista* lista);







/*
void Insere(TipoItem *X, TipoLista *lista)
{
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    if (lista->Ultimo == NULL)
    {
        lista->prim = novo;
        lista->Ultimo = novo;
    }
    else{
        TipoLista->
    }
}
*/
