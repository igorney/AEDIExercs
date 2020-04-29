#include <stdio.h>

int somaVetor(int vet[], int n);

int main()
{
    int n,i,aux;
    scanf("%d", &n);

    int vet[n];

    for(i=0;i<n;i++)
        scanf("%d", &vet[i]);

    printf("%ld\n", somaVetor(vet, n));
    
return 0;
}

long somaVetor(int vet[], int n)
{
    long i, soma;

    soma = 0;
    for(i=0;i<n;i++)
    {
        soma += vet[i];
    }

    return soma;
}

