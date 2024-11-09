#include "cliente.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <string.h>
#define OPCIONES "a) Actualizar el saldo de un cliente dado su DNI por la acreditación de valores.\nb) Actualizar el saldo de un cliente dado su DNI por la Transferencia de valores.\nc) Generar  un  vector  Operaciones  realizadas,  dada  una  fecha  ingresada  por  teclado  y  mostrar  el nuevo vector ordenado por Apellido y Nombre.\nd) Generar un vector Deudores con los Clientes que posean un saldo de cuenta negativo y mostrar ordenado el vector Deudores de acuerdo al saldo.\ne) Salir.\nopcion: "
/*
Ejercicio 5:  Escribir un programa modular que utilizando el concepto de TAD permita administrar una 
lista de clientes de un banco. El dato a registrar por cada cliente será: Apellido y Nombre, DNI, Saldo de 
cuenta, Fecha de operación.   
El programa debe permitir ingresar la lista y posteriormente ordenarla por DNI del cliente. Luego a través 
de un menú realizar las siguientes operaciones:  
a) Actualizar el saldo de un cliente dado su DNI por la acreditación de valores.  
b) Actualizar el saldo de un cliente dado su DNI por la Transferencia de valores.  
c) Generar  un  vector  Operaciones  realizadas,  dada  una  fecha  ingresada  por  teclado  y  mostrar  el 
nuevo vector ordenado por Apellido y Nombre.  
d) Generar un vector Deudores con los Clientes que posean un saldo de cuenta negativo y mostrar 
ordenado el vector Deudores de acuerdo al saldo.  
*/
void menu(int *salir, ListaCliente *clientes);

void menu_a(ListaCliente *clientes);
void menu_b(ListaCliente *clientes);
void menu_c(ListaCliente *clientes);
void menu_d(ListaCliente *clientes);

int comparar_por_fecha(Cliente *cliente1, Cliente *cliente2);
int comparar_por_apellido_nombre(Cliente *cliente1, Cliente *cliente2);
int comparar_por_saldo_negativo(Cliente *cliente1, Cliente *cliente2);
int comparar_por_saldo(Cliente *cliente1, Cliente *cliente2);

int main()
{
        int n, i, salir;
        ClienteArray array;
        ListaCliente clientes;
        inicializar_lista_cliente(&clientes, array);

        ingresar_entero("ingrese la cantidad de clientes: ", &n);
        i = 0;
        while (i < n) {
                if(intentar_agregar_cliente(&clientes))
                        i++;
                else
                        printf("ya existe un cliente con ese dni.\n");
        }
        salir = 0;
        while(!salir)
                menu(&salir, &clientes);

        return 0;
}
void menu(int *salir, ListaCliente *clientes)
{
        char opcion;
        ingresar_char(OPCIONES, &opcion);
        while((opcion < 'a') && (opcion > 'e'))
                ingresar_char("opcion invalida, ingrese una opcion valida: ", &opcion);

        switch (opcion) {
                case 'a': 
                        menu_a(clientes);
                        break;
                case 'b': 
                        menu_b(clientes);
                        break;
                case 'c': 
                        menu_c(clientes);
                        break;
                case 'd': 
                        menu_d(clientes);
                        break;
                case 'e': 
                        printf("saliendo...\n");
                        *salir = 1;
                        break;
               }
}

void menu_a(ListaCliente *clientes)
{
        Cliente ingreso;
        int indice;
        ingresar_entero("ingrese el dni: ", &ingreso.dni);
        indice = buscar_cliente(clientes, ingreso, comparar_por_dni);
        if(indice == -1) {
                printf("no se encontro un cliente con ese dni.\n");
        } else {
                printf("saldo disponible: %lf\n", clientes->p[indice]->saldo);
                ingresar_double("ingrese la cantidad de dinero a acreditar: ", &ingreso.saldo);
                while(ingreso.saldo < 0)
                      ingresar_double("la cantidad a acreditar no puede ser menor que 0: ", &ingreso.saldo);
                
                printf("se ha acreditado correctamente el dinero.\n");
                clientes->p[indice]->saldo += ingreso.saldo;
                printf("saldo disponible: %lf\n", clientes->p[indice]->saldo);
        }
}
void menu_b(ListaCliente *clientes)
{
        Cliente ingreso;
        int indice;
        ingresar_entero("ingrese el dni: ", &ingreso.dni);
        indice = buscar_cliente(clientes, ingreso, comparar_por_dni);
        if(indice == -1) {
                printf("no se encontro un cliente con ese dni.\n");
        } else {
                printf("saldo disponible: %lf\n", clientes->p[indice]->saldo);
                ingresar_double("ingrese la cantidad de dinero a retirar: ", &ingreso.saldo);
                while(ingreso.saldo < 0)
                      ingresar_double("la cantidad a retirar no puede ser menor que 0: ", &ingreso.saldo);
                
                printf("se ha retirado correctamente el dinero.\n");
                clientes->p[indice]->saldo -= ingreso.saldo;
                printf("saldo disponible: %lf\n", clientes->p[indice]->saldo);
        }
}
void menu_c(ListaCliente *clientes)
{
        ListaCliente salida;
        Cliente ingresado;
        ingresado.ultima_operacion = ingresar_fecha("ingrese la fecha: \n");
        buscar_clientes(clientes, ingresado, comparar_por_fecha, &salida);
        if(salida.size == 0) {
                printf("no se encontraron operaciones con esa fecha.\n");
        } else {
                ordenar_lista_cliente(&salida, comparar_por_apellido_nombre);
                mostrar_lista_cliente(&salida);
        }
}
void menu_d(ListaCliente *clientes)
{
        ListaCliente salida;
        Cliente ingresado;
        ingresado.saldo = 0;
        buscar_clientes(clientes, ingresado, comparar_por_saldo_negativo, &salida);
        if(salida.size == 0) {
                printf("no se encontraron deudores.\n");
        } else {
                ordenar_lista_cliente(&salida, comparar_por_saldo);
                mostrar_lista_cliente(&salida);
        }
}

int comparar_por_fecha(Cliente *cliente1, Cliente *cliente2)
{
        return dias_entre_fechas(cliente1->ultima_operacion, cliente2->ultima_operacion);
}
int comparar_por_apellido_nombre(Cliente *cliente1, Cliente *cliente2)
{
        return strcmp(cliente1->apellido_nombre, cliente2->apellido_nombre);
}
int comparar_por_saldo_negativo(Cliente *cliente1, Cliente *cliente2)
{
        int salida = -1;
        if(cliente1->saldo < cliente2->saldo)
                salida = 0;
        return salida;
}
int comparar_por_saldo(Cliente *cliente1, Cliente *cliente2)
{
        return (cliente1->saldo > cliente2->saldo) - (cliente1->saldo < cliente2->saldo);
}