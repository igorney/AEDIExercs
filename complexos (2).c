//gcc complexos.c -o complexos.exe
#include<stdio.h>

struct tComplex{
	int re;
	int im;
};

//Recebe dois inteiros a e b e retorna um complexo
struct tComplex complexo(int real, int imaginario){
	struct tComplex numero;
	numero.re = real;
	numero.im = imaginario;
	return numero;
}

//Recebe dois complexos e retorna a adição de ambos.
struct tComplex soma(struct tComplex c1, struct tComplex c2){
	struct tComplex resultado;
	resultado = complexo(c1.re+c2.re, c1.im+c2.im);
	return resultado;
}

//Recebe dois complexos e retorna a subtração de ambos
struct tComplex sub(struct tComplex c1, struct tComplex c2){
	struct tComplex resultado;
	resultado = complexo(c1.re-c2.re, c1.im-c2.im);
	return resultado;
}

//Recebe dois complexos e retorna o produto de ambos.
struct tComplex mult(struct tComplex c1, struct tComplex c2){
	struct tComplex resultado;
	resultado = complexo(c1.re*c2.re - c1.im*c2.im, c1.re*c2.im + c1.im*c2.re);
	return resultado;
}

//Recebe dois complexos e retorna o quociente de ambos.
/*

https://brasilescola.uol.com.br/matematica/divisao-numeros-complexos.htm

Ao dividirmos dois números complexos devemos escrevê-los em forma de fração
e multiplicarmos o numerador e o denominador pelo conjugado do denominador.

Ex. z1    1 + i     1 - 2i   3 - i
    -- =  ------ x ------- = -----
    z2    1 + 2i    1 - 2i     5

*/
struct tComplex div(struct tComplex c1, struct tComplex c2){
    struct tComplex resultado, aux1, aux2;
	struct tComplex conjugado = complexo(c2.re, c2.im*-1);
    aux1 = mult(c1, conjugado);
	aux2 = mult(c2, conjugado);
    resultado = complexo(aux1.re / aux2.re, aux1.im / aux2.re);
	return resultado;
}

int main() {
	int re1, im1, re2, im2;
	char i1, i2, op;
	//enquanto o usuario digitar o primeiro real
    while (scanf ("%d", &re1) != EOF) {
        scanf ("%d %c %c %d %d %c", &im1, &i1, &op, &re2, &im2, &i2);
		//cria os complexos c1 e c2
		struct tComplex c1 = complexo(re1, im1);
        struct tComplex c2 = complexo(re2, im2);
		struct tComplex res;
		//age conforme a operação selecionada
		switch (op) {
            case '+': res = soma(c1,c2);
                       break;
            case '-': res = sub(c1,c2);
                       break;
            case '*': res = mult(c1,c2);
                       break;
            case '/': res = div(c1,c2);
                       break;
        }
		if(res.im >=0)
			printf ("%d +%di\n", res.re, res.im);
		else
			printf ("%d %di\n", res.re, res.im);
    }
	return 0;
}