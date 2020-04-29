#include <stdio.h>

int main()
{
    long n, divpar;
    long i;
    scanf("%ld", &n);

    divpar = 0;
    for (i = 1; i <= n; i++)
    {
        if((n%i == 0) && (i%2 == 0)){
            divpar++;
        }
    }
    printf("%ld\n", divpar);
    

return 0;
}