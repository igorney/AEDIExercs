#include <stdio.h>
#include <stdlib.h>

typedef struct pilha_s
{
    char **v;
    long long tam;
    long long qtElementos;
    
}pilha;

void inicializa(pilha* Pilha,long long N);
void empilha(pilha* Pilha,char* elemento);
void desempilha(pilha* Pilha);
void exibeTopo(pilha* Pilha);
void exibeBase(pilha* Pilha);
void exibeUltimo(pilha* Pilha);


int main()
{
    long long N;
    char op;
    pilha Pilha;
    char *elemento;
    int i;
    
    scanf("%lld", &N);
    
    inicializa(&Pilha, N);
    
    while(scanf(" %c", &op)!=EOF)
    {
        if(op == 'E')
        {
            scanf(" %s", elemento);
            empilha(&Pilha, elemento);
        }
        
        else if(op == 'D')
        {
            desempilha(&Pilha);
        }
        
        else if(op == 'X')
        {
            exibeTopo(&Pilha);
        }
        
        else if(op == 'B')
        {
            exibeBase(&Pilha);
        }
        
        else if(op == 'T')
        {
            exibeUltimo(&Pilha);
        }
        
    }
    
    free(Pilha.v);
    
    return 0;
}

void inicializa(pilha* Pilha,long long N)
{
    int i;
    
    Pilha->v = (char**) calloc(N,sizeof(char*));
    
    for(i=0;i<N;i++)
    {
        Pilha->v[i] = (char*) calloc(100,sizeof(char));
    }
    
    for(i=0;i<N;i++)
    {
        Pilha->v[i] = NULL;
    }
    
    Pilha->tam = N;
    Pilha->qtElementos = 0;
    
}

void empilha(pilha* Pilha,char* elemento)
{
    if(Pilha->qtElementos < Pilha->tam )
    {
        Pilha->v[Pilha->qtElementos] = elemento;
        Pilha->qtElementos++;
    }
}

void desempilha(pilha* Pilha)
{
    if(Pilha->qtElementos > 0)
    {
        Pilha->v[(Pilha->qtElementos)-1] = NULL;
        Pilha->qtElementos--;
    }
    
}

void exibeBase(pilha* Pilha)
{
    int i;
    for(i=0;i<(Pilha->qtElementos);i++)
    {
        i<((Pilha->qtElementos)-1)? printf("%s ", Pilha->v[i]) : printf("%s\n", Pilha->v[i]);
        //printf("%d\n", Pilha->v[i]);
    }
    
}

void exibeTopo(pilha* Pilha)
{
    int i;
    for(i=((Pilha->qtElementos)-1);i>=0;i--)
    {
        i!=0? printf("%s ", Pilha->v[i]) : printf("%s\n", Pilha->v[i]);
        //printf("%d\n", Pilha->v[i]);
    }
}

void exibeUltimo(pilha* Pilha)
{
    if(Pilha->qtElementos>0)
    {
        printf("%s\n", Pilha->v[(Pilha->qtElementos)-1]);
    }
    
}
