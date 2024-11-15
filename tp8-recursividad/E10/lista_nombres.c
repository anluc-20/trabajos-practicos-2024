#include "lista_nombres.h"

void enlazar_array(ListaNombres *lista, int indice)
{
        if(indice > 0)
                enlazar_array(lista, indice - 1);
        
        lista->p[indice] = &lista->arr[indice];
}
ListaNombres crear_lista_nombres()
{
        ListaNombres nombres;
        nombres.size = 0;
        enlazar_array(&nombres, LISTA_SIZE - 1);
        return nombres;
}
void cargar_nombres_r(ListaNombres *lista, int indice)
{
        if(indice > 0)
                cargar_nombres_r(lista, indice - 1);
        ingresar_cadena(*lista->p[indice]);
        mostrar_cadena(*lista->p[indice]);
}
void cargar_nombres(ListaNombres *lista, int cantidad)
{
        cargar_nombres_r(lista, cantidad - 1);
        lista->size = cantidad;
}
void mostrar_nombres_r(ListaNombres *lista, int indice)
{
        if(indice > 0)
                mostrar_nombres_r(lista, indice - 1);
        mostrar_cadena(*lista->p[indice]);
}
void mostrar_nombres(ListaNombres *lista)
{
        mostrar_nombres_r(lista, lista->size-1);
}

void merge(ListaNombres * lista, int inicio1, int fin1, int inicio2, int fin2)
{
        ListaNombres temp_lista = crear_lista_nombres();
        int i;
        i = 0;
        while((inicio1 <= fin1) && (inicio2 <= fin2)) {
                if(comparar_cadena(*lista->p[inicio1], *lista->p[inicio2]) < 0) {
                        temp_lista.p[i] = lista->p[inicio1];
                        inicio1++;
                } else {
                        temp_lista.p[i] = lista->p[inicio2];
                        inicio2++;
                }
                i++;
        }
        while (inicio1 <= fin1) {
                temp_lista.p[i] = lista->p[inicio1];
                inicio1++;
                i++;
        }
        while (inicio2 <= fin2) {
                temp_lista.p[i] = lista->p[inicio2];
                inicio2++;
                i++;
        }
        
        inicio1 = fin2 - i + 1;
        inicio2 = 0;
        while (inicio2 < i) {
                lista->p[inicio1] = temp_lista.p[inicio2];
                inicio1++;
                inicio2++;
        }
}
void merge_sort(ListaNombres *lista, int inicio, int fin) 
{
        if(inicio < fin) {
                merge_sort(lista, inicio, inicio + (fin-inicio)/2); //sublista izquierda
                merge_sort(lista, inicio + (fin-inicio)/2 + 1, fin); //sublista derecha
        } else {
                return; // cuando sea una sublista de tamanio 1 no hacemos nada y retornamos
        }
        merge(lista, inicio, inicio + (fin-inicio)/2, inicio + (fin-inicio)/2 + 1, fin);
}

void ordenar_nombres(ListaNombres *lista)
{
        merge_sort(lista, 0, lista->size - 1);
}
