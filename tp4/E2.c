#include <stdio.h>

typedef int Array[50];
/*
Ejercicio 2:
	Se tiene una lista de N números naturales sin repetidos, se desea; encontrar el menor de la
	lista sabiendo que existe y es único, ordenar la lista de menor a mayor, insertar un nuevo elemento
	manteniendo el orden y las características de la lista, para finalizar, mostrar los primos presentes en la
	lista.


*/


void mostrar_array_entero(int *array, int size);
void ordenar_por_insercion(int *array, int size);
void ingreso_entero(const char *mensaje, int *salida);
void ingreso_array_entero(int *array, int size);
void insertar_ordenado(int *array, int *size, int elemento);
int es_primo(int num);
void mostrar_primos(int *array, int size);


int main(int argc, char *argv[]) {
	int n, num;
	
	
	/*
	//Caso de prueba 1:
	n = 8;
	Array numeros = {7, 3, 9, 1, 6, 8, 2, 5};
	num = 6;
	//Salida: 1, 2, 3, 5, 6, 6, 7, 8, 9

	//Caso de prueba 2:

	n = 5;
	Array numeros = {10, 4, 2, 8, 6};  
	num = 5;  
	// Salida: 2, 4, 5, 6, 8, 10
	
	//Caso de prueba 3:

	n = 3;
	Array numeros = {12, 7, 9};  
	num = 11;  
	// Salida: 7, 9, 11, 12  
	
	//Caso de prueba 4:

	n = 6;
	Array numeros = {1, 20, 14, 5, 9, 3};  
	num = 21;  
	// Salida: 1, 3, 5, 9, 14, 20, 21
	*/
	//Caso de prueba 5:

	n = 4;
	Array numeros = {25, 35, 30, 20};  
	num = -6;  
	// Salida: -6, 20, 25, 30, 35  
	/**/

/*
	ingreso_entero("ingrese el tamaño del arreglo: ", &n);
	ingreso_array_entero(numeros, n);
	ingreso_entero("ingrese el numero a insertar: ", &num);
*/
	
	ordenar_por_insercion(numeros, n);
	mostrar_array_entero(numeros, n);
	insertar_ordenado(numeros, &n, num);
	mostrar_array_entero(numeros, n);
	mostrar_primos(numeros, n);
	
	return 0;
}

void ordenar_por_insercion(int *array, int size)
{
	int aux, j, band;
	for(int i = 1; i < size; i++) {
		j = i-1;
		band = 0;
		while ((j >= 0) && (band == 0)) {
			if(array[j+1] < array[j]) {
				aux = array[j+1];
				array[j+1] = array[j];
				array[j] = aux;
				j--;
			}
			else {
				band = 1;
			}		
		}
	}
}

void mostrar_array_entero(int *array, int size) 
{
	printf("array: ");
	for (int i = 0; i < size; i++) {
		printf("%d, ", array[i]);
	}
	printf("\n");
}
void mostrar_primos(int *array, int size) 
{
	printf("primos: ");
	for (int i = 0; i < size; i++) {
		if(es_primo(array[i]))
			printf("%d, ", array[i]);
	}
	printf("\n");
}

void ingreso_entero(const char* mensaje, int* salida)
{
	printf("%s",mensaje);
	scanf("%d",salida);
}

void ingreso_array_entero(int *array, int size)
{
	for (int i = 0; i < size; i++) {
		printf("[%d/%d] = ", i, size-1);
		scanf("%d", &array[i]);
	}
}

void insertar_ordenado(int *array, int *size, int elemento)
{
	int i = *size;
	while ((i>0) && (elemento < array[i-1])) {
		array[i] = array[i-1];
		i--;
	}
	array[i] = elemento;
	*size = *size + 1;
}

int es_primo(int num) 
{
	int aux = num>0 ? num : -num;
	int primo = 1, mitad = (aux/2) + 1, i = 2;

	while((primo == 1) && (i<mitad)) {
		if(aux%i == 0)
			primo = 0;
		i++;
	}
	if(primo == 0 || aux == 1)
		return 0;
	else
		return 1;
}