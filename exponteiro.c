#include<stdio.h>
#include<stdlib.h>
int main(){
	int a;
	int *pa; //endereço de a
	pa = &a; // pa aponta pra a
	
	a = 10;
	printf("Conteudo: %d\n", *pa);
	
	*pa = 5;
	printf("Valor de a: %d\n", a);

	return 0;
}
