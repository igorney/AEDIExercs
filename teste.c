#include<stdio.h>
#define TAM 10

void mostrarHistograma(int pos, int valores){
	
		int cont;
		while(cont <= v[i]){
			printf("*");
			cont++;
		}
		printf("\n");
}

int main(){
	int v[TAM], i, cont;

	for(i=0; i<TAM; i++){
		scanf("%d", &v[i]);
	}
	
	for(i=1; i<=TAM; i++){
		mostrarHistograma(i, v[i]);
	} 
return 0;
}
