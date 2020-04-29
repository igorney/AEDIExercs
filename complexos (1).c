#include <stdio.h>
typedef struct stPonto {
    long x;
    long y;
} Ponto;
Ponto operacao(Ponto a, Ponto b, char x)
{
    Ponto p;
    if (x == '+')
    {   
        p.x =  a.x + b.x;
        p.y = a.y + b.y;
        return p;
    }
    else if (x == '-')
    {
        p.x = a.x - b.x;
        p.y = a.y - b.y;
        return p;
    }
    else if (x == '*')
    {
        p.x =  a.x * b.x;
        p.y = a.y * b.y;
        return p;
    }
    else if (x == '/')
    {
        p.x = a.x / b.x;
        p.y = a.y / b.y;
        return p;
    }
    
}
int main()
{
    Ponto p1, p2, r;
    char op;
    while (1)
    {
        scanf("%ld %ldi %c %ld %ldi", &p1.x, &p1.y, &op, &p2.x, &p2.y);
        r = operacao(p1, p2, op);
        printf("%ld %ldi\n", r.x, r.y);
    }

return 0;
}