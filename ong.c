#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stItem
{
    char *dado;
    int repe;
    struct stItem *prox;
    struct stItem *ant;
}Item;
Item* inicarItem(char *n)
{
    Item *item = (Item*)malloc(sizeof(Item));
    if(item != NULL)
    {
        item->dado = (char*)malloc(100 * sizeof(char));
        strcpy(item->dado, n);
        item->repe = 1;
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
void imprime(Lista *lista) {
    Item *item = lista->prim;
    while (item != NULL) {
        printf("%s [%d]\n", item->dado, item->repe);
        item = item->prox;
    }
}
int listaVazia (Lista *l) {
    return l->qtd == 0;
}
void insere(Lista *lista, char *n)
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
        while (atual != NULL && strcmp(n , atual->dado) != 0) {
            ant = atual;
            atual = atual->prox;
            if(atual != NULL && strcmp(n , atual->dado) == 0){
                atual->repe++;
                return;
            }
        }
        // caso 2: inicio da lista
        if (ant == NULL) {
            if(atual != NULL && strcmp(n , atual->dado) == 0){
                atual->repe++;
                return;
            }
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
            if(atual != NULL && strcmp(n , atual->dado) == 0){
                atual->repe++;
                return;
            }
            novo->prox = atual;
            atual->ant = novo;
            ant->prox = novo;
            novo->ant = ant;
            lista->qtd++;
        }
        else
        {
            free(novo->dado);
            free(novo);
            return;
        }
    }
}
void ordena(Lista *lista, Item *item) {
    Item *aux = (Item*)malloc(sizeof(Item));
    if(item == lista->ult){
        free(aux);
        return;
    }
    else
    {
        //printf("%d\n", item->repe);
        // if(item->repe > item->prox->repe){ //se repeticao for maior que prox troca
        //     aux = item;
        //     item = item->prox;
        //     item->prox = aux;
        //     ordena(lista, item);
        // }
        free(aux);
        ordena(lista, item->prox);
    }
}
void excluir (Lista *l)
{
    if (!listaVazia (l)) {
        Item *atu = l->prim, *ant = NULL;
        while (atu != NULL) {
            ant = atu;
            free(ant->dado);
            free(ant);
            atu = atu->prox;
        }
    }
}
int main()
{
    Lista *lista = iniciaLista();
    char *op = (char*)malloc(100 * sizeof(char));
    while(scanf("%s", op) != EOF)
    {
        insere(lista, op);
    }
    //ordena(lista, lista->prim);
    imprime(lista);
    free(op);
    excluir(lista);
    free(lista);
    return 0;
}