#include <stdio.h>
int main(){
   int crescente=1;
   int atual, anterior;

   scanf("%d",&atual);
   while (atual >= 0){
       anterior = atual;
       scanf("%d",&atual);
       if (atual >=0){
           if (atual < anterior){
              crescente = 0;
           }
       }
   }

   if (crescente){
      printf("A sequencia eh crescente\n");
   }
   else{
      printf("A sequencia nao eh crescente\n");
   }
   return 0;
}
