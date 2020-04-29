#include<stdio.h>
int main(){
   int a,b,c;
   scanf("%d%d",&a,&b);
   /*if (a > b){
      c = 1;
   }
   else{
      c = -1;
   }*/

   c = ( a > b )? 1 : (a < b)? -1: 0 ;

   printf("Valor de c = %d\n",c);
}
