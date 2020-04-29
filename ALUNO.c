#include <stdio.h>
#include <string.h>

typedef struct stAluno{
   long mat;
   char nome[40];
   float nota;
} Aluno;
void criarAluno(Aluno *a, long mat, char nome[], float nota){
   a->mat = mat;
   strcpy(a->nome, nome);
   a->nota = nota;
}
void bonificarAluno(Aluno *a){
   a->nota += 0.5;
}
int main(){
   Aluno a;

   long mat;
   char nome[40];
   float nota;

   printf("ei, digite o RA do aluno: ");
   scanf("%ld",&mat);
   
   printf("digite agora o nome: ");
   scanf("%s", nome);
   
   printf("finalmente, a nota: ");
   scanf("%f", &nota);
   
   criarAluno(&a, mat, nome, nota); // chama funçao cria aluno, passando o ponteiro como edereço de aluno para criar.

   printf("%ld - %s       NOTA = %.1f\n",a.mat,a.nome,a.nota);
   
   printf("Vou bonificar o aluno\n");
   
   bonificarAluno(&a); //Passa novamente o ponteiro a para alterar as informações de aluno
   printf("%ld - %s       NOTA = %.1f\n",a.mat,a.nome,a.nota);

   return 0;
}