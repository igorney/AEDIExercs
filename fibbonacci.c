#include <stdio.h>


int fibbonacci(int n){

  if (n == 0 || n == 1){

      return n;

  }

  else{

      return fibbonacci(n-1)+fibbonacci(n-2);

  }

}


int main()
{

    for (int i=0; i <= 20; i++){

        printf("fibbonacci(%2d) = %d\n",i,fibbonacci(i));

    }


    return 0;

}