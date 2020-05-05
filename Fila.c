#include <stdio.h>
#include <stdlib.h>

typedef struct stlista {
    int *items;
    int inicio, fim, tam;
} Lista;

void initList(Lista *lista, int tam) {
    lista->items = malloc(tam*sizeof(int));
    lista->inicio = -1;
    lista->fim = -1;
    lista->tam = tam;
}

void inserir(Lista *lista, int item) {
    if (lista->fim < (lista->tam)-1) {
        lista->fim++;
        lista->items[lista->fim] = item;

        if (lista->inicio == -1) {
            lista->inicio++;
        }
    }
}

void remover(Lista *lista) {
    if (lista->inicio > -1) {
        printf("%d\n", lista->items[lista->inicio]);
        if (lista->inicio < lista->tam) {
            lista->inicio++;
            if (lista->inicio == lista->fim+1) {
                lista->inicio = -1;
                lista->fim = -1;
            }
        }
    }

}

int main() {
    Lista *lista = (Lista*)malloc(sizeof(lista));
    int tam, item;
    char option;
    scanf("%d", &tam);
    initList(lista, tam);

    while(scanf(" %c", &option) != EOF) {

        switch (option) {
        case('E'):
                scanf("%d", &item);
                inserir(lista, item);
            break;
        case('D'):
                remover(lista);
            break;
        }
    
    }
    free(lista);
    return 0;
}