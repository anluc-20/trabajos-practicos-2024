#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define T_MAX 50

typedef int Vector[T_MAX];
/*
Ejercicio 5: Generar aleatoriamente una lista A de tamaño N, que simula notas de un examen parcial,
entre 0 y 100. A continuación, determinar la/las notas modales (las que más se repiten).
*/

void generar_lista_aleatoria(int *array, int size, int min, int max);
void mostrar_notas_y_repeticiones(int *reducida, int *repitencia, int size);
void ingreso_entero(char *mensaje, int *salida);
void reducir_notas(int *notas, int *reducida, int *repitencia, int size, int *new_size);
int busqueda_binaria(int *array, int size, int buscado);
void ordenar_arrastrando_2(int *array_principal, int *array_secundario, int size);
void ordenar_array(int *array, int size);
void intercambiar(int *a, int *b);
void contar_notas(int *notas, int *reducida, int *repitencia, int size, int *new_size);

int main()
{
        Vector notas, reducida, repitencia;
        int n, m;
        ingreso_entero("Ingrese el tamaño de la lista: ", &n);
        generar_lista_aleatoria(notas, n, 60, 100);
        ordenar_array(notas, n);
        contar_notas(notas, reducida, repitencia, n, &m);
        mostrar_notas_y_repeticiones(reducida, repitencia, m);
        printf("hola\n");
        ordenar_arrastrando_2(repitencia, reducida, m);
        mostrar_notas_y_repeticiones(reducida, repitencia, m);

        return 0;
}

void generar_lista_aleatoria(int *array, int size, int min, int max)
{
        srand(time(NULL));
        for (int i = 0; i < size; i++)
                array[i] = rand() % (max - min + 1) + min;
}

void reducir_notas(int *notas, int *reducida, int *repitencia, int size, int *new_size)
{
        int indice, buscado;
        reducida[0] = notas[0]; 
        repitencia[0] = 1;
        *new_size = 1;
        for (int i = 1; i < size; i ++) {
                buscado = notas[i];
                indice = busqueda_binaria(reducida, *new_size, buscado);
                if(indice != -1) {
                        repitencia[indice] += 1;
                } else {
                        *new_size += 1;
                        reducida[*new_size-1] = buscado;
                        repitencia[*new_size-1] = 1;
                        ordenar_arrastrando_2(reducida, repitencia, *new_size);
                }
        } 
}
void contar_notas(int *notas, int *reducida, int *repitencia, int size, int *new_size)
{
        reducida[0] = notas[0]; 
        repitencia[0] = 1;
        *new_size = 1;
        for (int i = 1; i < size; i++) {
                if(notas[i] == reducida[*new_size-1]) {
                        repitencia[*new_size-1] += 1;
                } else {
                       *new_size += 1;
                        reducida[*new_size-1] = notas[i];
                        repitencia[*new_size-1] = 1; 
                }
        }
}

void ordenar_arrastrando_2(int *array_principal, int *array_secundario, int size) {
        int j; 
        for (int i = 1; i < size; i++) {
                j = i - 1;
                while((array_principal[j] < array_principal[j+1]) && (j >= 0)) {
                        intercambiar(&array_principal[j], &array_principal[j+1]);
                        intercambiar(&array_secundario[j], &array_secundario[j+1]);
                        j--;
                }
        }
}
void ordenar_array(int *array, int size)
{
        int j; 
        for (int i = 1; i < size; i++) {
                j = i - 1;
                while((array[j+1] < array[j]) && (j >= 0)) {
                        intercambiar(&array[j], &array[j+1]);
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

int busqueda_binaria(int *array, int size, int buscado)
{
        int inicio = 0, fin = size - 1, m = (inicio + fin) / 2;
        while((inicio < fin) && array[m] != buscado) {
                if(array[m] > buscado)
                        fin = m - 1;
                else
                        inicio = m + 1;

                m = (inicio + fin) / 2;
        }
        if(array[m] == buscado)
                return m;
        else
                return -1;
}

void mostrar_notas_y_repeticiones(int *reducida, int *repitencia, int size) 
{
        for (int i = 0; i < size; i++) {
                printf("la nota: %d, se repite %d veces\n", reducida[i], repitencia[i]);
        }
}
void ingreso_entero(char *mensaje, int *salida)
{
        printf("%s", mensaje);
        scanf("%d", salida);
}