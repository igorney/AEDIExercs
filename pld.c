#include <stdio.h>
#include <stdlib.h>
typedef struct stItem
{       
    int dado;
    struct stItem *anterior;
}Item;

Item* criarItem(int x)
{
    Item *item = (Item*)malloc(sizeof(Item));
    if(item != NULL)
    {
        item->dado = x;
        item->anterior = NULL;
    }
    return item;
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
void imprimePilha(Pilha *pilha)
{
    Item *item = pilha->topo;
    int i;
    for (i = 0; i < pilha->qtd-1; i++) {
        printf ("%d ", item->dado);
        item = item->anterior;
    }
    if (pilha->qtd > 0) {
        printf ("%d\n", item->dado);
    }
}
void empilha(int num, Pilha *pilha)
{
    Item *item = criarItem(num);
    item->anterior = pilha->topo;
    pilha->topo = item;
    pilha->qtd++;
    //imprimePilha(pilha);
}
void desempilha(Pilha *pilha)
{
    if(pilha->qtd == 0) return;
    Item *item = pilha->topo;
    int num = item->dado;
    pilha->topo = item->anterior;
    free(item);
    pilha->qtd--;
    printf("[%d]\n", num);
}
int main()
{
    char op;
    int num;
    Pilha *pilha = iniciaPilha();
    while(scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
            case 'E':   
                scanf("%d", &num);
                empilha(num, pilha);
            break;
            case 'D':   
                desempilha(pilha);
            break;
            case 'M':   
                imprimePilha(pilha);
            break;
        }
    }
    free(pilha);
    return 0;
}

