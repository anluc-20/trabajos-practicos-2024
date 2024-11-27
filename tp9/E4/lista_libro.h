#include "libro.h"

typedef struct Nodo Nodo;
struct Nodo {
        Libro libro;
        Nodo *siguiente;
};

typedef Nodo *ListaLibros;

ListaLibros crear_lista();
void cargar_inicio(ListaLibros *lista);
void cargar_final(ListaLibros *lista);
void mostrar_lista(ListaLibros *lista);
void modificar_libro_tipo(ListaLibros *lista, int isbn);
int buscar_libro(int isbn, ListaLibros *lista, Libro *libro);
