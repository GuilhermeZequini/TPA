#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// ESQUELETO PARA IMPLEMENTAÇÃO DE UMA LISTA SIMPLESMENTE ENCADEADA
// A LISTA ARMAZENA ITENS DO TIPO "ALUNO", COM NOME E MATRÍCULA

// ITENS DA LISTA. FAREMOS UM TIPO "ALUNO"



typedef struct aluno Aluno;
struct aluno {
    int Matricula;
    char* Nome;
};

Aluno* criaraluno(char* Nome, int Matricula){
    Aluno* novoaluno = (Aluno*)malloc(sizeof(Aluno));
    novoaluno->Matricula = Matricula;
    novoaluno->Nome = nome;
    return novoaluno;
};

char* recuperaNome(Aluno* aluno){
    return aluno->Nome;
};

void imprimeAluno(Aluno* aluno){
    printf("Nome : %s \n",aluno->Nome);
    printf("Matricula : %d \n",aluno->Matricula);

    printf("\n\n");

    printf("Nome : %s",recuperaNome(aluno));
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

typedef struct lista Lista; // strutura de controle
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
     }
     else{
        // lista não está  vazia 
        lista->Ultimo->prox = nova;
     }
    lista->Ultimo = nova;
    return lista;
}


// retira aluno por nome 
int retiraAluno(Lista* lista, char* nome){
    Celula* atual = lista->prim;

//Se ele for o primeiro da lista
 if (strcmp(atual->item->Nome ,nome) == 0){
    excluiAluno(atual->item);
    lista->prim = lista->prim->prox;

    //caso o elemento também seja o último da lista e o unico 
    if(lista->prim == NULL){
        lista->Ultimo = NULL;
    }

    free(atual);
    return 0;
 }

    //caso ele não seja o primeiro
    while (atual->prox != NULL ){
        if (strcmp(atual->prox->item->Nome ,nome) == 0){
            excluiAluno(atual->prox->item);
            Celula* toDelete = atual->prox;
            atual->prox = atual->prox->prox;
            free(toDelete);
            if(atual->prox == NULL){
                lista->Ultimo = atual;
            }
            return 0;
        }
        atual = atual->prox;
    }
    return 1;
}

// imprime a lista 
void imprimeLista(Lista* lista){
    Celula* atual = lista->prim;
    while (atual != NULL){
        imprimeAluno(atual->item);
        atual = atual->prox;
    
    }
}


// liberação da memória alocada para a lista 
void liberaLista(Lista* lista){
    Celula* atual = lista->prim;
    Celula* prox;
    while (atual != NULL){
        prox = atual->prox;
        excluiAluno(atual->item);
        free(atual);   
    }
    free(lista);      
}



