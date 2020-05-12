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
    int e = filhoE (i), d = filhoD (i), menor = e;
    if (e < n) {
        if (d < n && v[d] <= v[menor]) {
            menor = d;
        }
        if (v[i] > v[menor]) {
            troca (v, i, menor);
            peneirar (v, n, menor);
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
    for(i = 0; i < n; i++){
        if(i == n-1) printf("%d\n", v[i]);
        else printf("%d ", v[i]);
    }
}
int searchPosition(int *v, int tam, int n){
    int i = 0;
    for(i = 0; i < tam; i++) if(v[i] == n) break; //search element position
    return i;
}
void removeHeap(int *v, int n, int tam){
    int i = searchPosition(v, tam, n);
    int aux;
    if(i < tam){
        while(i < tam){
            aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
            i++;
        }
    }
    else if(i == tam){
        return;
    }
}
int main(){
    int n, i, op, tam;
    scanf("%d", &tam);
    int *v = malloc(tam * sizeof(int));
    i = 0;
    while (scanf("%d", &op) != EOF)
    {
       switch (op)
       {
        case 1:
                scanf("%d", &n);
                v[i] = n; i++;
                constroiHeap(v, i);
                break;
        case 2:
                scanf("%d", &n);
                removeHeap(v, n, i);
                i--;
                break;
            case 3:
                constroiHeap(v, i);
                printf("%d\n", v[0]);
                break;
        default:
            break;
       }
    }
    free(v);
    return 0;
}