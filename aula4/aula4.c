#include <stdio.h>

typedef struct StAluno Aluno;
typedef struct StAluno
{
  char data[10];
  

} Aluno;


Aluno * CadastrarData()
{
 Aluno *Primeiro;
  Primeiro = (Aluno *)malloc(sizeof(Aluno));
  printf("Digite a data da seguinte forma dd/mm/aaaa");
  scanf("%s",Primeiro->data);
  return Primeiro;
}


int main(void)
{



  return 0;
}