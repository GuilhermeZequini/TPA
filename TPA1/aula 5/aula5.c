#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// ESQUELETO PARA IMPLEMENTAÇÃO DE UMA LISTA SIMPLESMENTE ENCADEADA
// A LISTA ARMAZENA ITENS DO TIPO "ALUNO", COM NOME E MATRÍCULA

// ITENS DA LISTA. FAREMOS UM TIPO "ALUNO"

typedef struct aluno Aluno;
struct aluno
{
    int matricula;
    char* nome;
};

Aluno* CriarAluno(char* nome, int matricula){
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    novoAluno->matricula = matricula;
    novoAluno->nome = nome;
};

char* recuperaNome(Aluno* novoAluno){
    return novoAluno->nome;
};

void imprimeAluno(Aluno* aluno){
    printf("Nome : %s",aluno->nome);
    printf("Nome : %d",aluno->matricula);

    printf("\n\n");

    char* nome = recuperaNome(aluno);
    printf("Nome : %s",aluno->nome);
};

void exculirAluno(Aluno* aluno){
    free(aluno);
};


// A LISTA EM SI

// Vamos criar um tipo célula, que representa cada item da lista.
typedef struct celula Celula;
struct celula
{
    Aluno* item;
    Celula* prox;
};

typedef struct lista Lista;
struct lista
{
    Celula* Primeira;
    Celula* Ultima;
};

Lista* iniciarLista(){
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->Primeira = NULL;
    novaLista->Ultima = NULL;
    return novaLista;
};
Lista* insereAluno(Lista* lista ,Aluno* aluno){
    //Criar uma nova celula 
    Celula*  novaCelula = (Celula*)malloc(sizeof(Celula));
    novaCelula->item =  aluno;
    novaCelula->prox = NULL;

    //Se al lista esiver vazia 
    if(lista->Primeira == NULL && lista->Ultima == NULL){
        lista->Primeira = novaCelula;
        lista->Ultima = novaCelula;
        return lista;
    }
    else{
        lista->Primeira->prox = novaCelula;
        lista->Ultima = novaCelula;
        return lista;
    }

};



int main() {
  
 // Criar lista
    Lista* minhaLista = iniciarLista();

    // Criar e inserir alunos na lista
    Aluno* aluno1 = CriarAluno("Joao", 123);
    Aluno* aluno2 = CriarAluno("Maria", 456);

    minhaLista = insereAluno(minhaLista, aluno1);
    minhaLista = insereAluno(minhaLista, aluno2);
   

    // Imprimir alunos na lista
    Celula* atual = minhaLista->Primeira;

    while (atual != NULL) {
        imprimeAluno(atual->item);
        atual = atual->prox;
    }
    return 0;
}

/*

// retira aluno por nome 
int retiraAluno(Lista* lista, char* nome);

// imprime a lista 
void imprimeLista(Lista* lista);

// liberação da memória alocada para a lista 
void liberaLista(Lista* lista);




   */
