#include "articulo.h"
#include "../utils/utils.h"
#include <stdio.h>

int comparar_por_codigo(Articulo *articulo1, Articulo *articulo2)
{
        return (articulo1->codigo > articulo2->codigo) - (articulo1->codigo < articulo2->codigo);
}

void ingresar_articulo(Articulo *articulo, int codigo)
{
        ingresar_texto("nombre: ", articulo->nombre, CADENA_MAX_SIZE);
        ingresar_texto("proveedor: ", articulo->proveedor, CADENA_MAX_SIZE);
        ingresar_entero("stock: ", &articulo->stock);
        ingresar_double("precio: ", &articulo->precio);
        articulo->codigo = codigo;
}
void ordenar_lista_articulos(ListaArticulos *articulos, Comparador comparar)
{
        int i, j;
        Articulo *aux;
        for (i = 1; i < articulos->size; i++) {
                j = i - 1;
                while((j >= 0) && (comparar(articulos->p[j+1], articulos->p[j]) < 0)) {
                        aux = articulos->p[j+1];
                        articulos->p[j+1] = articulos->p[j];
                        articulos->p[j] = aux;
                        j--;
                }
        }
}
void eliminar_articulo(ListaArticulos *articulos, int indice)
{
        int i;
        articulos->size--;
        for (i = indice; i < articulos->size; i++) {
                articulos->p[i] = articulos->p[i + 1];
        }
}
void buscar_articulos(const ListaArticulos *articulos, ListaArticulos *salida, Comparador comparar, Articulo comparado)
{
        int i;
        salida->size = 0;
        for (i = 0; i < articulos->size; i++) {
                if(comparar(articulos->p[i], &comparado) == 0) {
                        salida->p[salida->size] = articulos->p[i];
                        salida->size++;
                }
        }
}
void inicializar_lista_articulos(ListaArticulos *articulos, Articulo *array)
{
        int i;
        for (i = 0; i < ARTICULOS_MAX_SIZE; i++) {
                articulos->p[i] = &array[i];
        }
        articulos->size = 0;
}
int buscar_articulo(ListaArticulos *articulos, int codigo)
{
        int inicio, fin, m;
        inicio = 0;
        fin = articulos->size - 1;
        m = (inicio + fin) / 2;
        while((inicio < fin) && (articulos->p[m]->codigo != codigo)) {
                if(articulos->p[m]->codigo > codigo)
                        fin = m - 1;
                else
                        inicio = m + 1;
                m = (inicio + fin) / 2;
        }
        if(articulos->p[m]->codigo != codigo)
                m = -1;

        return m;
}
void agregar_articulo(ListaArticulos *articulos)
{
        int codigo;
        if(articulos->size >= ARTICULOS_MAX_SIZE) {
                printf("no se pueden agregar mas articulos, la lista esta llena.\n");
        } else {
                ingresar_entero("codigo: ", &codigo);
                while(buscar_articulo(articulos, codigo) != -1)
                        ingresar_entero("ya existe un articulo con ese codigo, ingrese otro: ", &codigo);
                ingresar_articulo(articulos->p[articulos->size], codigo);
                articulos->size++;
                ordenar_lista_articulos(articulos, comparar_por_codigo);
        }
}
void mostrar_articulo(const Articulo *articulo)
{
        printf("codigo: %d\n", articulo->codigo);
        printf("nombre: %s\n", articulo->nombre);
        printf("proveedor: %s\n", articulo->proveedor);
        printf("stock: %d\n", articulo->stock);
        printf("precio: %lf\n", articulo->precio);
}
void mostrar_articulos(const ListaArticulos *articulos)
{
        int i;
        for (i = 0; i < articulos->size; i++) {
                printf("[%d/%d]: \n", i, articulos->size - 1);
                mostrar_articulo(articulos->p[i]);
        }
}
