#include <stdio.h>

int main(){
	int v[15], par[5], impar[5];
	int i=0, j=0, k=0;
	for(i=0; i<15; i++){
		scanf("%d", &v[i]);	
	}
	for(i=0; i<15; i++){
			if(v[i] %2 == 0 && j<5){
				par[j] = v[i];
				j++;
			}
			else if(v[i] %2 != 0 && k<5){
				impar[k] = v[i];
				k++;
			}
			else if(j==5){
				for(j=0; j<5; j++){
					printf("par[%d] = %d\n", j, par[j]);
				}
				j=0;
			}
			else if(k==5){
				for(k=0; k<5; k++){
					printf("impar[%d] = %d\n", k, impar[k]);
				}
				k=0;
			}
	}
return 0;
}
