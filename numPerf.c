#include <stdio.h>

int main()
{
    long n, aux;
    long i;
    scanf("%ld", &n);

    aux = 0;
    for (i = 1; i < n; i++)
    {
        if((n%i == 0)){
            aux+=i;
        }
    }
    printf(aux == n ? "SIM\n" : "NAO\n");
    

return 0;
}