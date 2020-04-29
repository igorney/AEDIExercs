#include <stdio.h>
#include <stdlib.h>
void imprime(int *v, int n){
    for(int i = 0; i < n; i++){
        if(i == n-1) printf("%d\n", v[i]);
        else printf("%d ", v[i]);
    }
}
int particiona (int *v, int e, int d, int p, int n) {
    int i = e, pm = e-1;
    // troca v[p] <-> v[d]
    int tmp = v[p];
    v[p] = v[d];
    v[d] = tmp;
    p = d;
    while (i < d) {
        if (v[i] <= v[p]) {
            pm++;
            // troca v[i] <-> v[pm]
            tmp = v[i];
            v[i] = v[pm];
            v[pm] = tmp;
        }
        i++;
        imprime (v, n);
    }
    pm++;
    // troca v[p] <-> v[pm]
    tmp = v[i];
    v[i] = v[pm];
    v[pm] = tmp;
    imprime (v, n);
    return pm;
}
void quickSort (int *v, int e, int d, int n) {
    if (e < d) {
        int p = d;
        int pm = particiona (v, e, d, p, n);
        quickSort (v, e, pm-1, n);
        quickSort (v, pm+1, d, n);
    }
}
int main () {
    int n, i;
    scanf ("%d", &n);
    int *v = malloc (n * sizeof (int));
    for (i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    
    int e = 0, d = n-1;
    imprime (v, n);
    quickSort (v, e, d, n);
    imprime (v, n);
    
    free (v);
    return 0;
}
