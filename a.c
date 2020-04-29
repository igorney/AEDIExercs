#include <stdio.h>
#include <stdlib.h>

typedef struct stCompetidor{
    int id;
    char nome[100];
    int min;
    int seg;
    int dec;
} Competidor;
void ordenaTempo (Competidor *A, int comps)
{
    int aux, temp;
    while()
    {

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
    }
    ordenaTempo(&A, comps);

    free(A);
    return 0;
}