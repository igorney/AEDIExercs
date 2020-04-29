#include <stdio.h>
#include <string.h>

#define NUM_LETRAS 26


int main(void) {

    char frase[512];
    int alfa[NUM_LETRAS];
    
    int n, maior = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s", frase);
        for(int t =0; t < NUM_LETRAS; ++t){
            alfa[t] = 0;
        }
        for(int j = 0; j < strlen(frase); ++j){
            char letra = frase[j];
            int indice = letra - 'a';
            if((indice >= 0) & (indice < NUM_LETRAS)){
                alfa[indice]++;
            }
        }
        
        for(int t =0; t < NUM_LETRAS; ++t){
            //printf("%c: %d\n", 'a' + t, alfa[t]);
			if(alfa[t] > maior)
				maior = alfa[t];
        }
		for(int t =0; t < NUM_LETRAS; ++t){
        	if(alfa[t] == maior)
				printf("%c", 'a' + t);
		}
        
    }
	
    return 0;
}
