#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StAluno Aluno;
typedef struct StAluno
{
    int Num;
    char Nome[10];
    float notas[3];
    Aluno *Prox;
} Aluno;

// Forma estática

int main()
{
    Aluno A1;
    Aluno Turma[3];
    A1.Num = 10;
    Turma[0].Num = 20;

    printf("A1.turma = %d\n", A1.Num);
    printf("Turma[0].turma = %d\n", Turma[0].Num);
    printf("Turma[1].turma = %d\n", Turma[1].Num);

    Aluno *P1;
    Aluno *P2;
    P1 = (Aluno *)malloc(sizeof(Aluno));
    P1->Num = 30;
    printf("P1.Num = %d\n", P1->Num);
    P2 = &A1;
    printf("P2->Num = %d", P2->Num);

    printf("\n\n");

    // Criação de uma estrutura
    //  encadeada de alunos

    Aluno *Primeiro;
    Primeiro = (Aluno *)malloc(sizeof(Aluno));
    Primeiro->Num = 1;

    // é uma função que copia a string e coloca em uma variável
    
    strcpy(Primeiro->Nome, "Carlos");
    printf("Aluno1 = %s\n", Primeiro->Nome);
    printf("Aluno1 = %d\n", Primeiro->Num);

    // fazendo com que o primeiro aluno aponte para a variável prox que vai criar o segundo aluno e assim por diante
    // Forma menos eficiênte
    // Primeiro->Prox = (Aluno *)malloc(sizeof(Aluno));

    // Forma mais eficiênte
    Aluno *Aux;
    Aux = (Aluno *)malloc(sizeof(Aluno));
    Primeiro->Prox = Aux;
    Aux->Num = 2;
    printf("Aluno2 = %d\n", Aux->Num);

    Aux->Prox = (Aluno *)malloc(sizeof(Aluno));
    Aux = Aux->Prox;
    Aux->Num = 3;
    printf("Aluno3 = %d\n", Aux->Num);

    Aux->Prox = (Aluno *)malloc(sizeof(Aluno));
    Aux = Aux->Prox;
    Aux->Num = 4;
    printf("Aluno4 = %d\n", Aux->Num);
    // indica que o ultimo elemento aponta para nada
    Aux->Prox = NULL;

    printf("\n");

    Aux = Primeiro;
    while (Aux != NULL){
        printf("Aluno %d\n",Aux->Num);
        Aux = Aux->Prox;
    }
 
    return 0;
}
