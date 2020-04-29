// caso de errado fazer busca binaria

#include <stdio.h>

int buscaVetor(int vet[], int n, int busca);

int main()
{
    int n,i,busca;
    scanf("%d", &n);

    int vet[n];

    for(i=0;i<n;i++)
        scanf("%d", &vet[i]);

    while(scanf("%d", &busca)==1)
    {
        if(buscaVetor(vet, n, busca)) printf("SIM\n");
        else printf("CHAVE NAO ENCONTRADA\n");
    }

    return 0;
}

int buscaVetor(int vet[], int n, int busca)
{
    int i;

    for(i=0;i<n;i++)
    {
        if(vet[i]==busca) return 1;
    }

    return 0;
}

