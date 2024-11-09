#include "../fecha/fecha.h"
#define CADENA_MAX_SIZE 30
#define CLIENTES_MAX_SIZE 30
/*
Ejercicio 5:  Escribir un programa modular que utilizando el concepto de TAD permita administrar una 
lista de clientes de un banco. El dato a registrar por cada cliente será: 
Apellido
Nombre, 
DNI, 
Saldo de cuenta,
 Fecha de operación.   
El programa debe permitir ingresar la lista y posteriormente ordenarla por DNI del cliente. Luego a través 
de un menú realizar las siguientes operaciones:  
a) Actualizar el saldo de un cliente dado su DNI por la acreditación de valores.  
b) Actualizar el saldo de un cliente dado su DNI por la Transferencia de valores.  
c) Generar  un  vector  Operaciones  realizadas,  dada  una  fecha  ingresada  por  teclado  y  mostrar  el 
nuevo vector ordenado por Apellido y Nombre.  
d) Generar un vector Deudores con los Clientes que posean un saldo de cuenta negativo y mostrar 
ordenado el vector Deudores de acuerdo al saldo.  
*/

typedef char Cadena[CADENA_MAX_SIZE];
typedef struct {
        Cadena apellido;
        Cadena nombre;
        int dni;
        double saldo;
        Fecha ultima_operacion;
        Cadena apellido_nombre;
} Cliente;

typedef struct {
        Cliente *p[CLIENTES_MAX_SIZE];
        int size;
} ListaCliente;

typedef int (*Comparador)(Cliente*, Cliente*);
typedef Cliente ClienteArray[CLIENTES_MAX_SIZE];

int comparar_por_dni(Cliente *cliente1, Cliente *cliente2);
Cliente ingresar_cliente(int dni);
void inicializar_lista_cliente(ListaCliente *clientes, ClienteArray array);
int intentar_agregar_cliente(ListaCliente *clientes);
void eliminar_cliente(ListaCliente *clientes, int indice);
void mostrar_cliente(const Cliente *cliente);
void mostrar_lista_cliente(const ListaCliente *clientes);
int buscar_cliente(const ListaCliente *clientes, Cliente filtro, Comparador comparar);
void buscar_clientes(const ListaCliente *clientes, Cliente filtro, Comparador comparar, ListaCliente *salida);
void ordenar_lista_cliente(ListaCliente *clientes, Comparador comparar);
