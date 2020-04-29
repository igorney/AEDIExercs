#include <stdio.h>

#define TAM 5


float somaVetor(float vet[], int t){

    if (t == 1){

        return vet[t-1];

    }

    else{

        return vet[t-1]+somaVetor(vet, t-1);

    }


}


int main()
{

    float vetor[TAM];

    for (int i=0; i<TAM; i++){

        scanf("%f",&vetor[i]);

    }

    printf("soma do vetor = %f\n",somaVetor(vetor, TAM));

    

return 0;

}