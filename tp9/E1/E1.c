/*
        Ejercicio 1:  Cree un programa que declare tres pares ordenados (x,y) en variables de tipo puntero con asignación de memoria en forma dinámica e indique cual par ordenado retorna el mínimo valor al ser evaluado en la expresión (x2-10y).  
*/

#include "par_ordenado.h"
#include "lista_par.h"
#include <stdio.h>

int main()
{
        ListaPares *pares = NULL;
        int i;
        pares = crear_lista_pares();

        for (i = 0; i < 3; i++) {
                agregar_lista_pares(pares, crear_par_ordenado());
        }

        mostrar_lista_pares(pares);
        printf("el elemeno mas pequeño de la operacion 2x - 10y aplicada a todos los pares es: %d", operar_lista_y_devuelve_menor(pares));
        
        eliminar_lista_pares(pares);

        return 0;
}
