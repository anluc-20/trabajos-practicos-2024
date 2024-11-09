#include <stdio.h>
#define STR_MAX_SIZE 30
#define VEHICULOS_ARR_MAX_SIZE 20
#define OPCIONES "a) Agregar un nuevo vehículo a la lista INGRESOS.\nb) Retirar un vehículo (Para esta acción se solicita el Nro. de Patente del vehículo, se buscará el vehículo en INGRESOS y se deben copiar los datos del vehículo a la lista EGRESOS, para cargar la información de salida. Posteriormente se debe eliminar el vehículo de la lista INGRESOS.\nc) Eliminar de la lista EGRESOS todos aquellos vehículos de un Tipo determinado por el usuario. \nd) Salir.\nopcion:"
#define TARIFA 50

typedef char String[STR_MAX_SIZE];
typedef enum {
        AUTO,
        CAMIONETA,
        MOTO
} TipoVehiculo;
typedef struct {
        int hora;
        int minutos;
} Tiempo;
typedef struct {
        int numero_patente;
        TipoVehiculo tipo;
        Tiempo tiempo_ingreso;
        Tiempo tiempo_egreso;
        Tiempo estancia;
        int importe;
} Vehiculo;

/*
Ejercicio 8:
Crear una estructura de datos de array de registros para almacenar los datos de los vehículos del
estacionamiento. Los datos a almacenar son: “Nro. de Patente, Tipo de Vehículo (auto, camioneta, moto),
Hora y Minutos de Ingreso, Hora y Minutos de Egreso, Importe Pagado”
Crear 2 listas de vehículos:
 La primer lista llamada INGRESOS, es para almacenar los vehículos que ingresan, en esta lista la
hora y minutos de egreso y el importe pagado no se debe cargar.
 La segunda lista llamada EGRESOS, es para almacenar los datos de los vehículos que se retiraron,
en donde se modificará la hora y minutos de egreso y el importe pagado.
Se pide realizar un programa que permita cargar la primer lista INGRESOS de N vehículos y luego a
través de un menú permita las siguientes operaciones:
a) Agregar un nuevo vehículo a la lista INGRESOS.
b) Retirar un vehículo (Para esta acción se solicita el Nro. de Patente del vehículo, se buscará el vehículo
en INGRESOS y se deben copiar los datos del vehículo a la lista EGRESOS, para cargar la
información de salida. Posteriormente se debe eliminar el vehículo de la lista INGRESOS.
c) Eliminar de la lista EGRESOS todos aquellos vehículos de un Tipo determinado por el usuario. 

funciones que hay que crear:
ingresar_vehiculo(*vehiculo) usos: 2
egresar_vehiculo(*ingresos, indice, *egresos, ) usos: 2
ordenar_vehiculos(*vehiculos) usos: 2
ingresar_hora(*tiempo) usos: 2
restar_horas(*tiempo1, *tiempo2)

el resto de funcionalidades tienen un solo uso, por lo que no vale la pena modularizarlas

*/

void menu(int *salir, Vehiculo **ingresos_p, Vehiculo **egresos_p, int *ingresos_size, int *egresos_size);

//opciones del menu
void ingresar_vehiculo_agregarlo(Vehiculo **ingresos_p, int *ingresos_size);
void ingresar_patente_eliminar_vehiculo(Vehiculo **ingresos_p, Vehiculo **egresos_p, int *ingresos_size, int *egresos_size);
void ingresar_tipo_eliminar_vehiculos(Vehiculo **egresos_p, int *egresos_size);

//funciones y procedimientos
void ingresar_vehiculo(Vehiculo *vehiculo);
void egresar_vehiculo(Vehiculo **ingresos_p, Vehiculo **egresos_p, int *ingresos_size, int *egresos_size, int indice);
void ordenar_vehiculos(Vehiculo **vehiculos_p, int size);
void ingresar_hora(Tiempo *tiempo);
Tiempo restar_horas(Tiempo ingreso, Tiempo egreso);
void mostrar_vehiculos(Vehiculo **vehiculos_p, int size);

//utilidades
void console_read(char *buffer, int max_size);
void ingresar_texto(char *mensaje, char *cadena, int max_size);
void ingresar_entero(char *mensaje, int *salida);
void ingresar_char(char *mensaje, char *salida);
void limpiar_entrada();

int main()
{
        int salida = 0, ingresos_size, egresos_size = 0;
        Vehiculo vehiculos[VEHICULOS_ARR_MAX_SIZE];
        Vehiculo *ingresos_p[VEHICULOS_ARR_MAX_SIZE];
        Vehiculo *egresos_p[VEHICULOS_ARR_MAX_SIZE];
        for (int i = 0; i < VEHICULOS_ARR_MAX_SIZE; i++) {
                ingresos_p[i] = &vehiculos[i];
                egresos_p[i] = &vehiculos[i];
        }
 
        ingresar_entero("ingrese el tamano de la lista: ", &ingresos_size);
        for (int i = 0; i < ingresos_size; i++) {
                printf("Vehiculo [%d/%d]:\n", i, ingresos_size - 1);
                ingresar_vehiculo(ingresos_p[i]);
        }
        ordenar_vehiculos(ingresos_p, ingresos_size);

        while (!salida) 
                menu(&salida, ingresos_p, egresos_p, &ingresos_size, &egresos_size);

        return 0;
}

void menu(int *salir, Vehiculo **ingresos_p, Vehiculo **egresos_p, int *ingresos_size, int *egresos_size)
{
        char opcion;
        ingresar_char(OPCIONES, &opcion);
        while((opcion < 'a') || (opcion > 'e'))
                ingresar_char("opcion invalida, por favor ingrese una opcion valida: ", &opcion);

        switch (opcion) {
                case 'a':
                        ingresar_vehiculo_agregarlo(ingresos_p, ingresos_size);

                        break;
                        
                case 'b':
                        ingresar_patente_eliminar_vehiculo(ingresos_p, egresos_p, ingresos_size, egresos_size);

                        break;

                case 'c':
                        ingresar_tipo_eliminar_vehiculos(egresos_p, egresos_size);
                        
                        break;
        
                case 'd':
                        printf("saliendo...\n");
                        *salir = 1;
                        break;
                case 'e':
                        mostrar_vehiculos(ingresos_p, *ingresos_size);
                        mostrar_vehiculos(egresos_p, *egresos_size);
                        break;
        }
}

//opciones del menu
void ingresar_vehiculo_agregarlo(Vehiculo **ingresos_p, int *ingresos_size)
{
        ingresar_vehiculo(ingresos_p[*ingresos_size]);
        *ingresos_size += 1;
        printf("se ha ingresado correctamente el vehiculo.\n");
        ordenar_vehiculos(ingresos_p, *ingresos_size);
}
void ingresar_patente_eliminar_vehiculo(Vehiculo **ingresos_p, Vehiculo **egresos_p, int *ingresos_size, int *egresos_size)
{
        int patente, indice;
        int inicio = 0, fin = *ingresos_size -1, m = (inicio + fin) / 2;

        ingresar_entero("ingrese la patente: ", &patente);
        
        while ((inicio < fin) && (ingresos_p[m]->numero_patente != patente)) {
                if(ingresos_p[m]->numero_patente > patente)
                        fin = m - 1;
                else
                        inicio = m + 1;

                m = (inicio + fin) / 2;
        }
        if(ingresos_p[m]->numero_patente == patente)
                indice = m;
        else
                indice = -1;

        if(indice == -1) {
                printf("no se encontro un vehiculo con esa patente.\n");
        } else {
                egresar_vehiculo(ingresos_p, egresos_p, ingresos_size, egresos_size, indice);
                printf("se ha egresado correctamente el vehiculo.\nTiempo de estacia: %d:%d\nImporte: $%d\n", egresos_p[*egresos_size-1]->estancia.hora, egresos_p[*egresos_size-1]->estancia.minutos, egresos_p[*egresos_size-1]->importe);
        }

}
void ingresar_tipo_eliminar_vehiculos(Vehiculo **egresos_p, int *egresos_size)
{
        TipoVehiculo tipo_vehiculo;
        int tipo;
        int i = 0, cant = 0;

        ingresar_entero("ingrese el tipo de vehiculo:\n[0]: AUTO\n[1]: CAMIONETA\n[3]: MOTO\nopcion: ", &tipo);
        while((tipo > 2) || (tipo < 0))
              ingresar_entero("opcion invalida, por favor ingresar una opcion valida: ", &tipo);

        tipo_vehiculo = tipo;
        while (i < *egresos_size) {
                if(egresos_p[i]->tipo == tipo_vehiculo)
                {
                        cant++;
                        *egresos_size -= 1;
                        for (int j = i; j < *egresos_size; j++)
                                egresos_p[j] = egresos_p[j+1];
                } else {
                        i++;
                }
        }
        printf("se han eliminado %d vehiculos.\n", cant);
        
}

//funciones y procedimientos
void ingresar_vehiculo(Vehiculo *vehiculo)
{
        int tipo;
        ingresar_entero("numero de patente: ", &vehiculo->numero_patente);
        ingresar_entero("ingrese el tipo de vehiculo:\n[0]: AUTO\n[1]: CAMIONETA\n[2]: MOTO\nopcion: ", &tipo);
        while((tipo > 2) || (tipo < 0))
              ingresar_entero("opcion invalida, por favor ingresar una opcion valida: ", &tipo);

        vehiculo->tipo = tipo;
        ingresar_hora(&vehiculo->tiempo_ingreso);
        vehiculo->tiempo_egreso.hora = 0;
        vehiculo->tiempo_egreso.minutos = 0;
        vehiculo->importe = 0;
}
void egresar_vehiculo(Vehiculo **ingresos_p, Vehiculo **egresos_p, int *ingresos_size, int *egresos_size, int indice)
{
        Vehiculo *egresado = egresos_p[*egresos_size];

        egresos_p[*egresos_size] = ingresos_p[indice];
        *egresos_size += 1;
        *ingresos_size -= 1;
        for (int i = indice; i < *ingresos_size; i++)
                ingresos_p[i] = ingresos_p[i + 1];

        ingresar_hora(&egresado->tiempo_egreso);
        egresado->estancia = restar_horas(egresado->tiempo_ingreso, egresado->tiempo_egreso);
        
        egresado->importe = egresado->estancia.minutos > 10 ? (egresado->estancia.hora + 1) * TARIFA : egresado->estancia.hora * TARIFA;

}
void ordenar_vehiculos(Vehiculo **vehiculos_p, int size)
{
        int j;
        Vehiculo *aux;
        for (int i = 1; i < size; i++) {
                j = i - 1;
                while ((j >= 0) && (vehiculos_p[j+1]->numero_patente < vehiculos_p[j]->numero_patente)) {
                        aux = vehiculos_p[j+1];
                        vehiculos_p[j+1] = vehiculos_p[j];
                        vehiculos_p[j] = aux;
                        j--;
                }
        }
}
void ingresar_hora(Tiempo *tiempo)
{
        printf("ingrese la hora:\n");

        ingresar_entero("hora: ", &tiempo->hora);

        while ((tiempo->hora > 23) || (tiempo->hora < 0))
                ingresar_entero("hora invalida, ingrese una hora valida: ", &tiempo->hora);
        
        ingresar_entero("minutos: ", &tiempo->minutos);

        while ((tiempo->minutos > 59) || (tiempo->minutos < 0))
                ingresar_entero("minutos invalidos, ingrese minutos validos: ", &tiempo->minutos);
}
Tiempo restar_horas(Tiempo ingreso, Tiempo egreso)
{
        Tiempo resultado;
        int total_ingreso, total_egreso;
        int aux_hora = 24, aux_minutos = 0;
        total_ingreso = (ingreso.hora * 100) + ingreso.minutos;
        total_egreso = (egreso.hora * 100) + egreso.minutos;

        if(total_ingreso > total_egreso) {
                if(ingreso.minutos > 0) {
                        aux_hora--;
                        aux_minutos = 60;
                }
                resultado.hora = (aux_hora - ingreso.hora) + egreso.hora;
                resultado.minutos = (aux_minutos - ingreso.minutos) + egreso.minutos;
        } else {
                if(ingreso.minutos > egreso.minutos) {
                        egreso.minutos += 60;
                        egreso.hora--;
                }
                resultado.hora = egreso.hora - ingreso.hora;
                resultado.minutos = egreso.minutos - ingreso.minutos;
        }
        return resultado;
}
void mostrar_vehiculos(Vehiculo **vehiculos_p, int size)
{
        for (int i = 0; i < size; i++) {
                printf("Vehiculo [%d/%d]:\n", i, size - 1);
                printf("patente: %d\n", vehiculos_p[i]->numero_patente);
                printf("ingreso: %d:%d\n", vehiculos_p[i]->tiempo_ingreso.hora, vehiculos_p[i]->tiempo_ingreso.minutos);
                printf("egreso: %d:%d\n", vehiculos_p[i]->tiempo_egreso.hora, vehiculos_p[i]->tiempo_egreso.minutos);
                printf("importe: %d\n", vehiculos_p[i]->importe);
        }
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