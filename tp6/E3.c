#include <stdio.h>

#define STR_MAX_SIZE 30
#define CLIENTES_ARR_MAX_SIZE 20
#define OPCIONES "a) Permitir actualizar el domicilio de un cliente, dado su número de cuenta\nb) Realizar un depósito\nc) Realizar un retiro\nd) Realizar una transferencia entre cuentas\ne) Salir.\nopcion: "

typedef char String[STR_MAX_SIZE];

typedef struct {
        int numero;
        String calle;
} Domicilio;
typedef struct {
        int numero_de_cuenta;
        String apellido;
        String nombre;
        Domicilio domicilio;
        int saldo;
} Cliente;

/*
Ejercicio 2: Un banco mantiene la información de sus clientes en un array de registros (Lista de clientes).
De cada Cliente se almacena la siguiente información: “Número de cuenta, Apellido y Nombre del cliente,
Domicilio del cliente, Saldo de la cuenta. “
Se solicita escribir un programa que permita realizar la carga de las cuentas de N Clientes de un banco y
luego mediante un menú realizar las siguientes operaciones:
a) Permitir actualizar el domicilio de un cliente, dado su número de cuenta
b) Realizar un depósito (es decir, dado un monto a depositar y una cuenta, actualizar el saldo).
c) Realizar un retiro (es decir, dado un monto a retirar y una cuenta, actualizar el saldo si es que el saldo
es mayor o igual al importe a retirar).
d) Realizar una transferencia entre cuentas (es decir, dado un monto a transferir, una cuenta origen y
una cuenta destino, actualizar el saldo destino si es que el saldo origen es mayor o igual al importe a
transferir). 

Ejercicio 3: Realice los cambios apropiados en el Ejercicio 2, para impedir la carga de un número de
cuenta ya existente en la lista y que la lista de clientes se ordene por el número de cuenta a medida que
se ingresan los clientes. 
*/

void menu(int *salir, Cliente **clientes_p, int *size);

//opciones del menu
void ingresar_numero_cuenta_actualizar_domicilio_cliente(Cliente **clientes_p, int size);
void ingresar_monto_cuenta_depositar(Cliente **clientes_p, int size);
void ingresar_monto_cuenta_retirar(Cliente **clientes_p, int size);
void ingresar_cuenta_origen_cuenta_destino_monto_transferir(Cliente **clientes_p, int size);


//funciones y procedimientos
void ingresar_cliente(Cliente *cliente, int numero_de_cuenta);
int seleccionar_cuenta(Cliente **clientes_p, int size);
int buscar_cliente_por_nro_cuenta(Cliente **clientes_p, int size, int numero_de_cuenta);
void ingresar_domicilio(Domicilio *domicilio);
void ordenar_por_numero_cuenta(Cliente **clientes_p, int size);
int busqueda_binaria_por_numero_cuenta(Cliente **clientes_p, int size, int numero_de_cuenta);
int ingresar_numero_de_cuenta(Cliente **clientes_p, int size);




//utilidades
void console_read(char *buffer, int max_size);
void ingresar_texto(char *mensaje, char *cadena, int max_size);
void ingresar_entero(char *mensaje, int *salida);
void ingresar_char(char *mensaje, char *salida);
void limpiar_entrada();
void enlazar_array_y_array_p(Cliente *array, Cliente **array_p, int size);
void ingresar_clientes(Cliente **clientes_p, int *size);


int main()
{
        int salida = 0, n;
        Cliente clientes[CLIENTES_ARR_MAX_SIZE];
        Cliente *clientes_p[CLIENTES_ARR_MAX_SIZE];
        enlazar_array_y_array_p(clientes, clientes_p, CLIENTES_ARR_MAX_SIZE);
 
        ingresar_clientes(clientes_p, &n);

        while (!salida) 
                menu(&salida, clientes_p, &n);

        return 0;
}

void menu(int *salir, Cliente **clientes_p, int *size)
{
        char opcion;
        ingresar_char(OPCIONES, &opcion);
        while((opcion < 'a') || (opcion > 'e'))
                ingresar_char("opcion invalida, por favor ingrese una opcion valida: ", &opcion);

        switch (opcion) {
                case 'a':
                        ingresar_numero_cuenta_actualizar_domicilio_cliente(clientes_p, *size);
                        
                        break;
                        
                case 'b':
                        ingresar_monto_cuenta_depositar(clientes_p, *size);
                        
                        break;

                case 'c':
                        ingresar_monto_cuenta_retirar(clientes_p, *size);

                        break;

                case 'd':
                        ingresar_cuenta_origen_cuenta_destino_monto_transferir(clientes_p, *size);

                        break;
        
                case 'e':
                        printf("saliendo...\n");
                        *salir = 1;
                        break;
        }
}

//opciones del menu
void ingresar_numero_cuenta_actualizar_domicilio_cliente(Cliente **clientes_p, int size)
{
        int numero_cuenta, indice;

        ingresar_entero("ingrese el numero de cuenta: ", &numero_cuenta);
        indice = buscar_cliente_por_nro_cuenta(clientes_p, size, numero_cuenta);
        if(indice != -1) {
                printf("ingrese el nuevo domicilio: \n");
                ingresar_domicilio(&clientes_p[indice]->domicilio);
                printf("se ha actualizado correctamente el domicilio del cliente  %s\n", clientes_p[indice]->nombre);
        } else {
                printf("no se encontro una cuenta con ese numero.\n");
        }
}
void ingresar_monto_cuenta_depositar(Cliente **clientes_p, int size)
{
        int indice, monto;
        printf("seleccione la cuenta para depositar: \n");
        indice = seleccionar_cuenta(clientes_p, size);

        printf("el saldo de la cuenta es: %d\n", clientes_p[indice]->saldo);

        ingresar_entero("ingrese el monto que quiere depositar: ", &monto);
        while(monto < 0)
                ingresar_entero("el monto no puede ser negativo: ", &monto);

        clientes_p[indice]->saldo += monto;
        printf("el nuevo saldo de la cuenta es: %d\n", clientes_p[indice]->saldo);
}
void ingresar_monto_cuenta_retirar(Cliente **clientes_p, int size)
{
        int indice, monto;
        printf("seleccione la cuenta para retirar: \n");
        indice = seleccionar_cuenta(clientes_p, size);

        printf("el saldo de la cuenta es: %d\n", clientes_p[indice]->saldo);

        ingresar_entero("ingrese el monto que quiere retirar: ", &monto);
        while((monto < 0) || (monto > clientes_p[indice]->saldo))
                ingresar_entero("el monto no puede ser negativo, o mayor que el saldo disponible: ", &monto);

        clientes_p[indice]->saldo -= monto;  
        printf("el saldo de la cuenta es: %d\n", clientes_p[indice]->saldo);
}
void ingresar_cuenta_origen_cuenta_destino_monto_transferir(Cliente **clientes_p, int size)
{
        int origen, destino, monto;
        printf("seleccione la cuenta de origen: \n");
        origen = seleccionar_cuenta(clientes_p, size);
        printf("seleccione la cuenta de destino: \n");
        destino = seleccionar_cuenta(clientes_p, size);

        printf("el saldo de la cuenta de origen es: %d\n", clientes_p[origen]->saldo);
        printf("el saldo de la cuenta de destino es: %d\n", clientes_p[destino]->saldo);

        ingresar_entero("ingrese el monto que quiere transferir: ", &monto);
        while((monto < 0) || (monto > clientes_p[origen]->saldo))
                ingresar_entero("el monto no puede ser negativo, o mayor que el saldo disponible: ", &monto);
        
        clientes_p[origen]->saldo -= monto;
        clientes_p[destino]->saldo += monto;

        printf("el saldo de la cuenta de origen es: %d\n", clientes_p[origen]->saldo);
        printf("el saldo de la cuenta de destino es: %d\n", clientes_p[destino]->saldo);
}

//funciones y procedimientos
void ingresar_cliente(Cliente *cliente, int numero_de_cuenta)
{
        cliente->numero_de_cuenta = numero_de_cuenta;
        ingresar_texto("nombre: ", cliente->nombre, STR_MAX_SIZE);
        ingresar_texto("apellido: ", cliente->apellido, STR_MAX_SIZE);
        ingresar_domicilio(&cliente->domicilio);
        ingresar_entero("saldo: ", &cliente->saldo);
}
void ingresar_domicilio(Domicilio *domicilio)
{
        ingresar_entero("numero de calle: ", &domicilio->numero);
        ingresar_texto("nombre calle: ", domicilio->calle, STR_MAX_SIZE);
}
int seleccionar_cuenta(Cliente **clientes_p, int size)
{
        int opcion;
        for (int i = 0; i < size; i++)
                printf("\nCuenta [%d]\nnumero de cuenta: %d\nnombre: %s\n", i, clientes_p[i]->numero_de_cuenta, clientes_p[i]->nombre);

        ingresar_entero("seleccion: ", &opcion);
        while((opcion > (size - 1)) || (opcion < 0))
                ingresar_entero("seleccion invalidad, por favor eliga una opcion valida: ", &opcion);    

        return opcion;
}
int buscar_cliente_por_nro_cuenta(Cliente **clientes_p, int size, int numero_de_cuenta)
{
        for (int i = 0; i < size; i++)
                if(clientes_p[i]->numero_de_cuenta == numero_de_cuenta)
                        return i;

        return -1;
}
void ordenar_por_numero_cuenta(Cliente **clientes_p, int size)
{
        Cliente *aux;
        int j;
        for (int i = 1; i < size; i++) {
                j = i - 1;
                while((j >= 0) && (clientes_p[j+1]->numero_de_cuenta < clientes_p[j]->numero_de_cuenta)) {
                        aux = clientes_p[j];
                        clientes_p[j] = clientes_p[j+1];
                        clientes_p[j+1] = aux;
                        j--;
                }
        }
}
int busqueda_binaria_por_numero_cuenta(Cliente **clientes_p, int size, int numero_de_cuenta)
{
        int inicio = 0, fin = size - 1, m = (inicio + fin) / 2;
        while((inicio < fin) && (clientes_p[m]->numero_de_cuenta != numero_de_cuenta))
        {
                if(clientes_p[m]->numero_de_cuenta > numero_de_cuenta)
                        fin = m - 1;
                else
                        inicio = m + 1;
                m = (inicio + fin) / 2;
        }
        if(clientes_p[m]->numero_de_cuenta == numero_de_cuenta)
                return  m;
        else
                return -1;
}
int ingresar_numero_de_cuenta(Cliente **clientes_p, int size)
{
        int numero_de_cuenta, indice;
        ingresar_entero("numero de cuenta: ", &numero_de_cuenta);
        indice = busqueda_binaria_por_numero_cuenta(clientes_p, size, numero_de_cuenta);
        while(indice != -1) {
                ingresar_entero("el numero de cuenta ya esta ocupado, eliga otro: ", &numero_de_cuenta);
                indice = busqueda_binaria_por_numero_cuenta(clientes_p, size, numero_de_cuenta);
        }
        return numero_de_cuenta;
}

//utilidades
void console_read(char *buffer, int max_size)
{
        char c;
        int i = 0;

        while((i < max_size - 1) && ((c = getchar()) != EOF) && (c != '\n')) {      
                buffer[i] = c;
                i++;
        }
        buffer[i] = '\0';

        if((c != '\n') && (c != EOF))
                while (((c = getchar()) != '\n') && (c != EOF));
}
void ingresar_texto(char *mensaje, char *cadena, int max_size)
{
        printf("%s", mensaje);
        console_read(cadena, max_size);
}
void ingresar_entero(char *mensaje, int *salida)
{
     printf("%s", mensaje);
     scanf("%d", salida);
     limpiar_entrada();
}
void ingresar_char(char *mensaje, char *salida)
{
        printf("%s", mensaje);
        scanf(" %c", salida);
        limpiar_entrada();
}
void limpiar_entrada()
{
        char c = getchar();
        if((c != '\n') && (c != EOF))
                while (((c = getchar()) != '\n') && (c != EOF)); 
}
void enlazar_array_y_array_p(Cliente *array, Cliente **array_p, int size)
{
        for (int i = 0; i < size; i++) {
                array_p[i] = &array[i];
        }
}
void ingresar_clientes(Cliente **clientes_p, int *size)
{
        int numero_de_cuenta;
        ingresar_entero("ingrese el numero de clientes: ", size);
        for (int i = 0; i < *size; i++) {
                printf("[%d/%d]\n", i, *size - 1);
                printf("ingrese los siguientes datos:\n");
                numero_de_cuenta = ingresar_numero_de_cuenta(clientes_p, *size);
                ingresar_cliente(clientes_p[i], numero_de_cuenta);
                ordenar_por_numero_cuenta(clientes_p, i + 1);
        }
}