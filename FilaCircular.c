#include <stdio.h>
#include <stdlib.h>
typedef struct stFila
{
    int *itens;
    int inicio, fim, tamanho;
}Fila;
void iniciaFila(Fila *fila, int n)
{
    fila->itens = (int*)malloc(n*sizeof(int));
    fila->inicio = -1;
    fila->fim = -1;
    fila->tamanho = n;
}
void enfileirar(Fila *fila, int n)
{
    if(fila->inicio == -1 && fila->fim == -1)
    {
        fila->fim++;
        fila->itens[fila->fim] = n;
        fila->inicio++;
    }
    else if(fila->fim < fila->tamanho-1)
    {
        fila->fim++;
        fila->itens[fila->fim] = n;
    }
    //printf("Elemento: %d, Posição: %d\n", fila->itens[fila->fim], fila->fim);
}
void desenfileirar(Fila *fila)
{
    int n;
    if(!(fila->inicio == -1 && fila->fim == -1))
    {
        n = fila->itens[fila->inicio];
        fila->inicio++;
        printf("%d\n", n);
        if(fila->inicio > fila->fim)
        {
            fila->inicio = -1;
            fila->fim = -1;
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
    free(fila.itens);


    return 0;
}