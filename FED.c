#include<stdio.h>
#include<stdlib.h>
struct Fila
{
    struct Item *inicio, *fim;
};
struct Fila * criaFila()
{
    struct Fila *fila = (struct Fila*) malloc(sizeof(struct Fila));
    if (fila != NULL)
    {
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}
struct Item
{
    int dado;
    struct Item *proximo;
}
struct Item * criaItem(int dado)
{
    struct Item * it = (struct Item*) malloc(sizeof(struct Item));
    if (it != NULL)
    {
        it->dado = dado;
        it->proximo = NULL;
    }
    return it;
}
void enfileirar(struct Fila *f, int dado)
{
    struct Item *novo = criaItem(dado);
    if (f->inicio == NULL)
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->prox = novo;
    }
    f->fim = novo;
}
int desenfileirar(struct Fila *f)
{
    if (f->inicio != NULL)
    {
        struct Item *atual = f->inicio;
        printf("<%d>\n", f->inicio->dado);
        f->inicio = f->inicio->prox;
        free(atual);
        if(f->inicio == NULL) f->fim == NULL;
    }
}
void destroiFila(struct Fila * f)
{
    if (f != NULL)
    {
        struct Item *atual;
        while(f->inicio != NULL)
        {
            atual = f->inicio;
            f->inicio = f->inicio->prox;
            free(atual);
        }
        free(f);
    }
}
void mostrar(struct Fila *f)
{
    if (f->inicio != NULL)
    {
        struct Item *atual = f->inicio;
        while(atual != NULL)
        {
            if (atual->prox == NULL) printf("%d\n", atual->dado);
            else printf("%d ", atual->dado);
            atual = atual->prox;
        }
    }
}
int maint(){
    return 0;
}