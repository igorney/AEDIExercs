// gcc leituraAteEOF.c -o prog.exe

/*

Entrada:
1 2 3 4 5 6 7 8 9 10

(pressione CTRL+D para EOF)

*/

#include <stdio.h>

int main () {
    int soma = 0, x;
    while (scanf ("%d", &x) != EOF) {
        soma = soma + x;
    }
    printf ("%d\n", soma);
    return 0;
}
