#include <stdio.h>
int main() {
	float raio;
	printf("Insira o raio da esfera:\n");
	scanf("%f", &raio);
	printf("%f", (4.0/3)*3.14159*raio*raio*raio);
	return 0;
}
