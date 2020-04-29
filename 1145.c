#include<stdio.h>

int main(){
	int X, Y;

	scanf("%d %d", &X, &Y);

	for(int i=1; i<=Y;){
		for(int j=1; j<=X && i<=Y;j++){
			if(j==X){
				printf("%d", i++);
			}
			else{
				printf("%d ", i++);
			}
		}
		printf("\n");
	}
	return 0;
}
