/*
        Ejercicio 9: Se pide crear un programa recursivo que permita generar aleatoriamente una lista de N números enteros en el intervalo [A, B], luego presentar un menú de opciones (el cual debe ser recursivo) que permita realizar las siguientes tareas: ordenar ascendentemente utilizando el método Q-Sort, buscar un elemento en la lista (dicho elemento es ingresado por teclado).
 * */
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
void buscar_elemento(ListaEnteros *lista);
void mostrar_elemento(ListaEnteros *lista, int indice);
int busqueda_binaria(ListaEnteros *lista, int inicio, int fin, int buscado);
int obtener_aleatorio(int min, int max);
void ordenar_ascendente(ListaEnteros *lista);
void q_sort(ListaEnteros *lista, int inicio, int fin);
int obtener_pivot(ListaEnteros *lista, int inicio, int fin);

void menu_recursivo(ListaEnteros *lista);

int main()
{

        ListaEnteros lista;// = {{4,8,2,1,9,5,7,3,6}, 9, 0, 0};
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
        printf("\nIngrese una opcion:\n0. salir\n1. mostrar la lista\n2. Ordenar ascendentemente\n3. buscar un elemento en la lista.\n");
        scanf("%d", &seleccion);
        switch (seleccion) {
                case 0:
                        printf("saliendo...\n");
                        break;
                case 1:
                        mostrar_lista(lista);
                        break;
                case 2:
                        ordenar_ascendente(lista);
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
        indice = busqueda_binaria(lista, 0, lista->size - 1, buscado);
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



int obtener_aleatorio(int min, int max)
{
        return rand() % (max - min + 1) + min;
}
int busqueda_binaria(ListaEnteros *lista, int inicio, int fin, int buscado)
{
        int m = (inicio + fin) / 2;
        if(inicio > fin)
                return -1;
        if(lista->arr[m] == buscado) {
                return m;
        } else {
                if(buscado < lista->arr[m])
                        return busqueda_binaria(lista, inicio, m - 1, buscado);                 
                else
                        return busqueda_binaria(lista, m + 1, fin, buscado); 
        } 
        
}

void ordenar_ascendente(ListaEnteros *lista)
{
        q_sort(lista, 0, lista->size - 1);
}
void q_sort(ListaEnteros *lista, int inicio, int fin)
{
        int pivot;
        pivot = obtener_pivot(lista, inicio, fin);

        //sublista izquierds
        if(inicio + 1 < pivot)// nos aseguramos que la sublista sea de almenos dos elementos
                q_sort(lista, inicio, pivot - 1);

        if(pivot + 1 < fin) //nos aseguramos que la sublista sea de almenos dos elementos
                q_sort(lista, pivot + 1, fin);

}
int obtener_pivot(ListaEnteros *lista, int inicio, int fin)
{
        int apuntador, i, pivot, aux;
        pivot = lista->arr[fin];
        apuntador = inicio - 1;
        for (i = inicio; i <= fin ; i++) {
                if (lista->arr[i] <= pivot) {
                        apuntador++;
                        aux = lista->arr[i];
                        lista->arr[i] = lista->arr[apuntador];
                        lista->arr[apuntador] = aux;
                }
        }
        return apuntador;
}


