#include <stdio.h>

/*
Problema:
	Calcule y retorne la cantidad de horas, minutos y segundos
	que existen en una cantidad de segundos
	ingresada por el usuario.
DE:
	>1 numero N, cantidad de segundos -> segundos
DS:
	>La cantidad de horas
	>La cantidad de minutos
	>La cantidad de segundos

Casos de prueba 1:  
	DE: segundos = 4634;
	DS: horas = 1; minutos = 17; segundos: 14;

Caso de prueba 2:
	DE: segundos = 3600
	DS: horas = 1; minutos = 0; segundos = 0;

Caso de prueba 3:
	DE: segundos = 59
	DS: horas = 0; minutos = 0; segundos = 59;

Caso de prueba 4:
	DE: segundos = 3661
	DS: horas = 1; minutos = 1; segundos = 1;

Caso de prueba 5:
	DE: segundos = 86399
	DS: horas = 23; minutos = 59; segundos = 59;

Caso de prueba 5:
	DE: segundos = 3540
	DS: horas = 0; minutos = 59; segundos = 0;


Problema
	Manipule dos números enteros quitando la última cifra del
	primero y añadiéndola al final del segundo

Casos de prueba 1:  

	DE: a = 4634, b = 45;
	DS: a = 463, b = 454;

Caso de prueba 2:

	DE: a = 123, b = 89
	DS: a = 12, b = 893

Caso de prueba 3:

	DE: a = 9876, b = 321
	DS: a = 987, b = 3216

Caso de prueba 4:

	DE: a = 5, b = 123
	DS: a = 0, b = 1235

Caso de prueba 5:

	DE: a = 1045, b = 67
	DS: a = 104, b = 675

Problema:
	Reciba dos variables enteras e intercambie sus valores. 

Caso de prueba 1:

	DE: a = 5, b = 10
	DS: a = 10, b = 5

Caso de prueba 2:

	DE: a = -3, b = 7
	DS: a = 7, b = -3

Caso de prueba 3:

	DE: a = 0, b = 100
	DS: a = 100, b = 0

Caso de prueba 4:

	DE: a = 12345, b = 54321
	DS: a = 54321, b = 12345

Caso de prueba 5:

	DE: a = -1000, b = -500
	DS: a = -500, b = -1000

*/
void calcularTiempo(int, int*, int*, int*);
void moverUltimaCifra(int*, int*);
void intercambiarValores(int*, int*);

int main() {
	/*
	while(1) {
		int segundos, minutos, horas;
		int x;
		scanf("%d", &x);
		calcularTiempo(x, &segundos, &minutos, &horas);
		printf("horas: %d\n", horas);
		printf("minutos: %d\n", minutos);
		printf("segundos: %d\n", segundos);
	}*/
	while(1) {
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		intercambiarValores(&a, &b);
		printf("a: %d\n", a);
		printf("b: %d\n", b);
	}
	return 0;
}

void calcularTiempo(int segundosIn, int* segundosOut, int* minutosOut, int* horasOut) {
	int resto;
	*horasOut = segundosIn/3600;
	resto = segundosIn%3600;
	*minutosOut = resto/60;
	resto = resto%60;
	*segundosOut = resto;
}

void moverUltimaCifra(int* a, int* b) {
	*b = (*b * 10) + *a % 10;
	*a = *a / 10;
}

void intercambiarValores(int* a, int* b) {
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

