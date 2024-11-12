/*
        Ejercicio 1:  Cree un programa que declare tres pares ordenados (x,y) en variables de tipo puntero con asignación de memoria en forma dinámica e indique cual par ordenado retorna el mínimo valor al ser evaluado en la expresión (x2-10y).  
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct ParOrdenado ParOrdenado;

ParOrdenado* crear_par_ordenado();

void mostrar_par_ordenado(ParOrdenado *par);
int operar_par_ordenado(ParOrdenado *par);
void eliminar_par_ordenado(ParOrdenado *par);

