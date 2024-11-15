/*.
 * Ejercicio 11: Diseñe un programa recursivo que permita, mediante un menú, administrar una lista de clientes. Los datos a registrar por cada cliente serán: Apellido y Nombre, DNI, saldo de cuenta. El programa debe además generar una lista de Deudores con los Clientes que posean un saldo de cuenta negativo y mostrar ordenado (Merge-Sort) la lista de Deudores, de acuerdo al saldo. Nota: Ejercicio subido en el sitio para completar los módulos recursivos 
 * */
#include "TAD_ListaCliente.h"
#include <stdio.h>

void menu_r(TLista *clientes);

int main()
{
        int n;
        TLista clientes = inicializa();
        clientes = cargar_clientes();
        ordena_clientes(&clientes);
        menu_r(&clientes);
        return 0;
}

void menu_r(TLista *clientes)
{
        int opcion;
        printf("Opciones:\n0. Salir\n1. Agregar cliente\n2. Eliminar cliente\n3. Modificar cliente\n4. Mostrar clientes\n5. Mostrar deudores\nEliga una opcion: ");
        scanf("%d", &opcion);
        getchar(); //limpio el salto de linea
        switch (opcion) {
                case 0:
                        printf("saliendo...");
                        break;
                case 1:
                        agrega_cliente(clientes);
                        ordena_clientes(clientes);
                        break;

                case 2:
                        elimina_cliente(clientes);
                        break;

                case 3:
                        modifica_cliente(clientes);
                        ordena_clientes(clientes);
                        break;

                case 4:
                        mostrar_clientes(*clientes);
                        break;

                case 5:
                        mostrar_clientes(genera_deudor(*clientes));
                        break;
                default:
                        printf("opcion invalida.\n");
        }
        if(opcion != 0)
                menu_r(clientes);
}
