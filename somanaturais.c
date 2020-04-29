#include <stdio.h>

int main() {
	int n, i, soma = 0;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		if(i%3==0 || i%5==0){
			soma += i;
		}
	}
	printf("Soma = %d\n", soma);
	return 0;
}
