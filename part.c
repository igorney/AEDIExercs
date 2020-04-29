#include <stdio.h>
#include <stdlib.h>
void imprime(int *v, int n, int p){
    
    for(int i = 0; i < p; i++){
        printf("%d\n", v[i]);
    }
    for(int i = p; i < n; i++){
        printf("%d\n", v[i]);
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
    }
    pm++;
    // troca v[p] <-> v[pm]
    tmp = v[i];
    v[i] = v[pm];
    v[pm] = tmp;
    return pm;
}
int main () {
    int n, i, p;
    scanf ("%d", &n);
    scanf ("%d", &p);
    int *v = malloc (n * sizeof (int));
    for (i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    
    int e = 0, d = n-1;
    p = particiona (v, e, d, p, n);
    imprime(v, n, p);
    
    free (v);
    return 0;
}
