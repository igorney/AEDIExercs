#include "aluno.h"
#include <string.h>
void criarAluno(Aluno *a, int mat, char nome[], float nota){
   a->mat = mat;
   strcpy(a->nome, nome);
   a->nota = nota;
}
void bonificarAluno(Aluno *a){
   a->nota += 0.5;
}