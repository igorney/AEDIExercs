#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(char* v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%c", v[i]);
    }
}
void insert(char *v, int n){
    int i;
    for(i = 0; i < n; i++){
        scanf(" %c", &v[i]);
    }
}
// Recebe um vetor de inteiros e 3 indices para definir inicio e fim de cada subvetor.
void mergeSort (char *v, int esq, int meio, int dir) {
    int n = dir - esq + 1;
    char *vaux = malloc (n * sizeof (char));
    int i = esq, j = meio+1, k = 0;
    while (i <= meio && j <= dir) {
        if (v[i] <= v[j]) {  // usamos <= para a implementacao no BOCA
            printf("%c : %c\n", v[i], v[j]);
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
int main(){
    char *v1, *v2, *v3;
    int q1, q2;

    scanf("%d", &q1);
    v1 = malloc((q1) * sizeof(char));
    insert(v1, q1);

    scanf("%d", &q2);
    v2 = malloc((q2) * sizeof(char));
    insert(v2, q2);

    v3 = malloc((q1+q2) * sizeof(char));
    strcat(v3, v1);
    strcat(v3, v2);
    
    printf("--------------------------\n");
    mergeSort(v3, 0, q1-1, q2-1);
    print(v3, q1+q2);
    printf("\n--------------------------");
    
    free(v1);
    free(v2);
    free(v3);

    return 0;
}