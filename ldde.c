#include <stdio.h>
#include <stdlib.h>
typedef struct stItem
{
    int dado;
    struct stItem *prox;
    struct stItem *ant;
}Item;
Item* inicarItem(int n)
{
    Item *item = (Item*)malloc(sizeof(Item));
    if(item != NULL)
    {
        item->dado = n;
        item->prox = NULL;
        item->ant = NULL;
    }
    return item;
}
typedef struct stLista
{
    Item *prim;
    Item *ult;
    int qtd;
}Lista;
Lista* iniciaLista(void)
{
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    if(lista != NULL)
    {
        lista->prim = NULL;
        lista->ult = NULL;
        lista->qtd = 0;
    }
    return lista;
}
void imprime(Lista *l) {
    Item *item = l->prim;
    int i = 0;
    if(l->qtd == 1){
        printf("%d\n", item->dado);
        return;
    }
    while(i < l->qtd-1) {
        printf ("%d ", item->dado);
        item = item->prox;
        i++;
        if (l->qtd-1 == i){
            printf ("%d\n", item->dado);
            return;
        }
    }
}
void exprime(Lista *l) {
    Item *item = l->ult;
    int i = 0;
    if(l->qtd == 1){
        printf("%d\n", item->dado);
        return;
    }
    while(i < l->qtd-1) {
        printf ("%d ", item->dado);
        item = item->ant;
        i++;
        if (l->qtd-1 == i){
            printf ("%d\n", item->dado);
            return;
        }
    }
}
int listaVazia (Lista *l) {
    return l->qtd == 0;
}
void insere(Lista *lista, int n)
{
    Item *novo = inicarItem(n);
    // Caso 1: lista vazia
    if (listaVazia (lista)) {
        lista->prim = novo;
        lista->ult = novo;
        lista->qtd++;
    }
    else {
        // procurar posicao de insercao
        Item *atual = lista->prim, *ant = NULL;
        while (atual != NULL && n > atual->dado) {
            ant = atual;
            atual = atual->prox;
        }
        // caso 2: inicio da lista
        if (ant == NULL) {
            novo->prox = atual;
            lista->prim = novo;
            atual->ant = novo;
            lista->qtd++;
        }
        // caso 3: fim da lista
        else if (atual == NULL) {
            ant->prox = novo;
            novo->ant = ant;
            lista->ult = novo;
            lista->qtd++;
        }
        // caso 4: meio da lista n != atu->chave &&
        else if (ant != NULL) { 
            novo->prox = atual;
            atual->ant = novo;
            ant->prox = novo;
            novo->ant = ant;
            lista->qtd++;
        }
        else
        {
            free(novo);
            return;
        }
        
    }
}
void excluir (Lista *l, int x)
{
    if (!listaVazia (l)) {
        // procurar posicao 
        Item *atu = l->prim, *ant = NULL;
        while (atu != NULL && x >= atu->dado) {
            //printf("Ant: %p e Atual: %d\n", ant, atu->chave);
            //caso 2: inicio da lista
            if(ant == NULL && x == atu->dado)
            {
                if(atu->prox != NULL){
                    l->prim = atu->prox;
                    (atu->prox)->ant = atu->ant;
                    free(atu);
                    l->qtd--;
                    return;
                }
                else{
                    l->prim = NULL;
                    l->ult = NULL;
                    //(atu->prox)->ant = atu->ant;
                    free(atu);
                    l->qtd--;
                    return;
                }
                
            }
            //caso 3: fim da fila
            else if (ant != NULL && x == atu->dado && atu->prox == NULL)
            {
                ant->prox = atu->prox;
                l->ult = atu->ant;
                free(atu);
                l->qtd--;
                return;
            }
            //caso meio da lista
            else if(x == atu->dado && atu->prox != NULL)
            {
                ant->prox = atu->prox;
                (atu->prox)->ant = atu->ant;
                free(atu);
                l->qtd--;
                return;
            }
            ant = atu;
            atu = atu->prox;
        }
    }
}
int main()
{
    Lista *lista = iniciaLista();
    int n;
    char op;
    while(scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
        case 'I':
            scanf("%d", &n);
            insere(lista, n);
        break;
        case 'E':
            scanf("%d", &n);
            excluir(lista, n);
        break;
        case 'M':
            imprime(lista);
        break;
        case 'R':
            exprime(lista);
        break;
        }
    }
    free(lista);
    return 0;
}