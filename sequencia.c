#include <stdio.h>

int main(){
	int n, s, i=0, j=0;
	scanf("%d", &n);
	while(n >= 0){
		s = n;
		scanf("%d", &n);
		if(n<0){
			break;
		}
		else if(n > s){
			j++;
		}
		i++;
	}
	if(i==j){
		printf("Sequencia");
	}
return 0;
}
