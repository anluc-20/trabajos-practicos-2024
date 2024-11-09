#include "../fecha/fecha.h"
#define CADENA_MAX_SIZE 30
#define LISTA_ALUMNOS_MAX_SIZE 30
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
typedef char Cadena[CADENA_MAX_SIZE];
typedef enum {
        EN_CURSO,
        FINALIZADO,
        PENDIENTE,
        BAJA
} Estado;
typedef struct {
        int dni;
        Cadena apellido;
        Cadena nombre;
        Cadena titulo_de_grado;
        Cadena curso_de_postgrado;
        Fecha inicio_postgrado;
        Fecha fin_de_postgrado;
        Estado estado;
        Cadena apellido_nombre;
        Cadena dni_curso;
} AlumnoPostgrado;

typedef struct {
        AlumnoPostgrado arr[LISTA_ALUMNOS_MAX_SIZE];
        AlumnoPostgrado *p_arr[LISTA_ALUMNOS_MAX_SIZE];
        int size;
} ListaAlumnos;
typedef int (*Comparador)(AlumnoPostgrado* , AlumnoPostgrado*);

void inicializar_lista_alumnos(ListaAlumnos *lista);
void ingresar_alumno(AlumnoPostgrado *alumno);
void agregar_alumno(ListaAlumnos *p_alumnos);
Estado ingresar_estado(char *mensaje);
void ordenar_lista_alumnos(ListaAlumnos *p_lista_alumnos, Comparador comparador);
void mostrar_lista_alumnos(ListaAlumnos *p_alumnos);
void mostrar_alumno(AlumnoPostgrado alumno);
