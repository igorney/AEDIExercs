#include<stdio.h>
#define TAM 20
float somaVetor(float v[], int i){
	if(i == 1){
		return v[i-1];
	}
	else{
		return v[i-1] + somaVetor(v, t-1);
	}
}
int main(){
	float v[TAM];

	for(int i=0; i<TAM; i++){
		scanf("%d", &v[i]);
	}
	return 0;
}
