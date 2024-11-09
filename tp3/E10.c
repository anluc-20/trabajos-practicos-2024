#include <stdio.h>

/*
Problema:
	Dada una lista de N fechas ingresadas por el usuario, representadas como números enteros
	con el formato (AAAADDMM), se pide indicar cuántas fechas son válidas y cuántas no lo son. Se debe
	tener en cuenta los años bisiestos.
	Nota: un año será bisiesto si es divisible entre 4, sin embargo, no puede ser divisible entre 100, a menos
	que también lo sea por 400. Se debe crear un módulo que separe la fecha en día, mes y año.


Caso de prueba 1: 
	Entrada: N=2, fechas = 12345678,20240913;
	Salida: validas=1, invalidas=1;

Caso de prueba 2:
	Entrada: N=3, fechas = 20200229,20211307,20241231;
	Salida: válidas = 2, inválidas = 1.

Caso de prueba 3:
	Entrada: N=4, fechas = 20190228,20190229,20000229,21000301;
	Salida: válidas = 3, inválidas = 1.

Caso de prueba 4:
	Entrada: N=2, fechas = 19991232,20000230;
	Salida: válidas = 0, inválidas = 2.

Caso de prueba 5:
	Entrada: N=5, fechas = 20210515,20160229,20210228,20200230,20240700;
	Salida: válidas = 3, inválidas = 2.

*/
void ingresoEntero(const char*, int*);
void separarFecha(int, int*, int*, int*);
int abs(int);
int esBisiesto(int);

int main() {
	int n, fecha, anio, mes, dia, bisiesto=0, validas = 0, invalidas = 0;
	
	while (1) {
		ingresoEntero("ingrese n: ", &n);
		for(int i = 0; i<n; i++) {
			ingresoEntero("ingrese x: ", &fecha);
			separarFecha(fecha, &anio, &mes,&dia);
			printf("anio: %d, mes: %d, dia: %d",anio, mes, dia);
			bisiesto=esBisiesto(anio);
	
			
			if((mes>12)||(mes<1)||(dia>31)||(dia<1)) {
				invalidas ++;
				continue;
			}
			
			if(((mes==2)&&!bisiesto&&(dia>28)) || ((mes==2)&&bisiesto&&(dia>29))) {
				invalidas ++;
				continue;
			}
				
			if(((mes==4)||(mes==6)||(mes==9)||(mes==11)) && dia>30) {
				invalidas ++;
				continue;
			}
			
			validas++;
		}
		printf("fechas validas: %d, fechas invalidas: %d",validas, invalidas);
		validas = 0, invalidas = 0;
	}
	
	
	return 0;
}


int abs(int x) {
	return x>0? x :-x;
}
void ingresoEntero(const char* mensaje, int* salida) {
	printf("%s",mensaje);
	scanf("%d",salida);
}

void separarFecha(int fecha, int* anios, int* meses, int* dias) {
	*dias = fecha%100;
	fecha /= 100;
	*meses = fecha%100;
	fecha /= 100;
	*anios = fecha;
}
int esBisiesto(int anio) {
	if(anio%4!=0) return 0;
	
	if(anio%100!=0) return 1;
	
	if(anio%400==0)
		return 1;
	else
		return 0;
	
}
