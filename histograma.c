#include <stdio.h>

#define TAM 10


void imprimeHistograma(int pos, int qtde){

    int cont;

    printf("[%2d]=",pos);

        for(cont=0;cont<qtde;cont++){

            printf("*");

        }

    printf("\n");

}


int main()
{

    int valores[TAM];

    int pos;

    for (pos = 0; pos < TAM; pos++){

        scanf("%d",&valores[pos]);

    }
    // mostrar o histograma
    
    for(pos=0;pos<TAM;pos++){

        imprimeHistograma(pos, valores[pos]);
    
    }

    return 0;

}