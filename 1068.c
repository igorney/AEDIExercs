#include <stdio.h>

int main(void){
	char e[1000];
	int i, p1, p2;

	scanf("%s", e);
	for(i=0; i < sizeof(e); i++){
		if(e[i] == '('){
			p1++;
		}
		else if(p1>=p2){
				if(e[i] == ')'){
					p2++;
				}
		}
	}
	if(p1==p2){
		printf("correct");
	}
	else{
		printf("incorrect");
	}

	return 0;
}

