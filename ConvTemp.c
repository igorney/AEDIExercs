#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    float r1, r2;
    scanf("%d %d %d", &a, &b, &c);
    r1 = -b + sqrt((b*b) - 4*a*c);
    r2 = -b - sqrt((b*b) - 4*a*c);
    printf("%f %f\n", r1, r2);
    
    return 0;
}