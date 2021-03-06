#include <stdio.h>
void imprime(int *v, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(i == n-1)printf("%c\n", (char)v[i]);
        else printf("%c ", (char)v[i]);
    }
}
int buscaBinaria (int x, int n, int v[]) {
   int e, m, d; //Direita esquerda meio, começo meio e fim
   e = 0; d = n-1; //primeiro e ultimo
   while (e <= d) { 
      m = (e + d)/2; //meio
      if (v[m] == x) return m; //se for do meio acabo
      if (v[m] < x) e = m + 1; //se ele for menor que o meio 
      else d = m - 1;
   }
   return -1;
}
void inserir(int *v, int *qtd, int n)
{
    int i, j;
    if((*qtd) == 0)
    {
        v[0] = n;
        (*qtd)++;
        return;
    }
    else
    {   
        if(buscaBinaria(n, (*qtd), v) != -1) return; //se o número tiver na lista
        for(i = 0; i < (*qtd); i++)
        {
            if(n < v[i]) // se ele for menor ele vai pra essa posição
            {
                for(j = (*qtd); j > i; j--) //desloca os cara pra direita
                {
                    v[j] = v[j-1];
                }
                v[i] = n; //bota o número na posição
                (*qtd)++;
                return; //retorna
            }
        }
        v[i] = n; // i == qtd de itens, ou seja, ultima posição
        (*qtd)++;
        return;
    }
    
}
void remover(int *v, int *qtd, int n)
{
    int i, j;
    if(buscaBinaria(n, (*qtd), v) == -1) return; //se o número não tiver na lista
    else
    {
        i = buscaBinaria(n, (*qtd), v); //posição do canalha
        for(j = i; j < (*qtd); j++) //desloca os cara pra direita
        {
            v[j] = v[j+1];
        }
        (*qtd)--;
        return;
    }
}
int main()
{
    int i, q, v[30000], qtd = 0;
    char op, n;
    scanf("%d", &q);
    while (scanf(" %c", &op) != EOF)
    {
        //printf("%s", &op);
        switch (op)
        {
            case 'I':
                scanf(" %c", &n);
                inserir(v, &qtd, (int)n);
            break;
            case 'R':
                scanf(" %c", &n);
                remover(v, &qtd, (int)n);
            break;
            case 'B':
                scanf(" %c", &n);
                if(buscaBinaria((int)n, qtd, v) == -1) 
                    printf("NAO\n");
                else 
                    printf("SIM\n");
            break;
            case 'M':   
                scanf("%c", &n);
                imprime(v, qtd);
            break;
        }
    }
    
    return 0;
}