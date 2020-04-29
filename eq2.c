#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    double r1, r2;
    double delta;

    scanf("%d %d %d", &a, &b, &c);
    delta = (b*b) - (4*a*c);
    r1 = ((-b) + sqrt(delta)) / (2*a);
    r2 = ((-b) - sqrt(delta)) / (2*a);

    printf("%.4lf %.4lf\n", r1, r2);
    
    return 0;
}