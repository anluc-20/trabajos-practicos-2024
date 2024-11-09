#include <stdio.h>

/*Ejercicio 9:
	Se desea calcular el importe que debe pagar un automovilista al estacionar su vehículo
	en la playa, si es motocicleta, paga el importe correspondiente a la tarifa básica según cantidad de
	horas que estacionó en la playa; si es automóvil paga el doble de la tarifa básica y si es camioneta
		paga el triple Dada la hora de entrada y de salida de un vehículo indicar el importe a pagar. La fracción
		de hora se paga como hora entera. Considerar que las horas de entrada y salida son del mismo día.
1.DE:
	hora de entrada : int
	hora de salida: int
	tipo de vehiculo: int
2.DS: 
	Importe a pagar: float

Tareas: 
1.ingresar entrada, salida, vehiculo
2.Obtener las horas a pagar, redondeando para arriba.
3.calcular el importe
4.mostrar el importe
*/
int main() {
	int entradaHora, entradaMin, salidaHora, salidaMin, vehiculo;
	int horas, minutos, horasRedondas;
	float importe;
	float tarifa=1;
	int band=0;

	do{
		if(band==1)
			printf("horas no validas\n");
				   
		do{
			if(band==1)
				printf("hora no valida\n");
					   
			printf("ingrese la hora de entrada:\n");
			printf("horas:");
			scanf("%d",&entradaHora);
			printf("minutos:");
			scanf("%d",&entradaMin);
					   
			band=1;
		} while((entradaHora>23)||(entradaHora<0)||(entradaMin>59)||(entradaMin<0));
				   
		band=0;
		do{
			if(band==1)
				printf("hora no valida\n");
					   
			printf("ingrese la hora de salida:\n");
			printf("horas:");
			scanf("%d",&salidaHora);
			printf("minutos:");
			scanf("%d",&salidaMin);
					   
			band=1;
		} while((salidaHora>23)||(salidaHora<0)||(salidaMin>59)||(salidaMin<0));
		
		horas=salidaHora-entradaHora;
		minutos=salidaMin-entradaMin;
		if(minutos<0){
			horas--;
			minutos+=60;
		}
		
		band=1;
		
	} while(horas<0);
	
	printf("diferencia horas:%d minutos:%d\n",horas, minutos);
	
	
	
	band=0;
	do{
		if(band==1)
			printf("vehiculo no valido\n");
		
		printf("ingrese el tipo de vehiculo\n1.motocicleta\n2.automovil\n3.camioneta\n");
		scanf("%d",&vehiculo);
		
		band=1;
	} while((vehiculo>3)||(vehiculo<1));
	
	if(minutos>0)
		horasRedondas=horas+1;
	else
		horasRedondas=horas;
	
	importe=tarifa*vehiculo*horasRedondas;
	
	printf("usted estuvo %d horas y %d minutos, el importe a pagar es: %f pesos",horas,minutos,importe);
	
	return 0;
}

