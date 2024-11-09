#include "articulo.h"
#include "../utils/utils.h"
#include <string.h>
#include <stdio.h>
#define OPCIONES "a) Agregar un nuevo artículo a la lista preservando el orden.\nb) Eliminar un artículo de la lista dado su Código.\nc) Mostrar los artículos de la lista.\nd) Mostrar los artículos de un Proveedor ingresado por teclado.\ne) Dado un nivel de stock mínimo ingresado por teclado, generar una nueva lista con los artículos que tienen un Stock menor que el ingresado y luego mostrarlo\nf)salir\nopcion: "
/*
Ejercicio  4:  Una  Tienda  que  vende  artículos  de  librería  administra  una  lista  de  N  artículos,  de  cada 
artículo  se  lleva  la  siguiente  información:  Código  del  artículo;  Nombre  del  artículo;  Proveedor;  Stock, 
Precio de venta.  
Se  necesita  un  programa  convenientemente  modularizado  que  utilizando  el  concepto  de  TAD  permita 
ingresar una lista de N artículos la cual se ordenará a medida que se ingresan los registros por el campo 
DNI. Posteriormente a través de un menú realizar las siguientes operaciones:  
a) Agregar un nuevo artículo a la lista preservando el orden.  
b) Eliminar un artículo de la lista dado su Código.  
c) Mostrar los artículos de la lista.  
d) Mostrar los artículos de un Proveedor ingresado por teclado.  
e) Dado un nivel de stock mínimo ingresado por teclado, generar una nueva lista con los artículos 
que tienen un Stock menor que el ingresado y luego mostrarlo 
*/

void menu_loco(int *salir, ListaArticulos *articulos);

void menu_a(ListaArticulos *articulos);
void menu_b(ListaArticulos *articulos);
void menu_c(ListaArticulos *articulos);
void menu_d(ListaArticulos *articulos);
void menu_e(ListaArticulos *articulos);

int comparar_por_proveedor(Articulo *articulo1, Articulo *articulo2);
int comparar_por_stock(Articulo *articulo1, Articulo *articulo2);

int main()
{
        int n, i, salir;
        ListaArticulos articulos;
        Articulo array[ARTICULOS_MAX_SIZE];
        inicializar_lista_articulos(&articulos, array);

        ingresar_entero("ingrese la cantidad de articulos a ingresar: ", &n);
        for (i = 0; i < n; i++) {
                agregar_articulo(&articulos);
        }

        salir = 0;
        while(!salir)
                menu_loco(&salir, &articulos);
        return 0;
}

void menu_loco(int *salir, ListaArticulos *articulos)
{
        char opcion;
        ingresar_char(OPCIONES, &opcion);
        while((opcion < 'a') || (opcion > 'f'))
                ingresar_char("opcion invalida, ingrese una valida: ", &opcion);

        switch(opcion) {
                case 'a':
                        menu_a(articulos);
                        break;
                case 'b':
                        menu_b(articulos);
                        break;
                case 'c':
                        menu_c(articulos);
                        break;
                case 'd':
                        menu_d(articulos);
                        break;
                case 'e':
                        menu_e(articulos);
                        break;
                case 'f':
                        printf("saliendo...\n");
                        *salir = 1;
                        break;
        }
}

void menu_a(ListaArticulos *articulos)
{
        agregar_articulo(articulos);
}
void menu_b(ListaArticulos *articulos)
{
        int codigo, indice;
        ingresar_entero("codigo: ", &codigo);

        if((indice = buscar_articulo(articulos, codigo)) == -1) {
                printf("no existe un articulo con ese codigo.\n");
        } else {
                printf("se ha eliminado correctamente el articulo.\n");
                eliminar_articulo(articulos, indice);
        } 
}
void menu_c(ListaArticulos *articulos)
{
        mostrar_articulos(articulos);
}
void menu_d(ListaArticulos *articulos)
{
        ListaArticulos salida;
        Articulo comparado = {0,"-", "-", 0, 0};
        ingresar_texto("ingrese el proveedor: ", comparado.proveedor, CADENA_MAX_SIZE);
        buscar_articulos(articulos, &salida, comparar_por_proveedor, comparado);
        if(salida.size == 0) {
                printf("no se encontraron articulos de ese proveedor.\n");
        } else {
                mostrar_articulos(&salida);
        }
}
void menu_e(ListaArticulos *articulos)
{
        ListaArticulos salida;
        Articulo comparado = {0,"-", "-", 0, 0};
        ingresar_entero("ingrese el stock: ", &comparado.stock);
        buscar_articulos(articulos, &salida, comparar_por_stock, comparado);
        if(salida.size == 0) {
                printf("no se encontraron articulos con un stock menor al ingresado.\n");
        } else {
                mostrar_articulos(&salida);
        }
}

int comparar_por_proveedor(Articulo *articulo1, Articulo *articulo2)
{
        return strcmp(articulo1->proveedor, articulo2->proveedor);
}
int comparar_por_stock(Articulo *articulo1, Articulo *articulo2) {
        return !(articulo1->stock < articulo2->stock);
}
