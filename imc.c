#include <stdio.h>

int main()
{
    double h, m, imc;
    scanf("%lf %lf", &h, &m);
    imc = m/(h*h);
    printf((imc < 16) ? "Magreza grave\n" : 
    ((imc >= 16) && (imc < 17)) ? "Magreza moderada\n" : 
    ((imc >= 17) && (imc < 18.5)) ? "Magreza leve\n" :
    ((imc >= 18.5) && (imc < 25)) ? "Saudavel\n" :
    ((imc >= 25) && (imc < 30)) ? "Sobrepeso\n" :
    ((imc >= 30) && (imc < 35)) ? "Obesidade Grau I\n" :
    ((imc >= 35) && (imc < 40)) ? "Obesidade Grau II (severa)\n" :
    "Obesidade Grau III (morbida)\n");
    return 0;
}