#include <stdio.h>
#define MAXIMO 50

/*
	Se tiene una lista de edades de N alumnos de una escuela, se solicita ingresar la lista y a continuacion, mediante un menu:
a) Determinar la edad con mayor cantidad de repeticiones sabiendo que existe y es �nica.
b) Mostrar la primera sublista creciente, de almenos dos numeros, conformada solo por elementos pares.

*/

void ingreso_array_entero(int *array, int size);
int buscar_mayor(int *array, int size);
int buscar_repetidos(int *array, int size, int buscado);
int encontrar_primera_sublista_creciente(int *array, int size, int *iIMay, int *iFMay);
void ingresar_opcion(int *opcion);
void mostrar_array_desde_hasta(int *array, int i1, int i2);
void menu();
int guardar_mayor_sublista(int *iIMay, int *iFMay, int iI, int iF);

int main(int argc, char *argv[]) {
	while(1) {
		menu();
	}
	
	return 0;
}

void menu() 
{
	int numeros[MAXIMO], n, mayor = 0, cant_repetidos = 0, i1 = 0, i2 = 0, opcion, tamano;
	
	printf("Ingrese la cantidad de alumnos: ");
	scanf("%d", &n);
	printf("Ingrese sus edades: \n");
	ingreso_array_entero(numeros, n);
	ingresar_opcion(&opcion);
	switch(opcion) {
		case 1:
			mayor = buscar_mayor(numeros, n);
			cant_repetidos = buscar_repetidos(numeros, n, mayor);
			printf("el mayor numero que mas se repite es el %d y se repite %d veces\n", mayor, cant_repetidos);			
			break;
		case 2: 
			tamano = encontrar_primera_sublista_creciente(numeros, n, &i1, &i2);
			if(tamano <  1) {
				printf("no pudo encontrarse una sublista con dichas caracteristicas\n");
				break;
			}
			mostrar_array_desde_hasta(numeros, i1, i2); 
			break;
	}
	
	
}

void ingresar_opcion(int *opcion)
{
	printf("Seleccione una opcion:\n1.Determinar la edad con mayor cantidad de repeticiones.\n2.Mostrar la primera sublista creciente, de almenos dos numeros, conformada solo por elementos pares.\n");
	scanf("%d", opcion);
	while((*opcion > 2) || (*opcion < 0)) {
		printf("Opcion invalida, por favor eliga de nuevo: ");
		scanf("%d", opcion);
	}
}
void ingreso_array_entero(int *array, int size)
{
	for(int i = 0; i < size; i++) {
		printf("[%d/%d] = ", i, size-1);
		scanf("%d", &array[i]);
	}
}

int buscar_mayor(int *array, int size)
{
	int mayor;
	for (int i = 0; i < size; i++) {
		if((i==0) || (array[i] > mayor))
			mayor = array[i];
	}
	return mayor;
}

int buscar_repetidos(int *array, int size, int buscado)
{
	int cant_repetidos = 0;
	for (int i = 0; i < size; i++) {
		if(array[i]==buscado)
			cant_repetidos++;
	}
	return cant_repetidos;
}

int encontrar_primera_sublista_creciente(int *array, int size, int *iIMay, int *iFMay)
{
	int iI = -1, iF = 0, tamano = 0;
	*iIMay = -1;
	for (int i = 0; i < size; i++) {
		if((array[i] % 2) == 0) {
			if(*iIMay == -1) {
				*iIMay = i;
				*iFMay = i;
			}
			if(iI == -1) {
				iI = i;
				iF = i;	
			} else if (array[i] > array[i-1]) {
				iF = i;
			} else {
				tamano = guardar_mayor_sublista(iIMay, iFMay, iI, iF);
				if(tamano > 0)
					return tamano;
				iI = -1;
			}
			
		}
		else if(*iIMay != -1){
			tamano = guardar_mayor_sublista(iIMay, iFMay, iI, iF);
			if(tamano > 0)
				return tamano;
			iI = -1;
		}
	}
	tamano = guardar_mayor_sublista(iIMay, iFMay, iI, iF);
	return tamano;
}
void mostrar_array_desde_hasta(int *array, int i1, int i2)
{
	for (int i = i1; i <= i2; i++) {
		printf("[%d] = %d\n", i, array[i]);
	}

	
}

int guardar_mayor_sublista(int *iIMay, int *iFMay, int iI, int iF) 
{
	if((iF - iI) > (*iFMay - *iIMay)) {
		*iIMay = iI;
		*iFMay = iF;
	}
	return *iFMay - *iIMay;
}
