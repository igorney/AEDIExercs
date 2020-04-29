//Ler um arquivo de valores de um determinado histograma
//um vetor de inteiros armazena estes dados do histograma
#include<stdio.h>

int main(){
	int i, v[30];

	for(i=0; i<30; i++){
		scanf("%d", &v[i]);
	}
	for(i=0; i<30; i++){
		printf("[%d] = %d\n", i, v[i]);
	}

return 0;
}
