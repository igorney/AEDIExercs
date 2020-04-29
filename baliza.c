#include <stdio.h>
#include <stdlib.h>

typedef struct stAtleta
{
    char nome[100];
    int min;
    int seg;
    int dec;
} Atleta;
int main()
{
    int n, m, i;
    Atleta *a;
    scanf("%d", &n);
    scanf("%d", &m);
    a = malloc(sizeof(Atleta) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", a[i].nome, &a[i].min, &a[i].seg, &a[i].dec);
        printf("%s %d %d %d", a[i].nome, a[i].min, a[i].seg, a[i].dec);
    }
    
    free(a);
    
    
return 0;
}