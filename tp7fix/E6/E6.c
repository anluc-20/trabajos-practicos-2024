#include "../utils/utils.h"
#include "espectaculo.h"
#include <stdio.h>
#define OPCIONES "a) Cargar los datos de un espectáculo.\nb) Mostrar los datos de un espectáculo.\nc) Retornar el nro. de sala de un espectáculo.\nd) Modificar la fecha de inicio o fin de un espectáculo.\ne) Modificar la hora de inicio o fin de un espectáculo.\nf) Salir\nOpcion: "
/*
Ejercicio 6: Una empresa multi-sala de espectáculos nos contrata para que le construyamos un software 
que permita administrar los espectáculos que ofrece.   
Para ello en la 1era reunión que mantenemos con el encargado de espectáculos nos comenta los datos 
que necesita registrar de cada uno de ellos, los cuales son: “Código del  espectáculo;  Nombre  del 
espectáculo; Fecha de inicio; Fecha de fin; Horario inicio; Horario Fin; Nro. de Sala” También nos explica 
las acciones a realizar con cada uno de los espectáculos:  
• Cargar los datos de un espectáculo.  
• Mostrar los datos de un espectáculo.  
• Retornar el nro. de sala de un espectáculo.  
• Modificar la fecha de inicio o fin de un espectáculo.  
• Modificar la hora de inicio o fin de un espectáculo.  
Nuestro  trabajo  consiste  en  crear  los  TADs  necesarios  que  permita  realizar  lo  propuesto  por  nuestro 
cliente.  Luego  un  programa  que  utilizando  los  TADs  creados  permita  administrar  una  lista  de  N 
espectáculos. 
*/

void menu(int *salir, ListaEspectaculo *espectaculos);

void menu_a(ListaEspectaculo *espectaculos);
void menu_b(ListaEspectaculo *espectaculos);
void menu_c(ListaEspectaculo *espectaculos);
void menu_d(ListaEspectaculo *espectaculos);
void menu_e(ListaEspectaculo *espectaculos);

int main()
{
        int n, i, salir;
        EspectaculoArray array;
        ListaEspectaculo espectaculos;
        inicializar_lista_espectaculo(&espectaculos, array);

        ingresar_entero("ingrese la cantidad de espectaculos: ", &n);
        i = 0;
        while (i < n) {
                if(intentar_agregar_espectaculo(&espectaculos))
                        i++;
                else
                        printf("ya existe un espectaculo con ese codigo\n");
        }
        salir = 0;
        while(!salir)
                menu(&salir, &espectaculos);
        return 0;
}

void menu(int *salir, ListaEspectaculo *espectaculos)
{
        char opcion;
        ingresar_char(OPCIONES, &opcion);
        while((opcion < 'a') && (opcion > 'f'))
                ingresar_char("opcion invalida, ingrese una valida: ", &opcion);

        switch (opcion) {
                case 'a':
                        menu_a(espectaculos);
                        break;
                case 'b':
                        menu_b(espectaculos);
                        break;
                case 'c':
                        menu_c(espectaculos);
                        break;
                case 'd':
                        menu_d(espectaculos);
                        break;
                case 'e':
                        menu_e(espectaculos);
                        break;
                case 'f':
                        *salir = 1;
                        break;
        }
}

void menu_a(ListaEspectaculo *espectaculos)
{
        if(!intentar_agregar_espectaculo(espectaculos))
                printf("esa sala ya esta ocupada\n");
}
void menu_b(ListaEspectaculo *espectaculos)
{
        int codigo, indice;

        ingresar_entero("ingrese el codigo del espectaculo: ", &codigo);
        indice = buscar_espectaculo_por_codigo(espectaculos, codigo);
        if(indice == -1) {
                printf("no se encontro ningun espectaculo con ese codigo\n");
        } else {
                mostrar_espectaculo(espectaculos->p[indice]);
        }
}
void menu_c(ListaEspectaculo *espectaculos)
{
        int codigo, indice;

        ingresar_entero("ingrese el codigo del espectaculo: ", &codigo);
        indice = buscar_espectaculo_por_codigo(espectaculos, codigo);
        if(indice == -1) {
                printf("no se encontro ningun espectaculo con ese codigo\n");
        } else {
                printf("el espectaculo ocupa la sala: %d\n", espectaculos->p[indice]->sala);
        }
}
void menu_d(ListaEspectaculo *espectaculos)
{
        int codigo, indice;

        ingresar_entero("ingrese el codigo del espectaculo: ", &codigo);
        indice = buscar_espectaculo_por_codigo(espectaculos, codigo);
        if(indice == -1) {
                printf("no se encontro ningun espectaculo con ese codigo\n");
        } else {
                printf("ingrese las nuevas fechas del espectaculo: \n");
                ingresar_fecha_espectaculo(espectaculos->p[indice]);
        }
}

void menu_e(ListaEspectaculo *espectaculos)
{
        int codigo, indice;

        ingresar_entero("ingrese el codigo del espectaculo: ", &codigo);
        indice = buscar_espectaculo_por_codigo(espectaculos, codigo);
        if(indice == -1) {
                printf("no se encontro ningun espectaculo con ese codigo\n");
        } else {
                printf("ingrese las nuevas horas del espectaculo: \n");
                ingresar_hora_espectaculo(espectaculos->p[indice]);
        }
}