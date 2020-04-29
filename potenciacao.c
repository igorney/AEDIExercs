#include <stdio.h>

int main(){
	unsigned int x, y, i;
	scanf("%d \n %d", &x, &y);
	for(i=1; i<=y; i++){
		x*=i;
	}
	printf("%d\n", x);

return 0;
}
