#include <stdio.h>
#define T_MAX 50

typedef int Array[T_MAX];

/*
Ejercicio 9: Dada una lista A de M números naturales, se solicita crear un vector P que contenga la
posición de los elementos de A, para que la lista se recorra ordenada de menor a mayor. Usar el vector
P para determinar cuántos elementos de A se encuentran en la posición correcta, de estar ordenado.

4. Casos de prueba:
Caso 1: Lista completamente desordenada
Entrada: 
A=[4,2,7,1,3,3,10], N=7

Salida esperada: 
2
2 (el 2 y el 10 están en la posición correcta).

Caso 2: Lista ya ordenada

Entrada: 
A=[1,2,3,4,7], N=5

Salida esperada: 
5
5 (todos los elementos están en su posición correcta).

Caso 3: Lista en orden inverso
Entrada: 
A=[7,4,3,2,1], N=5

Salida esperada: 
1
1 (solo el elemento del medio esta en la posicion correcta).

Caso 4: Lista con elementos repetidos
Entrada: 
A=[3,3,1,2,2,2], N=6

Salida esperada: 
0
0 (ningun numero en posicion correcta).

Caso 5: Lista con un elemento
Entrada: 
A=[1], N=1

Salida esperada: 
1
1 (todos los elementos en la posicion correcta).

*/
void ingreso_entero(char *mensaje, int *salida);
void ingreso_array_entero(int *array, int size);
void llenar_array_con_indices(int *array, int size);
void ordenar_array_de_indices(int *array_de_datos, int *array_de_indices, int size);
void intercambiar(int *a, int *b);
void comprobar_posicion(int *array_de_indices, int size);
void mostrar_array(int *array_de_datos, int *array_de_indices, int size);

int main() 
{
        Array numeros, indices;
        int m;
        /*while(1) {
                ingreso_entero("ingrese el tamaño de la lista: ", &m);
                ingreso_array_entero(numeros, m);
                llenar_array_con_indices(indices, m);
                ordenar_array_de_indices(numeros, indices, m);
                printf("el array ordenado es: \n");
                mostrar_array(numeros, indices, m);
                comprobar_posicion(indices, m);    
        }*/
        ingreso_entero("ingrese el tamaño de la lista: ", &m);
        ingreso_array_entero(numeros, m);
        llenar_array_con_indices(indices, m);
        ordenar_array_de_indices(numeros, indices, m);
        printf("el array ordenado es: \n");
        mostrar_array(numeros, indices, m);
        comprobar_posicion(indices, m);
        
        return 0;
}

void ingreso_entero(char *mensaje, int *salida)
{
        printf("%s", mensaje);
        scanf("%d", salida);
}
void ingreso_array_entero(int *array, int size)
{
	for (int i = 0; i < size; i++) {
		printf("[%d/%d] = ", i, size-1);
		scanf("%d", &array[i]);
	}
}

void ordenar_array_de_indices(int *array_de_datos,int *array_de_indices, int size)
{
        int j; 
        for (int i = 1; i < size; i++) {
                j = i - 1;
                while((array_de_datos[array_de_indices[j+1]] < array_de_datos[array_de_indices[j]]) && (j >= 0)) {
                        intercambiar(&array_de_indices[j], &array_de_indices[j+1]);
                        j--;
                }
        }
}

void intercambiar(int *a, int *b) 
{
        int aux;
        aux = *a;
        *a = *b;
        *b = aux;
}

void comprobar_posicion(int *array_de_indices, int size)
{
        int posiciones_correctas = 0;
        for (int i = 0; i < size; i++) {
                if(array_de_indices[i] == i)
                        posiciones_correctas++;
        }
        printf("la cantidad de elementos en la posicion correcta es: %d\n", posiciones_correctas);
}

void llenar_array_con_indices(int *array, int size)
{
        for (int i = 0; i < size; i++) {
                array[i] = i;
        }
}

void mostrar_array(int *array_de_datos, int *array_de_indices, int size) 
{
        for (int i = 0; i < size; i++) {
                printf("[%d] = %d\n", array_de_indices[i], array_de_datos[array_de_indices[i]]);
        }
}