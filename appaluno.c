#include <stdio.h>
#include "aluno.h"

int main(){
   Aluno a;

   int mat;
   char nome[40];
   float nota;
   printf("ei, digite o RA do aluno:");
   scanf("%d",&mat);
   printf("digite agora o nome:");
   scanf("%s", nome);
   printf("finalmente, a nota:");
   scanf("%f", &nota);
   criarAluno(&a, mat, nome, nota);
   printf("%d - %s       NOTA=%.1f\n",a.mat,a.nome,a.nota);
   printf("Vou bonificar o aluno\n");
   bonificarAluno(&a);
   printf("%d - %s       NOTA=%.1f\n",a.mat,a.nome,a.nota);
   return 0;

}
