#include <stdio.h>

int main() {
	double a, b, c, i;
	scanf("%lf\n%lf\n%lf", &a, &b, &c);
	if(a > b && a < c) {
		printf("Mediana = %lf\n", a);
	}
	else if(b > a && b < c) {
		printf("Mediana = %lf\n", b);
	}
	else if(c > a && c < b) {
		printf("Mediana = %lf\n", c);
	}
	else {
		printf("Mano, não sei o que aconteceu!");
	}
	return 0;
}
