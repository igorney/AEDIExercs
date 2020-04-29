#include <stdio.h>
#include <stdlib.h>
// Recebe um vetor de inteiros e 3 indices para definir inicio e fim de cada subvetor.
void mergeSort (int *v, int esq, int meio, int dir) {
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
    free(vaux);
}
void print(int* v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d\n", v[i]);
    }
}
void insert(int *v, int n){
    int i;
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}
int main(){
    int *v;
    int q1, q2;
    scanf("%d %d", &q1, &q2);
    v = malloc((q1+q2) * sizeof(int));
    insert(v, q1+q2);
    //printf("--------------------------\n");
    mergeSort(v, 0, q1-1, q1+q2-1);
    print(v, q1+q2);
    //printf("--------------------------\n");
    free(v);
    return 0;
}