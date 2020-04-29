#include<stdio.h>
// 1 1 2 3 5 8 13 21 34 ...
// 0 1 3 4 5 6 7  8  9 
int fibonacci(int n){
	if(n == 0 || n == 1){
		return n;
	}
	else{
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main(){
	int i;
	for(i=0; i <= 20; i++){
		printf("fibonacci(%d) = %d\n", i, fibonacci(i)); 
	}
	return 0;
}