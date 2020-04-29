#include <stdio.h>

int main(){
    int V, N;
    int perc, i;
    scanf("%d %d", &v, &n);

    for (i=1; i <= 9; i++) {
        perc = (i * V * N) / 10;
        if (i == 9) {
            if ((i * V * N) % 10) {
                printf("%d\n", perc+1);
            } else {
                printf("%d\n", perc);
            }
        } else {
            if ((i * V * N) % 10) {
                printf("%d ", perc+1);
            } else {
                printf("%d ", perc);
            }
        }
    }
    
    return 0;
}

