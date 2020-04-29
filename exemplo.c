#include<stdio.h>
#define TAM 3
int main(){
	int m[TAM][TAM];
	int i, j;

	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			printf("L:%d C:%d E:%ld\n", i, j, &m[i][j]);
		}
	}
return 0;
}
