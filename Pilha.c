#include <stdio.h>
#include <stdlib.h>
typedef struct tPilha
{
    int *itens;
    int topo, tamanho;
}Pilha;
void iniciaPilha(Pilha *pilha, int n)
{
    pilha->itens = (int*)malloc(n*sizeof(int));
    pilha->topo = -1;
    pilha->tamanho = n;
}
void empilha(Pilha *pilha, int n)
{
    if( pilha->topo < pilha->tamanho)
    {
        pilha->topo++;
        pilha->itens[pilha->topo] = n;
    }
}
void desempilha(Pilha *pilha)
{
    if(pilha->topo != -1)
    {
        pilha->topo--;
    }
}
void topo(Pilha *pilha)
{
    int i;
    for(i = pilha->topo; i >= 0; i--)
    {
        printf("%d\n", pilha->itens[i]);
    }
}
void base(Pilha *pilha)
{
    int i;
    for(i = 0; i <= pilha->topo; i++)
    {
        printf("%d\n", pilha->itens[i]);
    }
}
int main()
{
    int n, num, i;
    char op;
    Pilha p;
    scanf("%d", &n);
    iniciaPilha(&p, n-1);
    while(scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
            case 'E':
                scanf(" %d", &num);
                empilha(&p, num);
            break;
            case 'D':
                desempilha(&p);
            break;
            case 'T':
                topo(&p);
            break;
            case 'B':
                base(&p);
            break;
        }
    }
    free(p.itens);
    return 0;
}