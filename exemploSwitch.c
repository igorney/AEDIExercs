#include <stdio.h>
int main(){
   int valor;
   scanf("%d",&valor);
   switch(valor){
      case 1:
         printf("Digitou valor 1\n");
         break;
      case 2:
         printf("Digitou valor 2\n");
         break;
      case 3:
         printf("Digitou valor 3\n");
         break;
      default:
         printf("Nao digitou nenhum deles\n");
   }
   return 0;
}
