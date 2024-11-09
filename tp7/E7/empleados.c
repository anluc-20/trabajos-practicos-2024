#include "empleados.h"
#include "../utils/utils.h"
#include <string.h>
#include <stdio.h>

void inicializar_lista_empleado(ListaEmpleado *empleados, EmpleadoArray array)
{
        int i;
        for (i = 0; i < EMPLEADOS_MAX_SIZE; i++) {
                empleados->p[i] = &array[i];
        }
        empleados->size = 0;
}
Empleado ingresar_empleado(int dni)
{
        Empleado empleado;
        empleado.dni = dni;
        ingresar_texto("apellido: ", empleado.apellido, CAD_MAX_SIZE);
        ingresar_texto("nombre: ", empleado.nombre, CAD_MAX_SIZE);
        empleado.fecha_de_alta = ingresar_fecha("ingrese la fecha de alta:\n");
        empleado.turno = ingresar_turno("seleccione un turno:\n");
        ingresar_long("celular: ", &empleado.celular);
        sprintf(empleado.apellido_nombre, "%s%s", empleado.apellido, empleado.nombre);
        return empleado;
}
Turno ingresar_turno(char *mensaje)
{
        int i, opcion;
        printf("%s", mensaje);
        for (i = 0; i < TURNO_SIZE; i++) {
                printf("[%d]: %s\n", i, TurnoCad[i]);
        }
        ingresar_entero("Opcion: ", &opcion);
        while((opcion < 0) || (opcion > TURNO_SIZE - 1))
                ingresar_entero("opcion invalida, elija una valida: ", &opcion);

        return (Turno)opcion;
}
int intentar_agregar_empleado_unico(ListaEmpleado *empleados)
{
        Empleado filtro;
        int resultado;
        ingresar_entero("dni: ", &filtro.dni);
        if(buscar_empleado(empleados, comparar_por_dni, filtro) != -1) {
                resultado = 0;
        } else {
                mostrar_lista_empleado(empleados);
                resultado = 1;
                *empleados->p[empleados->size] = ingresar_empleado(filtro.dni);
                empleados->size++;
                mostrar_lista_empleado(empleados);
                ordenar_lista_empleado(empleados, comparar_por_dni);
                mostrar_lista_empleado(empleados);
        }
        return resultado;
}
void mostrar_empleado(const Empleado *empleado)
{
        printf("%d\t\t", empleado->dni);
        printf("%s\t\t", empleado->apellido);
        printf("%s\t\t", empleado->nombre);
        printf("%s\t\t", empleado->fecha_de_alta.todo_junto);
        printf("%s\t\t", TurnoCad[empleado->turno]);
        printf("%ld\n", empleado->celular);
}
void mostrar_un_empleado(const Empleado *empleado)
{
        printf("DNI\t\tAPELLIDO\t\tNOMBRE\t\tALTA\t\tTURNO\t\tCELULAR\n");
        printf("%d\t\t", empleado->dni);
        printf("%s\t\t", empleado->apellido);
        printf("%s\t\t", empleado->nombre);
        printf("%s\t\t", empleado->fecha_de_alta.todo_junto);
        printf("%s\t\t", TurnoCad[empleado->turno]);
        printf("%ld\n", empleado->celular);
}
void mostrar_lista_empleado(const ListaEmpleado *empleados)
{
        int i;
        printf("DNI\t\tAPELLIDO\t\tNOMBRE\t\tALTA\t\tTURNO\t\tCELULAR\n");
        for (i = 0; i < empleados->size; i++) {
                mostrar_empleado(empleados->p[i]);
        }
}
int buscar_empleado(const ListaEmpleado *empleados, Comparador comparar, Empleado filtro)
{
        int inicio, fin, m;
        inicio = 0;
        fin = empleados->size - 1;
        m = (inicio + fin) / 2;
        while((inicio < fin)  && (comparar(empleados->p[m], &filtro) != 0)) {
                if(comparar(empleados->p[m], &filtro) > 0)
                        fin = m - 1;
                else
                        inicio = m + 1;
                m = (inicio + fin) / 2;
        }
        if(comparar(empleados->p[m], &filtro) != 0)
                m = -1;
        return m;
}
void ordenar_lista_empleado(ListaEmpleado *empleados, Comparador comparar)
{
        int i, j;
        Empleado *aux;
        for (i = 1; i < empleados->size; i++) {
                j = i - 1;
                while((j >= 0) && (comparar(empleados->p[j+1], empleados->p[j]) < 0)) {
                        aux = empleados->p[j+1];
                        empleados->p[j+1] = empleados->p[j];
                        empleados->p[j] = aux;
                        j--;
                }
        }
}
void buscar_empleados(const ListaEmpleado *empleados, ListaEmpleado *salida, Comparador comparar, Empleado filtro)
{
        int i;
        salida->size = 0;
        for (i = 0; i < empleados->size; i++) {
                if(comparar(empleados->p[i], &filtro) == 0) {
                        salida->p[salida->size] = empleados->p[i];
                        salida->size++;
                }
        }
}
void eliminar_empleado(ListaEmpleado *empleados, int indice)
{
        int i;
        Empleado *borrado = empleados->p[indice];

        empleados->size--;
        for (i = indice; i < empleados->size; i++) {
                empleados->p[i] = empleados->p[i+1];
        }
        empleados->p[empleados->size] = borrado;
}

int comparar_por_dni(Empleado *a, Empleado *b)
{
        return (a->dni > b->dni) - (a->dni < b->dni);
}
int comparar_por_apellido_nombre(Empleado *a, Empleado *b)
{
        return strcmp(a->apellido_nombre, b->apellido_nombre);
}
int comparar_por_turno(Empleado *a, Empleado *b)
{
        return (a->turno > b->turno) - (a->turno < b->turno);
}