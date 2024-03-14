#include <stdio.h>
#include <stdlib.h>

typedef struct StAluno Aluno;
typedef struct StAluno {
    int Num;
    char Nome[10];
    float notas[3];
    Aluno *Prox;
} Aluno;

Aluno *Primeiro;

// Função de alocação dinâmica

Aluno *CadastroAluno()
{
    Aluno *A1 = (Aluno *)malloc(sizeof(Aluno));
    printf("Digite o nome do aluno : ");
    scanf("%s", A1->Nome);
    A1->Prox = NULL;
    return A1;
}

void LsitaAluno(Aluno *A)
{
    Aluno *Aux = A;
    while (Aux != NULL)
    {
        printf("Aluno =>  %s\n", Aux->Nome);
        Aux = Aux->Prox;
    }
}

int main()
{

    Aluno *Aux;
    Primeiro = CadastroAluno();
    Primeiro->Prox = CadastroAluno();
    Aux = Primeiro->Prox;
    Aux->Prox = CadastroAluno();
    LsitaAluno(Primeiro);
    return 0;
}