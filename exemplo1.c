#include <stdio.h>

int main(void) {
  int a,b,c;
  printf("Digite 3 lados\n");
  scanf("%d%d%d",&a,&b,&c);
  if (a+b>c && a+c>b && b+c>a){
    printf("Os lados formam um triangulo\n");
  }
  else{
    printf("Nao formam triangulo\n");
  }
  return 0;
}