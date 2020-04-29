#include <stdio.h>
int main(){
   int i;
   i=0;
   /*while(i<10){
      if (i==5){
         continue;
      }
      printf("Valor do i=%d\n",i);
      i++;
   }*/


   for (i=0; i<10;i++){
      if (i==5){
         continue;
      }
      printf("Valor do i=%d\n",i);
   }
   return 0;
}
