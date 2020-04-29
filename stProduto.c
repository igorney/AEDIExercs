#include <stdio.h>

typedef struct stAluno{
	char nome[30];
	int matricula;
	float nota1;
	float nota2;
} Aluno;

int main(){
	Aluno v[10];
	int i;
	for(i=0; i<10; i++){
		printf("Batata");
		//Inserção do aluno
		scanf("%s", v[i].nome);
		scanf("%d", &v[i].matricula);
		scanf("%f", &v[i].nota1);
		scanf("%f", &v[i].nota2);
	}

	return 0;
}
