#include <stdio.h>
#include <stdlib.h>

typedef struct stCompetidor{
    int id;
    char nome[100];
    int min;
    int seg;
    int dec;
    int tempo;
} Competidor;
void ordenaTempo (Competidor *A, int n)
{
    Competidor aux;
    int i, j;
    for(i = n-1; i == 0; i--)
    {
        if(A[i].tempo == 0)
        {
            aux = A[i];
            A[i] = A[j+1];
            A[j+1] = aux;
        }
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if((A[j].tempo > A[j+1].tempo))
            {
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
}
void series(Competidor *A, int n, int s)
{
    int i, aux;
    if(n <= s)
    {
        printf("1a. serie\n");
        if(s%2 == 0) s--;
        for(i = s-1; i < n; i++)
        {   
            printf("%s\n", A[i].nome);
        }
        for(i = 0; i < n-s; i++)
        {   
            printf("%s\n", A[i].nome);
        }
    }
    else
    {
        printf("%da. series\n", (n/s) + 1);
        if(s%2 == 0) s--;
        for(i = s; i < n; i++)
        {   
            printf("%s\n", A[i].nome);
        }
        printf("%d series\n", (n/s) + 1);
        for(i = 0; i < n-(n%s); i++)
        {   
            printf("%s\n", A[i].nome);
        }
    }
}
int main()
{
    Competidor *A;
    int raias, comps;
    int i, aux;
    scanf("%d %d", &raias, &comps);
    A = malloc(sizeof(Competidor) * comps);
    aux = 0;
    for(i = 0; i < comps; i++)
    {   
        A[i].id = ++aux;
        scanf("%s %d %d %d", A[i].nome, &A[i].min, &A[i].seg, &A[i].dec);
        A[i].tempo = A[i].min*60000 + A[i].seg*60 + A[i].dec;
        if (A[i].tempo == 0)
        {
            A[i].tempo = A[i].id*6000000;
        }
    }
    ordenaTempo(A, comps);
    series(A, comps, raias);
    
    free(A);
    return 0;
}