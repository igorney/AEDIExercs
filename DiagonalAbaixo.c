#include <stdio.h>
#define T 3
int main(){
    int n;
    char o;
    int i, j;
    float soma=0.0, aux=0.0;
    float m[T][T];

    scanf("%c", &o);

    if(o == 'S'){
        for(i=0; i<T; i++){
            for(j=0; j<T; j++){
                scanf("%f", &m[i][j]);
                if(i<j){
                    soma += m[i][j];
                    aux++;
                }
            }
        }
        printf("%.1f\n", soma);
    }
    else if(o == 'M'){
        for(i=0; i<T; i++){
            for(j=0; j<T; j++){
                scanf("%f", &m[i][j]);
                if(j>i-j-1){
                    soma += m[i][j];
                    aux++;
                }
            }
        }
        printf("%.1f\n", soma/aux);
    }
    return 0;
}
