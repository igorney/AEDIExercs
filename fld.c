#include <stdio.h>
#include <stdlib.h>
typedef struct stItem
{
    int dado;
    struct stItem *prox;
    
}Item;
Item* criaItem(int n)
{
    Item *item = (Item*) malloc(sizeof(Item));
    if(item != NULL)
    {
        item->dado = n;
        item->prox = NULL;
    }
    return item;
}
typedef struct stFila
{
    Item *inicio;
    Item *fim;
}Fila;

Fila* criaFila(void)
{
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if(fila != NULL)
    {
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}
void inserir(Fila *fila, int n)
{
    Item *item = criaItem(n);
    if(fila->inicio == NULL && fila->fim == NULL)
    {
        fila->inicio = item;
        fila->fim = item;
    }
    else
    {
        (fila->fim)->prox = item;
        fila->fim = item;
    }
}
void imprimir(Fila *fila)
{
    Item *atual = fila->inicio;
    while (atual != NULL)
    {
        if(atual == fila->fim)printf("%d\n", atual->dado);
        else printf("%d ", atual->dado);
        atual = atual->prox;
    }
}
void excluir(Fila *fila)
{
    Item *aux = fila->inicio;
    if(fila->inicio == NULL) fila->fim = NULL;
    else fila->inicio = aux->prox;
    if(aux != NULL)printf("<%d>\n", aux->dado);
    free(aux);
}
int main()
{
    Fila *fila = criaFila();
    char op;
    int n;
    while(scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
            case 'E':
                scanf("%d", &n);
                inserir(fila, n);
            break;
            case 'M':
                scanf("%d", &n);
                imprimir(fila);
            break;
            case 'D':
                excluir(fila);
            break;
        }
    }
    free(fila);
    return 0;
}