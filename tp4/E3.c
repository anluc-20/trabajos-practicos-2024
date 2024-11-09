#include "stdio.h"

/*
Ejercicio 3:
Se tiene una lista de caracteres que representa una frase conformada con consonantes,
vocales en minúsculas y dígitos, el ingreso de la lista se finalizará al ingresar el carácter “/”. Se solicita
ingresar un carácter y buscarlo en la lista ingresada informando la primera posición donde se encuentra,
borrar de la lista los dígitos presentes y para finalizar ordenar la lista ascendentemente y mostrar la lista
resultante.

*/

int buscar_caracter(char *array, int size, char c);
void borrar_numeros_char(char *array, int *size);
void ordenar_por_insercion(char *array, int size);
int ingreso_char_array(char *array, int size, char stop);
void mostrar_array_char(char *array, int size);
int char_es_un_numero(char c);
void borrar_por_indice(char *array, int *size, int indice);

int main()
{
        int maximo = 50, posicion_char, n;
        char caracteres[50], c;
        n = ingreso_char_array(caracteres, maximo, '/');
        printf("ingrese el caracter a buscar: ");
        scanf(" %c", &c);

        posicion_char = buscar_caracter(caracteres, n, c);
        if(posicion_char == -1)
                printf("el caracter no se encuentra en la lista");
        else
                printf("el caracter se encuentra en la posicion: [%d]\n", posicion_char);

        borrar_numeros_char(caracteres, &n);
        ordenar_por_insercion(caracteres, n);
        printf("la lista ordenada ascendentemente es: ");
        mostrar_array_char(caracteres, n);

}

int ingreso_char_array(char *array, int size, char stop)
{
        int i = 1;
        printf("[0] = ");
        scanf(" %c", &array[0]); 
        while ((array[i-1]!=stop) && (i<size)) {
                printf("[%d] = ", i);
                scanf(" %c", &array[i]);
                i++;
        }
        i--;
        return i;

}

int buscar_caracter(char *array, int size, char c)
{
        for (int i = 0; i < size; i++) {
                if(array[i] == c)
                        return i;
        }
        return -1;
}

void borrar_numeros_char(char *array, int *size)
{
        int i = 0;
        while(i < *size) {
                if(char_es_un_numero(array[i]))
                        borrar_por_indice(array, size, i); 
                else
                        i++;
        }
}
void ordenar_por_insercion(char *array, int size)
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

void mostrar_array_char(char *array, int size) 
{
	printf("array: ");
	for (int i = 0; i < size; i++) {
		printf("%c, ", array[i]);
	}
	printf("\n");
}
int char_es_un_numero(char c)
{
        return (c >= 48) && (c <= 57);//48-57 son los codigos ASCII para 0-9
}

void borrar_por_indice(char *array, int *size, int indice) 
{
        int fin = *size - 1;
        for (int i = indice; i < fin; i++) {
                array[i] = array[i+1];
        }
        *size = fin;
}