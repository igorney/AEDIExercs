#include<stdio.h>
#include<stdlib.h>
struct Fila // Estrutura da Fila
{
    int *itens;
    int inicio, fim, tamanho;  
};
void iniciaFila (struct Fila *f, int n)
{
    if (f->tamanho != n)
    {
        f->itens = malloc(sizeof(int) * n);
        f->tamanho = n;
    }
    f->inicio = -1;
    f->fim = -1;
}
int checkVazia(struct Fila *f)
{
    if (f->inicio != -1 && f->inicio > f->fim) return 1;
    return 0;
}
void inserir(struct Fila *f, int x)
{
    if (f->fim != f->tamanho - 1)
    {
        if (f->inicio == -1 && f->fim == -1) f->inicio++;
        f->fim++;
        f->itens[f->fim] = x;
    }
}
int remover(struct Fila *f)
{
    int aux = -1;
    if (f->inicio != -1 && f->fim != -1)
    {
        aux = f->inicio;
        f->inicio++;
    }
    if (checkVazia(f)) iniciaFila(f, f->tamanho);
    return aux;
}
int maint(){
    return 0;
}