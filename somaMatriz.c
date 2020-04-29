#include <stdio.h>

int main()
{
    int n, i, j;
    int m1[100][100], m2[100][100];

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &m1[i][j]);

        }
    }
    //
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &m2[i][j]);

        }
    }
    //soma
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(j != n-1)
            {
                printf("%d ", m1[i][j]+m2[i][j]);
            }
            else
            {
                printf("%d\n", m1[i][j]+m2[i][j]);
            }
        }
    }
return 0;
}

