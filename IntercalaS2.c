#include <stdio.h>
#include <stdlib.h>
// Recebe um vetor de inteiros e 3 indices para definir inicio e fim de cada subvetor.
void mergeSort (char *v, int esq, int meio, int dir) {
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
int main(){
    char *v3;
    int q1, q2;
    int i = 0;
    
    v3 = (char*)malloc(20000 * sizeof(char)); 
    scanf("%s", v3);
    scanf("%d", &q1);
    scanf("%d", &q2);
    //merge v3
    mergeSort(v3, 0, q1-1, q2-1);
    printf("%s\n", v3);
    
    free(v3);

    return 0;
}