#include <stdio.h>

int main(){
	unsigned int n, i;

	scanf("%u", &n);
	
	for(i=1; i<=n; i++){
		if(n%i==0){
			printf("%u\n", i);
		}
	}

	return 0;
}
