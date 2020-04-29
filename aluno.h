typedef struct stAluno{
   int mat;
   char nome[40];
   float nota;
} Aluno;

void criarAluno(Aluno *a, int mat, char nome[], float nota);
void bonificarAluno(Aluno *a);
