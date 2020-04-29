#include <stdio.h>
int main(){
   int linhas;
   int num;
   scanf("%d",&linhas);
   for (num=1; num <= linhas*4; num++){
      if (num % 4 == 0){
         printf(" PIM\n");
      }
      else{
         printf("%3d",num);
      }
   }
   return 0;
}
