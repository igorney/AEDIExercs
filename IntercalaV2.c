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
int* merge(int* v1, int* v2, int q1, int q2, int q3){
    int i, j, k;
    int *v;
    for(i = 0, j = 0, k = 0; i < q3; i++){
        if(i < q1){
            v[i] = v1[j];
            j++;
        }
        else
        {
            v[i] = v2[k];
            k++;
        }
    }
    return v;
}
int main(){
    int *v1, *v2, *v3;
    int q1, q2, q3;

    scanf("%d %d", &q1, &q2);
    q3 = q1 + q2;
    v1 = malloc(q1 * sizeof(int));
    v2 = malloc(q2 * sizeof(int));
    v3 = malloc(q3 * sizeof(int));
    insert(v1, q1);
    insert(v2, q2);
    print(v1, q1);
    print(v2, q2);
    printf("--------------------------\n");
    v3 = merge(v1,v2,q1,q2, q3);
    print(v3, q3);
    printf("--------------------------\n");
    mergeSort(v3, 0, q1-1, q3-1);
    print(v3, q3);
    printf("--------------------------\n");
    free(v1);
    free(v2);
    free(v3);
    return 0;
}