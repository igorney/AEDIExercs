#include <stdio.h>

int main()
{
    long n, aux;
    long i;
    scanf("%ld", &n);
    aux = n;
    while (n >= 0)
    {
        if (n < aux)
            aux = n;
        scanf("%ld", &n);
    }
   
    printf(aux < 0 ? "nenhum numero informado\n" :
     "%ld\n", aux);
    

return 0;
}