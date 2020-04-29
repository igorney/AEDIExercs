#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stProduto{
   int codigo;
   char descricao[30];
   float preco;
};

typedef struct stProduto Produto;


void printProduct(Produto p){
   printf("%d - %s - R$ %.2f\n",
            p.codigo, 
            p.descricao, 
            p.preco);
}

char* converteParaString(Produto p){
    char* result = (char*)malloc(sizeof(char)*50);
    sprintf(result, "%d - %s - %.2f\n",p.codigo, p.descricao, p.preco);
    return result;
}
int main()
{
    Produto prods[10];
    int i;
    //char strResult[50];
  
    // lendo
    for(i=0;i<10;i++){
       prods[i].codigo = i;
       strcpy(prods[i].descricao,"produtoteste");
       prods[i].preco = i*100;
    }
    for (i=0;i<10;i++){
        
        printf("%s", converteParaString(prods[i]));
    }
    return 0;
}
