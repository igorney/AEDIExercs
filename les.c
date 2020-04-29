#include <stdio.h>
#include <stdlib.h>

typedef struct tLes
{
    int *itens;
    int quatidade;
    int tamanho;
}Les;
void iniciaLista(Les *A, int n)
{
    int i;
    A->itens = (int*)malloc(sizeof(int) * n);
    A->quatidade = 0;
    A->tamanho = n;
    for(i = 0; i < n; i++)
    {
        A->itens[i] = 0;
    }
}
void insereLista(Les *A, int n)
{
    int i;
    for(i = 0; i < A->tamanho; i++)
    {

        if(A->itens[i] == n)
        {
            break;
        }
        else if(A->itens[i] == 0)
        {
            A->itens[i] = n;
            A->quatidade++;
            break;
        }
    }
}
void removeLista(Les *A, int n)
{
    int i;
    for(i = 0; i < A->tamanho; i++)
    {
        if(n == A->itens[i])
        {
            A->itens[i] = 0;
            A->quatidade--;
        }
    }  
}
void ordenaLista(Les *A)
{
    int i, j, aux;
    for(i = 0; i < A->tamanho-1; i++)
    {
        for(j = 0; j < A->tamanho-1-i; j++)
        {
            if((A->itens[j] > A->itens[j+1]))
            {
                aux = A->itens[j];
                A->itens[j] = A->itens[j+1];
                A->itens[j+1] = aux;
            }
        }
    }
}
int main()
{
    int tam, i, num;
    char o;
    Les *A;
    int count = 0;
    scanf("%d", &tam);
    iniciaLista(A, tam);
    scanf("%c %d", &o, &num);
    while (count < tam)
    {
        if(o == 'I')
        {
            insereLista(A, num);
            count++;
        }
        else if(o == 'E')
        {
            removeLista(A, num);
            count++;
        }
        scanf("%c %d", &o, &num);
    }
    ordenaLista(A);
    for (i = 0; i < A->tamanho; i++)
    {
        if(A->itens[i] != 0)printf("%d\n", A->itens[i]);
    }
    
    free(A->itens);
    return 0;
}