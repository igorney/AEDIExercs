// gcc lde.c -o prog.exe

#include <stdio.h>
#include <stdlib.h>

typedef struct tItem {
    int chave;
    struct tItem *prox;
} Item;

Item *criaItem (int x) {
    Item *novo = malloc (sizeof (Item)); 
    novo->chave = x;
    novo->prox = NULL;
    return novo;
}

typedef struct tLista {
    int q;
    Item *ini;
}Lista;

Lista *criaLista () {
    Lista *l = malloc (sizeof (Lista));
    l->q = 0;
    l->ini = NULL;
    return l;
}

void imprime (Lista *l) {
    Item *it = l->ini;
    int i;
    for (i = 0; i < l->q-1; i++) {
        printf ("%d ", it->chave);
        it = it->prox;
    }
    if (l->q > 0) {
        printf ("%d\n", it->chave);
    }
}

int listaVazia (Lista *l) {
    return l->q == 0;
}

void inserir (Lista *l, int x) {
    Item *novo = criaItem (x);
    // Caso 1: lista vazia
    if (listaVazia (l)) {
        l->ini = novo;
        l->q++;
    }
    else {
        // procurar posicao de insercao
        Item *atu = l->ini, *ant = NULL;
        while (atu != NULL && x > atu->chave) {
            ant = atu;
            atu = atu->prox;
        }
        // caso 2: inicio da lista
        if (ant == NULL) {
            novo->prox = l->ini;
            l->ini = novo;
            l->q++;
        }
        // caso 3: fim da lista
        else if (atu == NULL) {
            ant->prox = novo;
            l->q++;
        }
        // caso 4: meio da lista
        else if (x != atu->chave) {
            ant->prox = novo;
            novo->prox = atu;
            l->q++;
        }
    }
}
void excluir (Lista *l, int x)
{
    if (!listaVazia (l)) {
        // procurar posicao de insercao
        Item *atu = l->ini, *ant = NULL;
        while (atu != NULL && x >= atu->chave) {
            //printf("Ant: %p e Atual: %d\n", ant, atu->chave);
            //caso 2: inicio da lista
            if(ant == NULL && x== atu->chave)
            {
                l->ini = atu->prox;
                free(atu);
                l->q--;
                return;
            }
            //caso 3: fim da fila
            else if (ant != NULL && x == atu->chave)
            {
                ant->prox = atu->prox;
                free(atu);
                l->q--;
                return;
            }
            ant = atu;
            atu = atu->prox;
        }
    }
}
void busca(Lista *l, int x)
{
    // procurar o canalha
    Item *atu = l->ini, *ant = NULL;
    while (atu != NULL && x >= atu->chave) 
    {
        //printf("Busca: %d\n", atu->chave);
        if(atu->chave == x)
        {
            printf("SIM\n");
            return;
        }
        ant = atu;
        atu = atu->prox;
    }
    printf("NAO\n");
}
int main () {
    char op;
    int x;
    Lista *l = criaLista ();
    while (scanf (" %c", &op) != EOF) {
        switch (op) {
            case 'I': scanf ("%d", &x);
                      inserir (l, x);
                      break;
            case 'R': scanf ("%d", &x);
                      excluir(l, x);
                      break;
            case 'B': scanf ("%d", &x);
                      busca(l, x);
                      break;
            case 'L': imprime (l);
                      break;
        }
    }
    return 0;
}
