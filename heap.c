#include <stdio.h>
#include <stdlib.h>
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
void showHeap(int *v, int n){
    int i = 0;
    while(i < n){
        if(i == n)printf("%d\n", v[i]);
        else printf("%d ", v[i]);
        i++;
    }
}
int main(){
    int n, i;
    scanf("%d", &n);
    int *v;
    while (n != 0)
    {
        v = malloc(n * sizeof(int));
        for(i = 0; i < n; i++){
            scanf("%d", &v[i]);
            constroiHeap(v, n);
        }
        showHeap(v, n);
        scanf("%d", &n);
    }
    free(v);
    return 0;
}