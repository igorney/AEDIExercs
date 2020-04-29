#include <stdio.h>
#include <stdlib.h>


int main(){
    int i, j, n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    int matriz[n][m]; //= malloc(m*sizeof(int));

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
//
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(j == n-1)
            {
                printf("%d\n", matriz[j][i]);
            }
            else
            {
                printf("%d ", matriz[j][i]);
            }
        }
    }
return 0;
}