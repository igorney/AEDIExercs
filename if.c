#include <stdio.h>
int main(){
   int a, b, c;
   a = 10;
   b = 5;
   c = 0;
   if ( a < b && (c = 8) > 0){
      printf("VERDADEIRO: a=%d, b=%d, c=%d\n",a,b,c);
   }
   else{
      printf("FALSO: a=%d, b=%d, c=%d\n",a,b,c);
   }
   return 0;
}
