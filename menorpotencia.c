#include <stdio.h>

int main(){
	int n, i=1;
	scanf("%d", &n);

	while(i<n){
		i*=2;
	}
	printf(" A menor potencia de 2 de %d é : %d", n, i);

return 0;
}
