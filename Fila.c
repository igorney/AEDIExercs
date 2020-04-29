#include <stdio.h>
#include <stdlib.h>
typedef struct stFila
{
    int *itens;
    int inicio, fim, tamanho;
}Fila;
void iniciaFila(Fila *fila, int n)
{
    fila->itens = (int*)malloc(sizeof(int));
    fila->inicio = -1;
    fila->fim = -1;
    fila->tamanho = n;
}
void enfileirar(Fila *fila, int n)
{
    
}
void desenfileirar(Fila *fila)
{
    
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