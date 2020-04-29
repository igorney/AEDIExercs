#include <stdio.h>

int main(){
	int M[4][4];
	int i,j;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			scanf("%d", &M[i][j]);
		}
	}
	for(i=0; i<4; i++){
		if(M[i][0] == 2){
			printf("%d %d\n", M[i][0], M[i][2]);
		}
	}
	return 0;
}
