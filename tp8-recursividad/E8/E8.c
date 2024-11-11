/*
Ejercicio  8:  Se  pide  crear  un  programa  recursivo  que  permita  generar  aleatoriamente  una  lista  de  N 
números enteros en el intervalo [A, B], luego presentar un menú de opciones (el cual debe ser recursivo) 
que permita realizar las siguientes tareas: mostrar la lista, Insertar un nuevo elemento en una posición 
ingresada por teclado, buscar un elemento en la lista.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 30

typedef int IntArray[ARR_SIZE];

typedef struct {
        IntArray arr;
        int size;
        int min;
        int max;
} ListaEnteros;

ListaEnteros crear_lista();
void mostrar_lista(ListaEnteros *lista);
void cargar_lista_aleatorio(ListaEnteros *lista, int cantidad);
void cargar_elemento_aleatorio(ListaEnteros *lista, int indice);
void insertar_elemento(ListaEnteros *lista);
void mover_elementos_recursivo(ListaEnteros *lista, int posicion, int indice);
void buscar_elemento(ListaEnteros *lista);
void mostrar_elemento(ListaEnteros *lista, int indice);
int busqueda_secuencial_recursiva(ListaEnteros *lista, int indice, int buscado);
int obtener_aleatorio(int min, int max);

void menu_recursivo(ListaEnteros *lista);

int main()
{
        ListaEnteros lista;
        int cantidad;
        lista = crear_lista();
        printf("ingrese el tamanio de la lista: ");
        scanf("%d", &cantidad);
        cargar_lista_aleatorio(&lista, cantidad);
        menu_recursivo(&lista);

        return 0;
}

void menu_recursivo(ListaEnteros *lista)
{
        int seleccion;
        printf("\nIngrese una opcion:\n0. salir\n1. mostrar la lista\n2.Insertar un nuevo elemento en una posición ingresada por teclado\n3. buscar un elemento en la lista.\n");
        scanf("%d", &seleccion);
        switch (seleccion) {
                case 0:
                        printf("saliendo...\n");
                        break;
                case 1:
                        mostrar_lista(lista);
                        break;
                case 2:
                        insertar_elemento(lista);
                        break;
                case 3:
                        buscar_elemento(lista);
                        break;
                default:
                        printf("opcion invalida\n");
                        break;
        }
        if(seleccion != 0)
                menu_recursivo(lista);
}

ListaEnteros crear_lista()
{
        ListaEnteros lista;
        lista.size = 0;
        printf("ingrese A: ");
        scanf("%d", &lista.min);
        printf("ingrese B: ");
        scanf("%d", &lista.max);
        return lista;
}
void mostrar_lista(ListaEnteros *lista)
{
        mostrar_elemento(lista, lista->size-1);
}

void cargar_lista_aleatorio(ListaEnteros *lista, int cantidad)
{
       srand(time(NULL));
       lista->size = cantidad;
       cargar_elemento_aleatorio(lista, lista->size - 1);
}

void cargar_elemento_aleatorio(ListaEnteros *lista, int indice)
{
        if(indice > 0)
                cargar_elemento_aleatorio(lista, indice - 1);

        lista->arr[indice] = obtener_aleatorio(lista->min, lista->max);
}

void buscar_elemento(ListaEnteros *lista)
{
        int buscado, indice;
        printf("ingrese el elemento que quiere buscar: ");
        scanf("%d", &buscado);
        indice = busqueda_secuencial_recursiva(lista, lista->size - 1, buscado);
        if(indice == -1)
                printf("no se encontro el elemento\n");
        else
                printf("el elemento esta en el indice %d\n", indice);
}

void mostrar_elemento(ListaEnteros *lista, int indice)
{
        if(indice > 0)
                mostrar_elemento(lista, indice - 1);
        printf("%d, ", lista->arr[indice]);
}



int busqueda_secuencial_recursiva(ListaEnteros *lista, int indice, int buscado)
{
        if(lista->arr[indice] == buscado)
                return indice;

        if(indice > 0)
                return busqueda_secuencial_recursiva(lista, indice - 1, buscado);
        else
                return -1;
        
}

void insertar_elemento(ListaEnteros *lista)
{
        int posicion;
        printf("ingrese la posicion donde quiere insertar: ");
        scanf("%d", &posicion);
        if(posicion < 0) {
                printf("posicion invalida.\n");
        } else {
                mover_elementos_recursivo(lista, posicion, lista->size);
                lista->arr[posicion] = obtener_aleatorio(lista->min, lista->max);
                lista->size++;
        }
                
}
void mover_elementos_recursivo(ListaEnteros *lista, int posicion, int indice)
{
        lista->arr[indice] = lista->arr[indice - 1];
        if(indice - 1 > posicion)
                mover_elementos_recursivo(lista, posicion, indice - 1);
}
int obtener_aleatorio(int min, int max)
{
        return rand() % (max - min + 1) + min;
}
