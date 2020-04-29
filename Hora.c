#include <stdio.h>

typedef struct stHora{
    int hora;
    int minuto;
    int segundo;
} Hora;
void horaAtual(Hora *horas, int hora, int min, int sec){
    horas->hora = hora;
    horas->minuto = min;
    horas->segundo = sec;
}
void printHora(Hora horas){
	printf("O Horário é: %d:%d:%d", horas.hora, horas.minuto, horas.segundo);
}
int main(){
	Hora h;
	int hora, min, sec;
	printf("Digite a hora: ");
	scanf("%d", &hora);
	printf("Digite os minutos: ");
	scanf("%d", &min);
	printf("Digite os segundos: ");
	scanf("%d", &sec);

	horaAtual(&h, hora, min, sec);

	printHora(h);

return 0;
}