#include "lista_libro.h"
#include <stdio.h>
#include <stdlib.h>


Nodo* crear_nodo()
{
        Nodo *nodo;
        nodo = (Nodo*) malloc(sizeof(Nodo));
        nodo->siguiente = NULL;
        return nodo;
}
ListaLibros crear_lista()
{
        ListaLibros lista = NULL;
        return lista;
}
int existe_nodo(Nodo *cabeza, Nodo *buscado)
{
        int existe = 0;
        while(cabeza != NULL) {
                if(comparar_libro_por_isbn(cabeza->libro, buscado->libro) == 0)
                        existe = 1;
                cabeza = cabeza->siguiente;
        }
        return existe;
}

int intentar_cargar_nodo(Nodo *cabeza, Nodo *nodo)
{
        int resultado;
        nodo->libro = cargar_libro();
        resultado = 1;
        if(existe_nodo(cabeza, nodo)) {
                printf("¡ya existe un libro con ese isbn!\n");
                resultado = 0;
        }
        return resultado;
}


void cargar_inicio(ListaLibros *lista)
{
        Nodo *nuevo;
        nuevo = crear_nodo();
        if(intentar_cargar_nodo(*lista, nuevo) == 0) {
                free(nuevo);
                return;
        }

        if(*lista == NULL) {
                *lista = nuevo;
                return;
        }

        nuevo->siguiente = *lista;
        *lista = nuevo;

}
void cargar_final(ListaLibros *lista)
{
        Nodo *nuevo, *aux;
        nuevo = crear_nodo();
        if(intentar_cargar_nodo(*lista, nuevo) == 0) {
                free(nuevo);
                return;
        }

        if(*lista == NULL) {
                *lista = nuevo;
                return;
        }

        aux = *lista;

        while(aux->siguiente != NULL)
                aux = aux->siguiente;

        aux->siguiente = nuevo;
}
void mostrar_lista(ListaLibros *lista)
{
        Nodo *aux;
        aux = *lista;
        while(aux != NULL) {
                mostrar_libro(aux->libro);
                aux = aux->siguiente;
        }
}
Nodo *buscar_nodo(Nodo *cabeza, int isbn)
{
        Nodo *buscado;
        buscado = NULL;
        while((cabeza != NULL) && (buscado == NULL)) {
                if(comparar_por_isbn(cabeza->libro, isbn) == 0)
                        buscado = cabeza;
                cabeza = cabeza->siguiente;
        }
        return buscado;
}
int buscar_libro(int isbn, ListaLibros *lista, Libro *libro)
{
        Nodo *buscado;
        int resultado;
        resultado = 0;
        buscado = buscar_nodo(*lista, isbn);
        if(buscado != NULL) {
                resultado = 1;
                *libro = buscado->libro;
        }

        return resultado;
}
void modificar_libro_tipo(ListaLibros *lista, int isbn)
{
        Nodo *buscado;
        buscado = buscar_nodo(*lista, isbn);
        if(buscado != NULL)
                modificar_tipo(&buscado->libro);   
        else
                printf("no se encontro un libro con ese isbn\n");
}
