#include "alumno.h"
#include "../utils/utils.h"
#include <stdio.h>


void ingresar_alumno(AlumnoPostgrado *alumno)
{
        ingresar_entero("dni: ", &alumno->dni);
        ingresar_texto("apellido: ", alumno->apellido, CADENA_MAX_SIZE);
        ingresar_texto("nombre: ", alumno->nombre, CADENA_MAX_SIZE);
        ingresar_texto("titulo de grado: ", alumno->titulo_de_grado, CADENA_MAX_SIZE);
        ingresar_texto("curso de postgrado: ", alumno->curso_de_postgrado, CADENA_MAX_SIZE);
        alumno->inicio_postgrado = ingresar_fecha("fecha de inicio de postgrado: \n");
        alumno->fin_de_postgrado = ingresar_fecha("fecha de fin de postgrado: \n");
        while(dias_entre_fechas(alumno->fin_de_postgrado, alumno->inicio_postgrado) < 0)
                alumno->fin_de_postgrado = ingresar_fecha("la fecha de fin no puede ser menor que la fecha de inicio, ingresa una fecha valida: \n");
        
        alumno->estado = ingresar_estado("seleccione un estado:\n");
        sprintf(alumno->apellido_nombre, "%s%s",alumno->apellido, alumno->nombre);
        sprintf(alumno->dni_curso, "%d%s", alumno->dni, alumno->curso_de_postgrado);
}
Estado ingresar_estado(char *mensaje)
{
        int estado;
        
        printf("%s", mensaje);
        ingresar_entero("[0] EN CURSO.\n[1] FINALIZADO.\n[2] PENDIENTE.\n[3] BAJA.\nopcion: ", &estado);
        while((estado > 3) || (estado < 0))
                ingresar_entero("opcion invalida, eliga una valida: ", &estado);
        return (Estado)estado;
}

void ordenar_lista_alumnos(ListaAlumnos *p_lista_alumnos, Comparador comparador)
{
        int i, j;
        AlumnoPostgrado *aux;
        for (i = 1; i < p_lista_alumnos->size; i++) {
                j = i - 1;
                while ((j >= 0) && (comparador(p_lista_alumnos->p_arr[j+1], p_lista_alumnos->p_arr[j]) < 0)) {
                        aux = p_lista_alumnos->p_arr[j+1];
                        p_lista_alumnos->p_arr[j+1] = p_lista_alumnos->p_arr[j];
                        p_lista_alumnos->p_arr[j] = aux;
                        j--;
                }
        }
}
void agregar_alumno(ListaAlumnos *p_alumnos)
{
        ingresar_alumno(p_alumnos->p_arr[p_alumnos->size]);
        p_alumnos->size++;
}

void inicializar_lista_alumnos(ListaAlumnos *lista)
{
        int i;
        for (i = 0; i < LISTA_ALUMNOS_MAX_SIZE; i++) {
                lista->p_arr[i] = &lista->arr[i];
        }
        lista->size = 0;
}
void mostrar_lista_alumnos(ListaAlumnos *p_alumnos)
{
        int i;
        for (i = 0; i < p_alumnos->size; i++) {
                printf("Alumno [%d/%d]:\n", i, p_alumnos->size - 1);
                mostrar_alumno(*p_alumnos->p_arr[i]);
        }
}
void mostrar_alumno(AlumnoPostgrado alumno)
{
        printf("dni: %d\n", alumno.dni);
        printf("apellido: %s\n", alumno.apellido);
        printf("nombre: %s\n", alumno.nombre);
        printf("titulo de grado: %s\n", alumno.titulo_de_grado);
        printf("curso de postgrado: %s\n", alumno.curso_de_postgrado);
        printf("fecha de inicio de postgrado: %s\n", alumno.inicio_postgrado.todo_junto);
        printf("fecha de fin de postgrado: %s\n", alumno.fin_de_postgrado.todo_junto);
        printf("estado: ");
        switch (alumno.estado) {

        case EN_CURSO:
                printf("EN CURSO\n");
                break;
        case FINALIZADO:
                printf("FINALIZADO\n");
                break;
        case PENDIENTE:
                printf("PENDIENTE\n");
                break;
        case BAJA:
                printf("BAJA\n");
                break;
        }
}