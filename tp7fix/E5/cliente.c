#include "cliente.h"
#include "../utils/utils.h"
#include <stdio.h>

int comparar_por_dni(Cliente *cliente1, Cliente *cliente2)
{
        return (cliente1->dni > cliente2->dni) - (cliente1->dni < cliente2->dni);
}

Cliente ingresar_cliente(int dni)
{
        Cliente cliente;
        ingresar_texto("nombre: ", cliente.nombre, CADENA_MAX_SIZE);
        ingresar_texto("apellido: ", cliente.apellido, CADENA_MAX_SIZE);
        ingresar_double("saldo: ", &cliente.saldo);
        cliente.ultima_operacion = ingresar_fecha("ingrese la ultima fecha de operacion: \n");
        cliente.dni = dni;
        sprintf(cliente.apellido_nombre, "%s%s", cliente.apellido, cliente.nombre);
        return cliente;
}
void inicializar_lista_cliente(ListaCliente *clientes, ClienteArray array)
{
        int i;
        for (i = 0; i < CLIENTES_MAX_SIZE; i++) {
                clientes->p[i] = &array[i];
        }
        clientes->size = 0;
}
int intentar_agregar_cliente(ListaCliente *clientes)
{
        Cliente ingreso;
        int resultado;
        ingresar_entero("ingrese el dni: ", &ingreso.dni);
        if(buscar_cliente(clientes, ingreso, comparar_por_dni) == -1)
        {
                *clientes->p[clientes->size] = ingresar_cliente(ingreso.dni);
                clientes->size++;
                ordenar_lista_cliente(clientes, comparar_por_dni);
                resultado = 1;
        } else {
                resultado = 0;
        }
        return resultado;
}
void eliminar_cliente(ListaCliente *clientes, int indice)
{
        int i;
        clientes->size--;
        for (i = indice; i < clientes->size; i++) {
                clientes->p[i] = clientes->p[i + 1];
        }
}
void mostrar_cliente(const Cliente *cliente)
{
        printf("%s\t", cliente->nombre);
        printf("%s\t", cliente->apellido);
        printf("%d\t", cliente->dni);
        printf("%lf\t", cliente->saldo);
        printf("%s\n", cliente->ultima_operacion.todo_junto);
}
void mostrar_lista_cliente(const ListaCliente *clientes)
{
        int i;
        printf("nombre\tapellido\tdni\tsaldo\tultima fecha de operacion\n");
        for (i = 0; i < clientes->size; i++) {
                mostrar_cliente(clientes->p[i]);
        }
}
int buscar_cliente(const ListaCliente *clientes, Cliente filtro, Comparador comparar)
{
        int inicio, fin, m;
        inicio = 0;
        fin = clientes->size - 1;
        m = (inicio + fin) / 2;
        while((inicio < fin) && (comparar(clientes->p[m], &filtro) != 0))
        {
                if(comparar(clientes->p[m], &filtro) > 0)
                        fin = m - 1;
                else
                        inicio = m + 1;
                m = (inicio + fin) / 2;
        }
        if(comparar(clientes->p[m], &filtro) != 0)
                m = -1;
        return m;
}
void buscar_clientes(const ListaCliente *clientes, Cliente filtro, Comparador comparar, ListaCliente *salida)
{
        int i;
        salida->size = 0;
        for (i = 0; i < clientes->size; i++) {
                if(comparar(clientes->p[i], &filtro) == 0) {
                        salida->p[salida->size] = clientes->p[i];
                        salida->size++;
                }
        }
}
void ordenar_lista_cliente(ListaCliente *clientes, Comparador comparar)
{
        int i, j;
        Cliente *aux;
        for (i = 1; i < clientes->size; i++) {
                j = i - 1;
                while((j >= 0) && (comparar(clientes->p[j+1], clientes->p[j]) < 0))
                {
                        aux = clientes->p[j+1];
                        clientes->p[j+1] = clientes->p[j];
                        clientes->p[j] = aux;
                        j--;
                }
        }
}
