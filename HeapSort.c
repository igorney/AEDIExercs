#include<stdio.h>
#include<stdlib.h>
int filhoE (int i) {
    return 2*i + 1;
}
int filhoD (int i) {
    return 2*i + 2;
}
int pai (int i) {
    return (i-1)/2;
}
int ultimoPai (int n) {
    return (n/2) - 1;
}
void troca (int *v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void peneirar (int *v, int n, int i) {
    int e = filhoE (i), d = filhoD (i), maior = e;
    if (e < n) {
        if (d < n && v[d] >= v[maior]) {
            maior = d;
        }
        if (v[i] < v[maior]) {
            troca (v, i, maior);
            peneirar (v, n, maior);
        }
    }
}

void constroiHeap (int *v, int n) {
    int u = ultimoPai (n), i;
    for (i = u; i >= 0; i--) {
        peneirar (v, n, i);
    }
}
void imprime (int *v, int n) {
    int i;
    for (i = 0; i < n-1; i++) {
        printf ("%d ", v[i]);
    }
    if (n > 0) {
        printf ("%d\n", v[n-1]);
    }
}

int selecionaMaximo (int *v, int n) {
    troca (v, 0, n-1);
    return n-1;
}

void heapSort (int *v, int n) {
    int i;
    constroiHeap (v, n);
    for (i = n-1; i >= 0; i--) {
        imprime (v, n);
        n = selecionaMaximo (v, n);
        peneirar (v, n, 0);
    }
}

int main () {
    int n, i;
    scanf ("%d", &n);
    int *v = malloc (n * sizeof (int));
    for (i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    imprime (v, n);
    heapSort (v, n);
    imprime (v, n);
    
    free (v);
    return 0;
}