#include <stdio.h>
#define TAM 5

void leiaVetor(int vet[]){
    for (int i=0;i<TAM;i++){
        printf("digite = ");
        scanf("%d",&vet[i]);
    }
}
void imprimaVetor(int vet[]){
    for (int i=0;i<TAM;i++){
        printf("\nvetor[%d] = %d",i,vet[i]);
    }
    printf("\n");
}
int main()
{
    int vetor[TAM];
    leiaVetor(vetor);
    imprimaVetor(vetor);

    return 0;
}