#include "TAD_ListaPacientes.h"
#include <stdio.h>

/*COMPLETAR*/

TLista inicializa_lista()
{
        TLista lista;
        lista.tam = 0;
        return lista;
}
int retorna_tam(TLista lista)
{
        return lista.tam;
}
void carga_paciente_r(TVector vector, int indice)
{
        if(indice >= 0) {
                carga_paciente_r(vector, indice - 1);
                vector[indice] = cargar_paciente();
        }
}
TLista carga_pacientes()
{
        TLista lista = inicializa_lista();
        printf("ingrese la cantidad de pacientes: ");
        scanf("%d", &lista.tam);
        getchar(); //limpio el salto de linea
        carga_paciente_r(lista.lis, lista.tam - 1);
        return lista;
}
void agrega_pacientes(TLista *lista)
{
        lista->lis[lista->tam] = cargar_paciente();
        lista->tam++;
}
void elimina_paciente_r(TLista *lista, int posicion)
{
        if(posicion < lista->tam - 1) {
                lista->lis[posicion] = lista->lis[posicion + 1];
                elimina_paciente_r(lista, posicion + 1);
        }
}
int elegir_paciente(TLista *lista)
{
        int opcion;
        printf("Seleccione un paciente: \n");
        mostra_pacientes(*lista);
        printf("opcion: ");
        scanf("%d", &opcion);
        if((opcion < 0) || (opcion > lista->tam - 1)) {
                printf("opcion invalida.\n");
                opcion = elegir_paciente(lista);
        }
        return opcion;
}
void elimina_pacientes(TLista *lista)
{
        int posicion;
        posicion = elegir_paciente(lista);
        elimina_paciente_r(lista, posicion);
        lista->tam--;
        printf("se ha eliminado correctamente el paciente.\n");
}
void modifica_pacientes(TLista *lista)
{
        int posicion;
        posicion = elegir_paciente(lista);
        modificar_paciente(&lista->lis[posicion]);
        printf("se ha modificado correctamente el paciente. \n");      
}

void mostrar_r(TVector vector, int indice)
{
        if(indice >= 0) {
                mostrar_r(vector, indice - 1);
                printf("\n\nPACIENTE [%d]\n", indice);
                mostrar_paciente(vector[indice]);
        }
}
void mostra_pacientes(TLista lista)
{
        mostrar_r(lista.lis, lista.tam - 1);
}
void genera_atencion_r(TLista *lista, TLista *atencion, int indice, long fecha, int tipo)
{
        if(indice >= 0) {
                genera_atencion_r(lista, atencion, indice - 1, fecha, tipo);
                if(compara_fecha_tipo(lista->lis[indice], fecha, tipo) == 1) {
                        atencion->lis[atencion->tam] = lista->lis[indice];
                        atencion->tam++;
                }
        }
}
TLista genera_atencion(TLista lista)
{
        long fecha, tipo;
        TLista atencion = inicializa_lista();
        printf("ingrese la fecha: ");
        scanf("%ld", &fecha);
        printf("ingrese el tipo: ");
        scanf("%ld", &tipo);
        genera_atencion_r(&lista, &atencion, lista.tam - 1, fecha, tipo);
        return atencion;
}
int obtener_pivot(TLista *lista, int inicio, int fin)
{
        int apuntador, i;
        RPaciente aux;
        apuntador = inicio - 1;
        for(i = inicio; i <= fin; i++) {
                if(compara_apellidos(lista->lis[i], lista->lis[fin]) <= 0) { //comparo con mi pivot (el ultimo elemento)
                        apuntador++;
                        aux =  lista->lis[i];
                        lista->lis[i] = lista->lis[apuntador];
                        lista->lis[apuntador] = aux;
                }
        }
        return apuntador;
}
void q_sort(TLista *lista, int inicio, int fin) {
        int pivot;
        if(inicio <= fin)
                return; //lista de tamanio 1 o menor, retornamos...
        pivot = obtener_pivot(lista, inicio, fin);
        q_sort(lista, inicio, pivot - 1); // sublista izquierda
        q_sort(lista, pivot + 1, fin);  //sublista derecha
}
void ordena_pacientes(TLista *lista)
{
        q_sort(lista, 0, lista->tam - 1);
}
int cantidad_pacientes(TLista lista)
{
        return lista.tam;
}
