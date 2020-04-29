#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *itens;
  int qtde;
  int size;
} lista;

void iniciaLista (lista* list, int size){
  list->itens = malloc(sizeof(lista)*300000);
  list->qtde = 0;
  list->size = size;
}

int buscaLinear (lista* list, int x){
  for (int i=0; i<list->qtde; i++){
    if (list->itens[i]==x)
      return i;
  }
  return -1;
}

void deslocaR (lista* list, int i){
  for (int k=list->qtde;k>i;k--)
    list->itens[k]=list->itens[k-1];
}

void deslocaL (lista* list, int i){
  for (;i<list->qtde-1;i++)
    list->itens[i]=list->itens[i+1];
}

void inserir(lista* list, int x){
  if (list->qtde==0){
    list->itens[0]=x;
    list->qtde++;
  } else {
    for (int i=0;i<list->qtde && x!=list->itens[i];i++){
      if (x<list->itens[i]){
        deslocaR(list, i);
        list->itens[i]=x;
        list->qtde++;
        break;
      } else if (i==list->qtde-1){
        list->itens[list->qtde] = x;
        list->qtde++;
        break;
      }
    }
  }
}

void remover (lista* list, int x){
  int pos = buscaLinear(list,x);
  if (pos>=0){
    deslocaL(list,pos);
    list->itens[list->qtde]=0;
    list->qtde--;
  }
}

void imprimirLista (lista* list){
  for (int i=0;i<list->qtde;i++)
    printf("%d\n", list->itens[i]);
}

int main(void) {
  lista *list = malloc(sizeof(lista));
  int size;
  scanf("%d", &size);
  iniciaLista(list,size);
  int n = size;
  while (n>0){
    char op;
    scanf(" %c", &op);
    int x;
    scanf("%d", &x);
    switch (op){
      case 'I':
        inserir(list,x);
        break;
      case 'E':
        remover(list,x);
        break;
    }

    n--;
  }

  imprimirLista(list);
}