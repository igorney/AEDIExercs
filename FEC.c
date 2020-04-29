#include<stdio.h>
#include<stdlib.h>
struct FilaC
{
    int itens[tamanho];
    int inicio, fim;
}
void iniciaFilaC(struct FilaC *fila)
{
    fila->inicio = 0;
    fila->fim = 0;
}
void inserir(struct FilaCircular *fila, int x)
{
    if (fila->quantidade == fila->tamanho - 1) return;
    fila->fim = (fila->fim + 1) % fila->tamanho;
    if (fila->quantidade == 0)
    {
        fila->inicio = (fila->inicio + 1) % fila->tamanho;
        fila->itens[fila->inicio] = x;
    }
    else
    {
        fila->itens[fila->fim] = x;
    }
    fila->quantidade++;
}
int remover(struct FilaCircular *fila)
{
    if (fila->inicio != -1)
    {
        int aux = fila->itens[fila->inicio];
        fila->inicio = (fila->inicio + 1) % fila->tamanho;
        fila->quantidade--;
        if (fila->quantidade == 0) iniciaFilaCircular(fila, fila->tamanho);
        return aux;
    }
    return -1;
}
int maint(){
    return 0;
}