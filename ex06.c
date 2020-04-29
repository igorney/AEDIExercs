#include <stdio.h>
int main(){
   int n;
   int pot=1;
   scanf("%d",&n);
   while (pot < n){
      pot*=2; // pot = pot * 2;
   }
   printf("A menor potencia de 2 maior q %d eh %d\n",n,pot);
   return 0;
}
