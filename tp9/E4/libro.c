#include "libro.h"
#include <stdio.h>

int carga_tipo()
{
        int tipo;
        printf("seleccione un tipo:\n0. Literatura\n1. Consulta\ntipo: ");
        scanf("%d", &tipo);
        while((tipo < 0) || (tipo > 1)) {
                printf("tipo invalido, ingrese uno valido: ");
                scanf("%d",&tipo);
        }
        return tipo;
}
void mostrar_tipo(int tipo)
{
        printf("tipo: ");
        switch (tipo) {
                case 0:
                        printf("Literatura\n");
                        break;
                case 1:
                        printf("Consulta\n");
                        break;
        }
}


int carga_referencia()
{
        int referencia;
        printf("seleccione una referencia:\n0. Artistico\n1. Divulgativo\n2. Descripcion\ntipo: ");
        scanf("%d", &referencia);
        while((referencia        < 0) || (referencia > 2)) {
                printf("tipo invalido, ingrese uno valido: ");
                scanf("%d",&referencia);
        }
        return referencia;
}

void mostrar_referencia(int referencia)
{
        printf("referencia: ");
        switch (referencia) {
                case 0:
                        printf("Artistico\n");
                        break;
                case 1:
                        printf("Divulgativo\n");
                        break;
                case 2:
                        printf("Descripcion\n");
                        break;
        }
}
Libro cargar_libro()
{
        Libro libro;
        printf("ingrese los siguientes datos:\n");
        printf("nombre: ");
        cargar_cadena(libro.nombre);
        printf("isbn: ");
        scanf("%d", &libro.isbn);
        libro.tipo = carga_tipo();
        libro.referencia = carga_referencia();

        return libro;
}
void mostrar_libro(Libro libro)
{ 
        printf("nombre: %s\n", libro.nombre);
        printf("isbn: %d\n", libro.isbn);
        mostrar_tipo(libro.tipo);
        mostrar_referencia(libro.referencia);
}
void modificar_tipo(Libro *libro)
{
        libro->tipo = carga_tipo();
}

int comparar_libro_por_isbn(Libro a, Libro b)
{
        return (a.isbn > b.isbn) - (a.isbn < b.isbn);
}
int comparar_libro_por_tipo(Libro a, Libro b)
{
        return (a.tipo > b.tipo) - (a.tipo < b.tipo);
}
int comparar_libro_por_referencia(Libro a, Libro b)
{
        return (a.referencia > b.referencia) - (a.referencia < b.referencia);
}
int comparar_libro_por_nombre(Libro a, Libro b)
{
        return comparar_cadena(a.nombre, b.nombre);
}
int comparar_por_isbn(Libro a, int isbn)
{
        return (a.isbn > isbn) - (a.isbn < isbn);
}
