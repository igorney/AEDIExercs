#include <stdio.h>
#include <stdlib.h>
typedef struct stFila
{
    int *items;
    int inicio, fim, tamanho;
}Fila;
void iniciaFila(Fila *fila, int n)
{
    fila->items = (int*)malloc(n*sizeof(int));
    fila->inicio = -1;
    fila->fim = -1;
    fila->tamanho = n;
}
void enfileirar(Fila *fila, int n)
{
    int aux = (fila->fim + 1)%(fila->tamanho);
    if (aux != fila->inicio) {
        fila->items[fila->fim] = n;
        fila->fim = aux;
    }
}
void desenfileirar(Fila *fila)
{
    if (fila->inicio != fila->fim) {
        printf("%d\n", fila->items[fila->inicio]);
        if (fila->inicio < fila->tamanho) {
            int aux = (fila->inicio+1)%fila->tamanho;
            fila->inicio = aux;
        }
    }
}
int main()
{
    int tam, num;
    char op;
    Fila *fila;
    scanf("%d", &tam);
    iniciaFila(fila, tam);
    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
            case 'E':
                scanf("%d", &num);
                enfileirar(fila, num);
            break;
            case 'D':
                scanf("%d", &num);
                desenfileirar(fila);
            break;
        }
    }
    // free(fila->items);


    return 0;
}