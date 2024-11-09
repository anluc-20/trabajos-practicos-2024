#include "alumno.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <string.h>
#define OPCIONES "a) Agregar un nuevo elemento a la lista de alumnos. \nb) Modificar los datos de un alumno dado su DNI y el Curso de Postgrado. \nc) Generar y mostrar una lista de alumnos que están cursando un Curso de Postgrado ingresado por teclado, la lista se debe ordenar alfabéticamente por Apellido y Nombre\nd) Dada una fecha ingresada desde teclado, modificar el estado del registro a Baja, si desde la Fecha de Inicio a la fecha ingresada pasaron más de 365 días.\nopcion: "
/*
Ejercicio 3: Se tiene que administrar una lista de N alumnos de Postgrado, de cada alumno se lleva la
siguiente información: DNI; Apellido y Nombre; Título de grado; Curso de Postgrado; Fecha Inicio del
curso de postgrado, Fecha Finalización del curso de postgrado; Estado (En curso, Finalizado, Pendiente,
Baja).
Se solicita un programa convenientemente modularizado que implementando TADs, permita ingresar una
lista de N alumnos de postgrado y que a través de un menú permita realizar las siguientes actividades:
a) Agregar un nuevo elemento a la lista de alumnos.
b) Modificar los datos de un alumno dado su DNI y el Curso de Postgrado.
c) Generar y mostrar una lista de alumnos que están cursando un Curso de Postgrado ingresado
por teclado, la lista se debe ordenar alfabéticamente por Apellido y Nombre.
d) Dada una fecha ingresada desde teclado, modificar el estado del registro a Baja, si desde la Fecha
de Inicio a la fecha ingresada pasaron más de 365 días. 
*/

void menu_loco(int *salir, ListaAlumnos *p_alumnos);

//opciones de menu
void menu_a(ListaAlumnos *p_alumnos);
void menu_b(ListaAlumnos *p_alumnos);
void menu_c(ListaAlumnos *p_alumnos);
void menu_d(ListaAlumnos *p_alumnos);

//funciones
int comparar_por_cadena(AlumnoPostgrado *alumno1, AlumnoPostgrado *alumno2);

int main()
{
        int i, salir;
        ListaAlumnos alumnos;
        inicializar_lista_alumnos(&alumnos);

        ingresar_entero("ingrese la cantidad de alumnos: ", &alumnos.size);

        for (i = 0; i < alumnos.size; i++) {
                printf("Alumno [%d/%d]:\n", i, alumnos.size - 1);
                ingresar_alumno(alumnos.p_arr[i]);
        }

        salir = 0;
        while (!salir) {
                menu_loco(&salir, &alumnos);
        }
}

void menu_loco(int *salir, ListaAlumnos *p_alumnos)
{
        char opcion;
        ingresar_char(OPCIONES, &opcion);
        while((opcion < 'a') || (opcion > 'f'))
                ingresar_char("opcion invalida, ingrese una valida: ", &opcion);
        
        switch (opcion) {
                case 'a':
                        menu_a(p_alumnos);
                        break;
                case 'b':
                        menu_b(p_alumnos);
                        break;
                case 'c':
                        menu_c(p_alumnos);
                        break;
                case 'd':
                        menu_d(p_alumnos);
                        break;
                case 'e':
                        printf("saliendo...\n");
                        *salir = 1;
                        break;
                case 'f':
                        mostrar_lista_alumnos(p_alumnos);
                        break;
        }
}

void menu_a(ListaAlumnos *p_alumnos)
{
        agregar_alumno(p_alumnos);
}
void menu_b(ListaAlumnos *p_alumnos)
{
        int dni, indice, i;
        Cadena curso, dni_curso;
        ingresar_entero("ingrese el dni: ", &dni);
        ingresar_texto("ingrese el curso de postgrado: ", curso, CADENA_MAX_SIZE);
        sprintf(dni_curso, "%d%s", dni, curso);

        indice = -1;
        i = 0;
        while((i < p_alumnos->size) && (indice == -1)) {
                if(strcmp(p_alumnos->p_arr[i]->dni_curso, dni_curso) == 0)
                        indice = i;
                i++;
        }
        if(indice == -1) {
                printf("no se encontro un alumno con ese dni y curso de postgrado.\n");
        } else {
                printf("ingrese los nuevos datos del alumno: \n");
                ingresar_alumno(p_alumnos->p_arr[indice]);
                printf("se han modificado correctamente los datos del alumno.\n");
        }
}
void menu_c(ListaAlumnos *p_alumnos) {
        int i;
        ListaAlumnos new_alumnos;
        Cadena curso;
        inicializar_lista_alumnos(&new_alumnos);

        ingresar_texto("ingrese el curso de postgrado: ", curso, CADENA_MAX_SIZE);

        for (i = 0; i < p_alumnos->size; i ++) {
                if(strcmp(p_alumnos->p_arr[i]->curso_de_postgrado, curso) == 0) {
                        new_alumnos.arr[new_alumnos.size] = *p_alumnos->p_arr[i];
                        new_alumnos.size++;
                }    
        }
        if(new_alumnos.size == 0) {
                printf("no se encontraron alumnos con ese curso de postgrado\n");
        } else {
                printf("me mori aca\n");
                ordenar_lista_alumnos(&new_alumnos, comparar_por_cadena);
                mostrar_lista_alumnos(&new_alumnos);
        }

}
void menu_d(ListaAlumnos *p_alumnos)
{
        Fecha fecha;
        int diferencia, i, band;
        band = 0;
        fecha = ingresar_fecha("ingrese una fecha: \n");
        for (i = 0; i < p_alumnos->size; i++) {
                diferencia = dias_entre_fechas(fecha, p_alumnos->p_arr[i]->inicio_postgrado);
                if(diferencia > 365) {
                        band = 1;
                        p_alumnos->p_arr[i]->estado = BAJA;
                        printf("se ha dado de baja a el alumno: \n");
                        mostrar_alumno(*p_alumnos->p_arr[i]);
                }   
        }
        if(band == 0)
                printf("no se ha dado de baja a ningun alumno.\n");
}


int comparar_por_cadena(AlumnoPostgrado *alumno1, AlumnoPostgrado *alumno2)
{
        return strcmp(alumno1->apellido_nombre, alumno2->apellido_nombre);
}