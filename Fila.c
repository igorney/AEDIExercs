#include <stdio.h>
#include <stdlib.h>
typedef struct stFila
{
    int *items;
    int inicio, fim, tamanho;
}Fila;
void iniciaFila(Fila *fila, int n)
{
    fila->items = (int*)malloc(sizeof(int));
    fila->inicio = -1;
    fila->fim = -1;
    fila->tamanho = n;
}
void enfileirar(Fila *fila, int n)
{

     if (fila->fim < (fila->tamanho)-1) {
        fila->fim++;
        fila->items[fila->fim] = n;

        if (fila->inicio == -1) {
            fila->inicio++;
        }
    }
}
void desenfileirar(Fila *fila)
{
     if (fila->inicio > -1) {
        printf("%d\n", fila->items[fila->inicio]);
        if (fila->inicio < fila->tamanho) {
            fila->inicio++;
            if (fila->inicio == fila->fim+1) {
                fila->inicio = -1;
                fila->fim = -1;
            }
        }
    }
}

int main()
{
    int tam, num;
    char op;
    Fila fila;
    scanf("%d", &tam);
    iniciaFila(&fila, tam);
    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
            case 'E':
                scanf("%d", &num);
                enfileirar(&fila, num);
            break;
            case 'D':
                scanf("%d", &num);
                desenfileirar(&fila);
            break;
        }
    }
    


    return 0;
}