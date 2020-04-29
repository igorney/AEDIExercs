#include <stdio.h>
#define T 100
int main(){
    char o;
    int i, j;
    float soma=0.0, aux=0.0;
    int m[T][T], n;

    scanf("%c", &o);
    scanf("%d", &n);

    if(o == 'S'){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf("%d", &m[i][j]);
                if(i>j){
                    soma += m[i][j];
                    aux++;
                }
            }
        }
        printf("%.1f\n", soma);
    }
    else if(o == 'M'){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf("%d", &m[i][j]);
                if(i>j){
                    soma += m[i][j];
                    aux++;
                }
            }
        }
        printf("%.1f\n", soma/aux);
    }
    return 0;
}