#include <stdio.h>

int buscaVetor(int vet[], int n, int busca);

int main()
{
    int n,i,aux;
    scanf("%d", &n);

    int vet[n];

    for(i=0;i<n;i++)
        scanf("%d", &vet[i]);

    scanf("%d", &aux);
    printf("%d\n", buscaVetor(vet, n, aux));
    
return 0;
}

int buscaVetor(int vet[], int n, int busca)
{
    int i, aux;


    for(i=0;i<n;i++)
    {
        if(vet[i]>=busca) aux++;
    }

    return aux;
}

