#include <stdio.h>

int main(){
	int plugue[5], tomada[5];
	int i, aux =0;

	for(i=0; i<5; i++){
		scanf("%d", &plugue[i]);
	}
	for(i=0; i<5; i++){
		scanf("%d", &tomada[i]);
	}
	for(i=0; i<5; i++){
		if(tomada[i] == plugue[i]){
			printf("N");
			break;
		}
		else{
			aux++;
		}
	}
	if(aux == 5){
		printf("Y");
	}
	return 0;
}
