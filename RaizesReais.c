#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int a, b , c;
	double r1, r2, d;
	
	printf("Insira os valores dos coeficientes do maior para o menor grau:\n");
	scanf("%d %d %d", &a, &b, &c);

	d = (b*b) - 4*a*c;
	r1 = (-b + sqrt(d)) / 2*a;
	r2 = (-b - sqrt(d)) / 2*a;

	printf(" Raiz 1: %.4lf \n Raiz 2: %.4lf \n", r1, r2);
	return 0;
}
