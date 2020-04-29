#include <stdio.h>
int main(){
   int a;
   scanf("%d",&a);
   do {
      printf("Valor do a = %d\n",a);
      a++;
   } while(a < 10);
   return 0;
}
