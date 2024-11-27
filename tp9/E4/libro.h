#include "../cadena/cadena.h"
typedef struct {
        int isbn, tipo, referencia;
        Cadena nombre;
} Libro;

Libro cargar_libro();
void mostrar_libro(Libro libro);
void modificar_tipo(Libro *libro);
int comparar_libro_por_isbn(Libro a, Libro b);
int comparar_libro_por_tipo(Libro a, Libro b);
int comparar_libro_por_referencia(Libro a, Libro b);
int comparar_libro_por_nombre(Libro a, Libro b);
int comparar_por_isbn(Libro a, int isbn);
