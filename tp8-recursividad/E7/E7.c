/*
Ejercicio 7: Dada una lista de N números enteros que se ingresa ordenada,
se pide crear un programa recursivo que permita: cargar y mostrar la lista,
a continuación, buscar si encuentra un elemento ingresado por teclado,
en caso de encontrarlo debe mostrar su posición y luego eliminarlo. Nota: Hacer búsqueda binaria. 
 */

#include <stdio.h>
#define ARR_SIZE 30

typedef int IntArray[ARR_SIZE];

typedef struct {
        IntArray arr;
        int size;
} Lista;

Lista crear_lista();
void mostrar_lista(Lista *lista);
void cargar_lista(Lista *lista, int cant);
int buscar_elemento(Lista *lista, int buscado);
void mostrar_elemento(Lista *lista, int indice);
void cargar_elemento(Lista *lista, int       indice);
int busqueda_binaria(Lista *lista, int inicio, int fin, int buscado);

int main()
{
        Lista lista;
        int elemento;
        lista = crear_lista();
        cargar_lista(&lista, 7);
        mostrar_lista(&lista);
        printf("ingrese el elemento a buscar: ");
        scanf("%d", &elemento);
        printf("el elemento esta en la posicion: %d\n", buscar_elemento(&lista, elemento));

        return 0;
}

Lista crear_lista()
{
        Lista lista;
        lista.size = 0;
        return lista;
}
void mostrar_lista(Lista *lista)
{
        mostrar_elemento(lista, lista->size-1);
}

void cargar_lista(Lista *lista, int cant)
{
        lista->size = cant;
        cargar_elemento(lista, lista->size-1);
}

int buscar_elemento(Lista *lista, int buscado)
{
        int indice;
        indice = busqueda_binaria(lista, 0, lista->size - 1, buscado);
        if(lista->arr[indice] != buscado)
                indice = -1;

        return indice;
}

void mostrar_elemento(Lista *lista, int indice)
{
        if(indice > 0)
                mostrar_elemento(lista, indice - 1);
        printf("%d, ", lista->arr[indice]);
}

void cargar_elemento(Lista *lista, int        indice)
{
        if(indice > 0)
                cargar_elemento(lista, indice - 1);
        printf("numero: \n");
        scanf("%d", &lista->arr[indice]);
}

int busqueda_binaria(Lista *lista, int inicio, int fin, int buscado)
{
        int m = (inicio + fin) / 2;
        if((lista->arr[m] != buscado) && (inicio < fin)) {
                if(buscado < lista->arr[m])
                        return busqueda_binaria(lista, inicio, m - 1, buscado);                 
                else
                        return busqueda_binaria(lista, m + 1, fin, buscado);
        }
        else {
                return m;
        } 
        
}
