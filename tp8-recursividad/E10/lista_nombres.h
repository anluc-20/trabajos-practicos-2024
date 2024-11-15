#include "../cadena/cadena_r.h"
#define LISTA_SIZE 20

typedef struct {
        Cadena arr[LISTA_SIZE];
        Cadena *p[LISTA_SIZE];
        int size;
} ListaNombres;

ListaNombres crear_lista_nombres();
void cargar_nombres(ListaNombres *lista, int cantidad);
void mostrar_nombres(ListaNombres *lista);
void ordenar_nombres(ListaNombres *lista);
