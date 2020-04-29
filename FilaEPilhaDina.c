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
typedef struct stPilha
{       
    int qtd;
    Item *topo;
}Pilha;

Pilha* iniciaPilha(void)
{
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha != NULL)
    {
        pilha->topo = NULL;
        pilha->qtd = 0;
    }
    return pilha;
}
void enfileirar(Fila *fila, int n)
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
void desenfileirar(Fila *fila)
{
    Item *aux = fila->inicio;
    if(fila->inicio == NULL) fila->fim = NULL;
    else fila->inicio = aux->prox;
    free(aux);
}
void imprimePilha(Pilha *pilha)
{
    Item *atual = pilha->topo;
    while (atual != NULL)
    {
        printf("%d\n", atual->dado);
        atual = atual->prox;
    }
}
// void imprimir(Fila *fila)
// {
//     Item *atual = fila->inicio;
//     while (atual != NULL)
//     {
//         printf("%d\n", atual->dado);
//         atual = atual->prox;
//     }
// }
void igualar(Fila *fila, Pilha *pilha){
    pilha->topo = fila->inicio;
}
int main(){
     int tam, num;
    char op;
    scanf("%d", &tam);
    Pilha *pilha = iniciaPilha();
    Fila *fila = criaFila();
    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
            case 'E':
                scanf("%d", &num);
                enfileirar(fila, num);
            break;
            case 'D':
                desenfileirar(fila);
            break;
            case 'P':
                igualar(fila, pilha);
            break;
            case 'M':
                imprimePilha(pilha);
            break;
        }
    }
    free(fila);
    free(pilha);
    return 0;
}