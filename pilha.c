#include <stdio.h>
void empilha(int *v, int n, int *qtd)
{
    v[(*qtd)] = n;
    (*qtd)++;
}
void desempilha(int *v, int n, int *qtd)
{
    if((*qtd) == 0) return;
    v[(*qtd) - 1] = 0;
    (*qtd)--;
}
void topo(int *v, int qtd)
{
    int i;
    if(qtd > 0)
    {
        for(i = qtd-1; i >= 0; i--)
        {
            printf("%d\n", v[i]);
        }
    }
    
}
void base(int *v, int qtd)
{
    int i;
    if(qtd > 0)
    {
        for(i = 0; i < qtd; i++)
        {
            printf("%d\n", v[i]);
        }
    }
    
}
int main()
{
    int n, num, v[1000000], qtd = 0;
    char op;
    scanf("%d", &n);
    while(scanf(" %c %d", &op, &num) != EOF)
    {
        switch (op)
        {
            case 'E':
                empilha(v, num, &qtd);
            break;
            case 'D':
                desempilha(v, num, &qtd);
            break;
            case 'T':
                topo(v, qtd);
            break;
            case 'B':
                base(v, qtd);
            break;
        }
    }

    return 0;
}