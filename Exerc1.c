#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stData{
	int dia;
	int mes;
	int ano;
} Data;
void dataFormat(Data data){
	printf("%d/%d/%d\n", data.dia, data.mes, data.ano);
}
int maiorData(Data data1, Data data2){
	int valor = 0;
	return valor;
}
int main(){
	Data data1, data2;
	scanf("%d %d %d", &data1.dia, &data1.mes, &data1.ano);
	scanf("%d %d %d", &data2.dia, &data2.mes, &data2.ano);
	dataFormat(data1);
	dataFormat(data2);
	maiorData(data1, data2);

	return 0;
}
