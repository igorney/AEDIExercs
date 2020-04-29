#include <stdio.h>
#include <stdlib.h>
void imprime(int *v, int n){
    for(int i = 0; i < n; i++){
        if(i == n-1) printf("%d\n", v[i]);
        else printf("%d ", v[i]);
    }
}
// Recebe um vetor de inteiros e 3 indices para definir inicio e fim de cada subvetor.
void intercala (int *v, int esq, int meio, int dir) {
    int n = dir - esq + 1;
    int *vaux = malloc (n * sizeof (int));
    int i = esq, j = meio+1, k = 0;
    while (i <= meio && j <= dir) {
        if (v[i] <= v[j]) {  // usamos <= para a implementacao no BOCA
            vaux[k++] = v[i++];
        }
        else {
            vaux[k++] = v[j++];
        }
    }
    while (i <= meio) {
        vaux[k++] = v[i++];
    }
    while (j <= dir) {
        vaux[k++] = v[j++];
    }
    for (i = esq; i <= dir; i++) {
        v[i] = vaux[i-esq];  // note que os indices originais devem ser mantidos
    }
    free (vaux);
}
void mergeSort (int *v, int e, int d, int n) {
    int meio;
    if (e < d) {
        meio = (d+e)/2;
        mergeSort (v, e, meio, n);
        mergeSort (v, meio+1, d, n);
        imprime (v, n);
        intercala (v, e, meio, d);
    }
}

int main () {
    int n, v[10000], i;
    scanf ("%d", &n);
    for (i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    
    imprime(v, n);
    mergeSort (v, 0, n-1, n);
    imprime (v, n);
    
    return 0;
}