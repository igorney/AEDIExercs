#include <stdio.h>
int main(){
    int c,q;
    scanf("%d%d",&c,&q);
    switch(c){
       case 1:
          printf("Total: R$ %.2f\n",4.0*q);
          break;
       case 2:
          printf("Total: R$ %.2f\n",4.5*q);
          break;
       case 3:
          printf("Total: R$ %.2f\n",5.0*q);
          break;
       case 4:
          printf("Total: R$ %.2f\n",2.0*q);
          break;
       case 5:
          printf("Total: R$ %.2f\n",1.5*q);
          break;
    }
    return 0;
}
