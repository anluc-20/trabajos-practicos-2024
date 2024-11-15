/*
        Ejercicio 10: Se desea crear una lista de N nombres.
        Utilizar leeCad Recursivo A continuación, se desea ordenarla ascendentemente utilizando el método M-Sort y 
        por último mostrar la lista resultante Nota: TAD con todos sus módulos recursivos. 
*/
#include "lista_nombres.h"
#include <stdio.h>

int main()
{
        int n;
        ListaNombres nombres = crear_lista_nombres();
        scanf("%s", *nombres.p[0]);
        printf("%s", *nombres.p[0]);
        mostrar_cadena(*nombres.p[0]);
        //printf("ingrese la cantidad de nombres: ");
        //scanf("%d", &n);
        //cargar_nombres(&nombres, n);
        //ordenar_nombres(&nombres);
        //mostrar_nombres(&nombres);  
        return 0;
}

