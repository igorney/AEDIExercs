#include <stdio.h>

int main(void) {
  
  int v[15], par[5], impar[5];
  int i = 0, iPar = 0, iImpar = 0, auxI = 0, auxP = 0;

  for(i=0; i<15; i++){
    scanf("%d", &v[i]);
  }
  for(i=0; i<15; i++){
    if(v[i]%2 == 0){
      if(iPar == 5){
        for(iPar=0; iPar<5; iPar++){
          printf("par[%d] = %d\n", iPar, par[iPar]);
        }
        iPar = 0;
      }
      else{
        par[iPar] = v[i];
        iPar++;
      }
    }
    else{
      if(iImpar == 5){
        for(iImpar=0; iImpar<5; iImpar++){
          printf("impar[%d] = %d\n", iImpar, impar[iImpar]);
        }
        iImpar = 0;
      }
      else{
        impar[iImpar] = v[i];
        iImpar++;
      }
    }
  }
  for(i=0;i<=iImpar;i++)
    {
      printf("impar[%d] = %d\n",i,impar[i]);
    }
    for(i=0;i<=iPar;i++)
    {
      printf("par[%d] = %d\n",i,par[i]);
    }
  return 0;
}
