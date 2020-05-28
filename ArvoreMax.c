//gcc 7.4.0

#include  <stdio.h>
#include  <stdlib.h>

typedef struct tNo {
    int chave;
    struct tNo *pai, *esq, *dir;
} No;

No *criaNo (int x) {
    No *novo = malloc (sizeof (No));
    novo->chave = x;
    novo->pai = novo->esq = novo->dir = NULL;
    return novo;
}

typedef struct tArvore {
    No *raiz;
    int quantidade;
} Arvore;

Arvore *criaArvore () {
    Arvore *t = malloc (sizeof (Arvore));
    t->raiz = NULL;
    t->quantidade = 0;
    return t;
}
int arvoreVazia(Arvore *arv){
    return arv->quantidade == 0;
}
void Inserir (Arvore *arv, int x) {
    No *novo = criaNo (x);
    // caso particular: arvore vazia
    if (arvoreVazia (arv)) {
        arv->raiz = novo;
        arv->quantidade++;
    }
    // caso geral: arvore nao vazia
    else {
        // busca posicao de insercao na ABB
        No *pai = NULL;
        No *filho = arv->raiz;
        while (filho != NULL) {
            pai = filho;
            if (x > filho->chave) {
                filho = filho->dir;
            }
            else if(x != filho->chave) { // modificar se nao quiser inserir chaves repetidas!
                filho = filho->esq;
            }
        }
        // Neste ponto, temos que filho == NULL e pai != NULL.
        if (x > pai->chave) {
            pai->dir = novo;
        }
        else {
            pai->esq = novo;
        }
        novo->pai = pai;
        arv->quantidade++;
    }
}
int main(void)
{
    Arvore *arvore = criaArvore();
    int n, i, num;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        Inserir(arvore, num);
    }
    No *filho = arvore->raiz;
    int maior = 0;
    while (filho != NULL) {
        if(filho->chave > maior){
            maior = filho->chave;
        }
        filho = filho->dir;
    }
    printf("%d\n", maior);
    free(arvore);
    free(filho);
}