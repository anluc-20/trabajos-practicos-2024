#include "lista_enteros.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


NodoPtr crear_nodo()
{
        NodoPtr nodo = NULL;
        nodo = (NodoPtr) malloc(sizeof(Nodo));
        nodo->numero = 0;
        nodo->siguiente = NULL;
        return nodo;
}
void cargar_nodo(NodoPtr *nodo)
{
        printf("ingrese el numero: ");
        scanf("%d", &(*nodo)->numero);
}
NodoPtr crear_y_cargar_nodo()
{
        NodoPtr nodo = crear_nodo();
        cargar_nodo(&nodo);
        return nodo;
}
NodoPtr crear_lista()
{
        NodoPtr cabeza = NULL;
        return cabeza;
}

void cargar_lista(NodoPtr *cabeza)
{
        NodoPtr aux;
        int n, i, random;
        srand(time(NULL));
        printf("ingrese la cantidad de elementos de la lista: ");
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
                random = rand();
                aux = crear_nodo();
                aux->numero = random;
                if(random % 2 == 0)
                        carga_principio(cabeza, aux);
                else
                        carga_final(cabeza, aux);
        }
}

void carga_principio(NodoPtr *cabeza, NodoPtr nodo)
{
        NodoPtr aux;
        if(*cabeza == NULL) {
                *cabeza = nodo;
                return;
        }
                

        aux = *cabeza;
        while(aux->siguiente != NULL)
                aux = aux->siguiente;

        aux->siguiente = nodo;
}
void carga_final(NodoPtr *cabeza, NodoPtr nodo)
{
        if(*cabeza == NULL) {
                *cabeza = nodo;
                return;
        }

        nodo->siguiente = *cabeza;
        *cabeza = nodo;
}
void mostrar_lista(NodoPtr cabeza)
{
        while(cabeza != NULL) {
                printf("%d, ", cabeza->numero);
                cabeza = cabeza->siguiente;
        }
}
void mostrar_mayores_que(NodoPtr cabeza, int numero)
{
        while(cabeza != NULL) {
                if(cabeza->numero > numero)
                        printf("%d, ", cabeza->numero);
                cabeza = cabeza->siguiente;
        }
}