#include<stdio.h>

int main(){
	int v1[5];
	int v2[5];
	int i, comparador;

	for(i=0; i<5; i++){
		scanf("%d", &v1[i]);
	}

	for(i=0; i<5; i++){
		scanf("%d", &v2[i]);
		if(v2[i] == v1[i])
			comparador++;
	}
	if(comparador == 5){
		printf("Y");
	}
	else{
		printf("N");
	}
	
return 0;
}
