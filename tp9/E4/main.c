/*
 * Ejercicio 4: Considere una pequeña biblioteca que posee un solo ejemplar por cada libro y cree un programa que, a través de un menú de opciones, administre el registro de los libros. Es necesario registrar por cada libro: ISBN del libro, Nombre del libro, Tipo de libro (Literatura, Consulta) y Referencia del libro (Artísticos, Divulgativos, Descripción). El programa debe permitir:   a) Agregar un nuevo libro al inicio de la lista, considerar que el ISBN debe ser único;   b) Mostrar los datos de un libro, dado su número de ISBN;  c) Mostrar la lista de todos los libros;  d) Modificar el campo Tipo de libro, dado su número de ISBN.  */

//Creamos los TAD de libro, lista_libro
//Creamos el menu
//fin

#include "lista_libro.h"
#include <stdio.h>

void menu(ListaLibros *lista);

int main()
{
        ListaLibros lista = crear_lista();
        menu(&lista);
        return 0;
}

void menu(ListaLibros *lista)
{
        int opcion, salir, isbn, resultado;
        Libro libro;
        salir = 0;
        while(!salir) {
                printf("\nOpciones:\n0. Salir\n1. Agregar un nuevo libro al inicio de la lista\n2. Mostrar los datos de un libro\n3. Mostrar la lista de todos los libros\n4. Modificar el campo Tipo de libro\nopcion: ");
        scanf("%d", &opcion);
        getchar();
        switch (opcion) {
                case 0:
                        printf("saliendo...\n");
                        salir = 1;
                        break;
                case 1:
                        cargar_inicio(lista);
                        break;
                case 2:
                        printf("ingrese el isbn: ");
                        scanf("%d", &isbn);
                        resultado = buscar_libro(isbn, lista, &libro);
                        if(resultado == 0)
                                printf("no se encontro un libro con ese isbn\n");
                        else
                                mostrar_libro(libro);
                        break;
                case 3:
                        mostrar_lista(lista);
                        break;
        
                case 4:
                        printf("ingrese el isbn: ");
                        scanf("%d", &isbn);
                        modificar_libro_tipo(lista, isbn);
                        break;

                default:
                        printf("opcion invalida\n");
        }
        }
}
