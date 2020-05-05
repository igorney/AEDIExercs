#include <stdio.h>
#include <stdlib.h>

typedef struct stlista {
    int *items;
    int inicio, fim, tam;
} Lista;

void initList(Lista *lista, int tam) {
    lista->items = malloc(tam*sizeof(int));
    lista->inicio = 0;
    lista->fim = 0;
    lista->tam = tam;
}

void inserir(Lista *lista, int item) {
    int new_end = (lista->fim + 1)%(lista->tam);
    if (new_end != lista->inicio) {
        lista->items[lista->fim] = item;
        lista->fim = new_end;
    }
}

void remover(Lista *lista) {
    if (lista->inicio != lista->fim) {
        printf("%d\n", lista->items[lista->inicio]);
        if (lista->inicio < lista->tam) {
            int new_begin = (lista->inicio+1)%lista->tam;
            lista->inicio = new_begin;
        }
    }

}

int main() {
    Lista *lista = (Lista*)malloc(sizeof(lista));
    int tam, item;
    char op;
    scanf("%d", &tam);
    initList(lista, tam);

    while(scanf(" %c", &op) != EOF) {

        switch (op) {
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