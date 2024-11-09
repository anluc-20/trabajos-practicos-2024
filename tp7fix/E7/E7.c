#include "../utils/utils.h"
#include "empleados.h"
#include <stdio.h>
#define OPCIONES "a) Agregar un nuevo elemento a la lista de empleados.\nb) Eliminar un empleado.\nc) Indicar el turno que tiene mayor cantidad de empleados.\nd) Dado un turno, mostrar todos sus empleados.e) salir.\nopcion: "

/*
Ejercicio 7: (TAD - Tipo Parcial)  
Una  Agencia  de  Servicios  lleva  una  lista  con  los  datos  de  sus  empleados.  Esta  lista  cuenta  con  la 
siguiente información:

.  Se necesita un programa que permita administrar más eficientemente la lista, para ello debe 
poder cargar la lista de empleados (considerando que se conoce la cantidad N de empleados), ordenarla 
por DNI y posteriormente presentar un menú con las siguientes opciones:  
1. agregar un nuevo empleado.  
2. Eliminar un empleado.  
3. Indicar cuál es el turno que tiene mayor cantidad de empleados.  
4. Dado un turno, mostrar todos sus empleados.  
Se pide:  
a) Presentar  los  TADs  necesarios  para  resolver  el  problema,  escribiendo  la  interfaz  (los  tipos  de 
datos y los prototipos). En este inciso no se solicita escribir la implementación de los módulos.  
b) Implementar todos módulos necesarios para cargar la lista de empleados y ordenarla según DNI, 
utilizando el método de Burbuja.   
c) Implementar la totalidad de los módulos necesarios para resolver el inciso 3.  
d) Desarrollar completamente el programa principal.
*/

void menu(int *salir, ListaEmpleado *empleados);

void menu_a(ListaEmpleado *empleados);
void menu_b(ListaEmpleado *empleados);
void menu_c(ListaEmpleado *empleados);
void menu_d(ListaEmpleado *empleados);

int obtener_empleados_por_turno(ListaEmpleado *empleados, Turno turno);

int main()
{
        int n, i, salir;
        EmpleadoArray array;
        ListaEmpleado empleados;
        empleados = crear_lista_empleado(array);

        ingresar_entero("ingrese la cantidad de empleados: ", &n);
        i = 0;
        while(i < n) {
                if(intentar_agregar_empleado_unico(&empleados)) {
                        i++;
                        printf("se ha agregado correctamente al empleado.\n");
                } else {
                        printf("ya existe ese empleado\n");
                }
        }
        salir = 0;
        while(!salir)
                menu(&salir, &empleados);
}

void menu(int *salir, ListaEmpleado *empleados)
{
        char opcion;

        ingresar_char(OPCIONES, &opcion);
        while((opcion < 'a') || (opcion > 'f'))
                ingresar_char("opcion invalida, porfavor ingrese una opcion valida: ", &opcion);

        switch (opcion) {
                case 'a': 
                        menu_a(empleados);
                        break;
                case 'b': 
                        menu_b(empleados);
                        break;
                case 'c': 
                        menu_c(empleados);
                        break;
                case 'd': 
                        menu_d(empleados);
                        break;
                case 'e': 
                        printf("saliendo...\n");
                        *salir = 1;
                        break;
                case 'f':
                        mostrar_lista_empleado(empleados);
                        break;
        }
}

void menu_a(ListaEmpleado *empleados)
{
        if(intentar_agregar_empleado_unico(empleados))
                printf("se ha agregado correctamente al empleado.\n");
        else
                printf("ya existe ese empleado\n");
}
void menu_b(ListaEmpleado *empleados)
{
        int indice, dni;
        Empleado filtro;
        Fecha fecha;
        ingresar_entero("ingrese el dni: ", &dni);
        filtro =  crear_empleado(dni, "", "", fecha, 0, 0);
        indice = buscar_empleado(empleados, comparar_por_dni, filtro);

        if(indice == -1) {
                printf("no se encontro un empleado con ese dni");
        } else {
                printf("se ha eliminado correctamente al empleado.\n");
                eliminar_empleado(empleados, indice);
        }
}
void menu_c(ListaEmpleado *empleados)
{
        int tamanio, i, mayor_cantidad, cantidad;
        Turno mayor;
        mayor = MANIANA; 
        mayor_cantidad = 0;

        for (i = 0; i < TURNO_SIZE; i++) {
                cantidad = obtener_empleados_por_turno(empleados, (Turno)i);
                if(cantidad > mayor_cantidad) {
                        mayor = (Turno)i;
                        mayor_cantidad = cantidad;
                }
        }

        printf("el turno con mas empleados es el turno %s, tiene %d empleados.\n", TurnoCad[mayor], mayor_cantidad);
}
void menu_d(ListaEmpleado *empleados)
{
        ListaEmpleado salida;
        Empleado filtro;
        Fecha fecha;

        filtro = crear_empleado(0, "", "", fecha, ingresar_turno("ingrese el turno: \n"), 0);
        buscar_empleados(empleados, &salida, comparar_por_turno, filtro);
        if(obtener_tamanio(&salida) == 0) {
                printf("el turno no tiene empleados.\n");
        } else {
                mostrar_lista_empleado(&salida);
        }

}

int obtener_empleados_por_turno(ListaEmpleado *empleados, Turno turno)
{
        ListaEmpleado salida;
        Empleado filtro;
        Fecha fecha;
        int tamanio;
        filtro = crear_empleado(0, "", "", fecha, turno, 0);
        buscar_empleados(empleados, &salida, comparar_por_turno, filtro);
        return obtener_tamanio(&salida);
}