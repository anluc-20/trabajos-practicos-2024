#include <stdio.h>
/*
Ejercicio 1
	Se tienen los siguientes Arreglos (Vectores):
	A= {3, -5, 2, 0, 7, -2}; B= {3.3, -5.2, 2.0, . . . , 7.0, -2.5} y C= {�a�, �e�, �i�, �o�, �u�, �b�, �c�}
	Se solicita:
	a) Determinar si cada arreglo cumple con la definici�n de Arreglos unidimensionales.
	b) Para aquellos que cumplan con la definici�n representarlos gr�ficamente.
	c) Definir el tipo de datos Arreglo y declarar el identificador A y C como variables de dicho tipo.
	d) Crear un programa que permita declarar los arreglos A y C y posteriormente, mostrar los elementos
	del arreglo A que se encuentran en posici�n par y los elementos del arreglo C que se encuentran en
	posici�n impar

*/
void mostrar_posiciones_pares(int *array, int size);
void mostrar_posiciones_impares(char *array, int size);

int main() {
	int A[] = {3, -5, 2, 0, 7, -2};
	char C[] = {'a', 'e', 'i', 'o', 'u', 'b', 'c'};
	mostrar_posiciones_impares(C,7);
	mostrar_posiciones_pares(A,6);
	
	return 0;
	
}

void mostrar_posiciones_pares(int *array, int size) 
{
	for(int i = 0; i < size; i += 2) {
		printf("posicion %d: %d\n", i, array[i]);
	}
}
void mostrar_posiciones_impares(char *array, int size) 
{
	for(int i = 1; i < size; i += 2) {
		printf("posicion %d: %c\n", i, array[i]);
	}
}


