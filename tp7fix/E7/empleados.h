#include "../fecha/fecha.h"
#include "../cadena/cadena.h"
#include "../utils/utils.h"
#include <string.h>
#include <stdio.h>
#define EMPLEADOS_MAX_SIZE 30
#define TURNO_SIZE 3

/*
DNI
Apellido
Nombre
Fecha de Alta
Turno disponible (mañana, tarde y noche), 
Celular
*/


typedef enum {
        MANIANA,
        TARDE,
        NOCHE
} Turno;
static const char *TurnoCad[TURNO_SIZE] =
{
        "MANIANA",
        "TARDE",
        "NOCHE"   
};
typedef struct {
        int dni;
        Cadena apellido;
        Cadena nombre;
        Fecha fecha_de_alta;
        Turno turno;
        long celular;
        Cadena apellido_nombre;
} Empleado;

typedef Empleado EmpleadoArray[EMPLEADOS_MAX_SIZE];
typedef struct {
        Empleado *p[EMPLEADOS_MAX_SIZE];
        int size;
} ListaEmpleado;

typedef int (*Comparador)(Empleado*, Empleado*);

ListaEmpleado crear_lista_empleado(EmpleadoArray array);
Empleado crear_empleado(int dni, Cadena apellido, Cadena nombre, Fecha fecha_de_alta, Turno turno, long celular);
Empleado ingresar_empleado(int dni);
Turno ingresar_turno(char *mensaje);
int obtener_tamanio(ListaEmpleado *empleados);
int intentar_agregar_empleado_unico(ListaEmpleado *empleados);
void mostrar_empleado(const Empleado *empleado);
void mostrar_un_empleado(const Empleado *empleado);
void mostrar_lista_empleado(const ListaEmpleado *empleados);
int buscar_empleado(const ListaEmpleado *empleados, Comparador comparar, Empleado filtro);
void ordenar_lista_empleado(ListaEmpleado *empleados, Comparador comparar);
void buscar_empleados(const ListaEmpleado *empleados, ListaEmpleado *salida, Comparador comparar, Empleado filtro);
void eliminar_empleado(ListaEmpleado *empleados, int indice);

int comparar_por_dni(Empleado *a, Empleado *b);
int comparar_por_apellido_nombre(Empleado *a, Empleado *b);
int comparar_por_turno(Empleado *a, Empleado *b);