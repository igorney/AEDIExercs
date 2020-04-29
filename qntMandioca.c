#include<stdio.h>

int main(){
	int n, i;
	int porcao = 225;

	for(i=1; i<=5; i++){
		scanf("%d", &n);
		switch(i){
			case 1:
				porcao += n*300;
			break;
			
			case 2:
				porcao += n*1500;
			break;
			
			case 3:
				porcao += n*600;
			break;
			
			case 4:
				porcao += n*1000;
			break;
			
			case 5:
				porcao += n*150;
			break;

			default:
			break;
		}
	}
	printf("%d\n", porcao);

	return 0;
}
