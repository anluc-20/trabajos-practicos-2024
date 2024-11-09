#include <stdio.h>
#include <string.h>
#define TCAD_SIZE_MAX 30
#define CONTACTOS_MAX_SIZE 30
#define OPCIONES "a) Añadir un nuevo contacto, considerando que cada contacto es único. (Mantener ordenada la lista por apellido y nombres).\nb) Borrar un contacto. (Maºntener ordenada la lista por apellido y nombres).\nc) Dado el apellido y el nombre, modificar su dirección o su teléfono.\nd) Dado un apellido y el nombre, mostrar sus datos.\ne) Mostrar la agenda telefónica completa.\nf) Dado un apellido, mostrar todos los datos de las personas con ese apellido.\ng) Dado un mes, mostrar todas las personas que cumplen años en ese mes.\nh) Salir.\n"
typedef char TCad[TCAD_SIZE_MAX];

typedef struct {
	int dia;
	int mes;
	int anio;
} Fecha;
typedef struct {
	TCad apellido_nombres;
	TCad apellido;
	TCad direccion;
	int celular;
	Fecha fecha_de_nacimiento;
} Contacto;
/*
Ejercicio 5: Se necesita crear un programa que maneje una Agenda telefónica de amigos, que almacena
los siguientes datos de cada persona: Apellidos, Nombres, Dirección, Celular, Fecha de nacimiento\u201d.
Realizar un programa que permita cargar la lista de amigos y que la misma se ordene alfabéticamente
por Apellidos y Nombres a medida que cargan los registros. Utilizando un menú permita realizar las
siguientes operaciones:
a) Añadir un nuevo contacto, considerando que cada contacto es único. (Mantener ordenada la lista por
apellido y nombres).
b) Borrar un contacto. (Maºntener ordenada la lista por apellido y nombres).
c) Dado el apellido y el nombre, modificar su dirección o su teléfono.
d) Dado un apellido y el nombre, mostrar sus datos.
e) Mostrar la agenda telefónica completa.
f) Dado un apellido, mostrar todos los datos de las personas con ese apellido.
g) Dado un mes, mostrar todas las personas que cumplen años en ese mes.
Universidad Nacional de Salta Facultad de Ciencias Exactas
Programación para LAS & TUP Año: 2024
Nota: Diseñar un módulo agrega un registro nuevo a la lista existente, que se pueda reutilizar en la
operación carga la lista y en la operación agrega nuevo registro.

*/

void menu(int *salir, Contacto **contactos, int *size);

//opciones del menu
void ingresar_datos_agregar_contacto(Contacto **contactos, int *size);
void seleccionar_contacto_borrarlo(Contacto **contactos, int *size);
void ingresar_nombre_apellido_modificar_direccion_o_telefono(Contacto **contactos, int size);
void ingresar_nombre_apellido_mostrar_datos(Contacto **contactos, int size);
void mostrar_agenda_completa(Contacto **contactos, int size);
void ingresar_apellido_mostrar_contactos(Contacto **contactos, int size);
void ingresar_mes_mostrar_cumpleanios(Contacto **contactos, int size);

//funciones y procedimientos
void ingresar_contacto(Contacto *contacto);
int intentar_ingresar_nombre_apellido(Contacto **contactos, int size, Contacto *contacto);
int buscar_contacto_por_apellido_nombres(Contacto **contactos, int size, TCad apellido_nombres);
void buscar_contactos_por_apellido(Contacto **contactos, int size, TCad apellido, Contacto **resultados, int *resultados_size);
void ingresar_fecha_de_nacimiento(Contacto *contacto);
void mostrar_contacto(Contacto *contacto);
void ingresar_nombre_apellido(TCad apellido, TCad apellido_nombres);
void ordenar_por_nombre_apellido(Contacto **contactos, int size);

//utilidades
void ingresar_entero(char *mensaje, int *salida);
void ingresar_char(char *mensaje, char *salida);
void ingresar_texto(char *mensaje, char *salida, int max_size);
void console_read(char *salida, int max_size);
void limpiar_entrada();

int main() {
	Contacto contactos[CONTACTOS_MAX_SIZE];
        Contacto *contactos_p[CONTACTOS_MAX_SIZE];
        int n = 0, salir = 0;

        for (int i = 0; i < CONTACTOS_MAX_SIZE; i++)
                contactos_p[i] = &contactos[i];

	while(!salir)
                menu(&salir, contactos_p, &n);

	return 0;
}

void menu(int *salir, Contacto **contactos, int *size)
{
	char opcion;
	printf(OPCIONES);
	ingresar_char("ingrese una opcion: ", &opcion);
	while((opcion < 'a') || (opcion > 'h'))
		ingresar_char("opcion invalida, ingrese una valida: ", &opcion);
	
	switch(opcion) {
		case 'a':
			ingresar_datos_agregar_contacto(contactos, size);
			break;
		case 'b':
                        seleccionar_contacto_borrarlo(contactos, size);
			break;
			
		case 'c':
                        ingresar_nombre_apellido_modificar_direccion_o_telefono(contactos, *size);
			break;
			
		case 'd':
                        ingresar_nombre_apellido_mostrar_datos(contactos, *size);
			break;
			
		case 'e':
                        mostrar_agenda_completa(contactos, *size);
			break;
			
		case 'f':
                        ingresar_apellido_mostrar_contactos(contactos, *size);
			break;
			
		case 'g':
                        ingresar_mes_mostrar_cumpleanios(contactos, *size);
			break;
		case 'h':
			printf("saliendo...");
			*salir = 1;
			break;
	}
}
	
//opciones del menu

void ingresar_datos_agregar_contacto(Contacto **contactos, int *size)
{
        int ok;
        ok = intentar_ingresar_nombre_apellido(contactos, *size, contactos[*size]);

        if(ok) {
                ingresar_contacto(contactos[*size]);
                printf("se ha agregado correctamente al contacto\n");
                *size += 1;
                ordenar_por_nombre_apellido(contactos, *size);
        } else {
                printf("un contacto con ese nombre ya existe \n");
        }
}
void seleccionar_contacto_borrarlo(Contacto **contactos, int *size)
{
        int opcion;
        printf("Seleccione uno de sus contactos: \n");
        mostrar_agenda_completa(contactos, *size);
        ingresar_entero("opcion: ", &opcion);
        while ((opcion < 0) || (opcion > *size - 1))
                ingresar_entero("opcion invalida, por favor seleccione una valida: ", &opcion);
        
        printf("se ha borrado al contacto %s\n", contactos[opcion]->apellido_nombres);
        for (int i = opcion; i < *size - 1; i++)
                contactos[i] = contactos[i+1];

        *size -= 1;
}
void ingresar_nombre_apellido_modificar_direccion_o_telefono(Contacto **contactos, int size)
{
        TCad apellido, apellido_nombres;
        int indice, opcion;
        ingresar_nombre_apellido(apellido, apellido_nombres);
        indice = buscar_contacto_por_apellido_nombres(contactos, size, apellido_nombres);
        if(indice == -1) {
                printf("no se encontro un contacto con ese apellido o nombre\n");
        } else {
                ingresar_entero("seleccione una opcion:\n1) Cambiar direccion.\n2) Cambiar telefono.\nopcion: ", &opcion);
                while ((opcion > 2) || (opcion < 1))
                        ingresar_entero("opcion invalida, eliga una opcion valida: ", &opcion);
                
                switch (opcion) {
                        case 1: 
                                ingresar_texto("ingrese la nueva direccion: ", contactos[indice]->direccion, TCAD_SIZE_MAX);
                                printf("se ha cambiado correctamente la direccion\n");
                                break;
                        case 2: 
                                ingresar_entero("ingrese el nuevo telefono: ", &contactos[indice]->celular);
                                printf("se ha cambiado correctamente el telefono\n");
                                break;
                }
        }
}
void ingresar_nombre_apellido_mostrar_datos(Contacto **contactos, int size)
{
        int indice;
        TCad apellido, apellido_nombres;
        ingresar_nombre_apellido(apellido, apellido_nombres);
        indice = buscar_contacto_por_apellido_nombres(contactos, size, apellido_nombres);
        if(indice == -1)
                printf("no se encontro un contacto con ese nombre\n");
        else
                mostrar_contacto(contactos[indice]);
}
void mostrar_agenda_completa(Contacto **contactos, int size)
{
        for (int i = 0; i < size; i++) {
                printf("Contacto [%d]:\n", i);
                mostrar_contacto(contactos[i]);
        }
        printf("size: %d\n", size);
}
void ingresar_apellido_mostrar_contactos(Contacto **contactos, int size)
{
        TCad apellido;
        Contacto *resultados[CONTACTOS_MAX_SIZE];
        int resultados_size;
        ingresar_texto("apellido: ", apellido, TCAD_SIZE_MAX);
        buscar_contactos_por_apellido(contactos, size, apellido, resultados, &resultados_size);
        
        if(resultados_size > 0)
                mostrar_agenda_completa(resultados, resultados_size);
        else
                printf("no se encontraron contactos con ese apellido\n");

}
void ingresar_mes_mostrar_cumpleanios(Contacto **contactos, int size)
{
        Contacto *resultados[CONTACTOS_MAX_SIZE];
        int resultados_size = 0, mes;

        ingresar_entero("mes: ", &mes);
        for (int i = 0; i < size; i++) {
                if(contactos[i]->fecha_de_nacimiento.mes == mes) {
                        resultados[resultados_size] = contactos[i];
                        resultados_size++;
                }
        }
        if(resultados_size > 0)
                mostrar_agenda_completa(resultados, resultados_size);
        else
                printf("no se encontraron contactos con ese apellido\n");
}

//funciones y procedimientos
void ingresar_contacto(Contacto *contacto)
{
	ingresar_entero("telefono: ", &contacto->celular);
        ingresar_texto("direccion: ", contacto->direccion, TCAD_SIZE_MAX);
        ingresar_fecha_de_nacimiento(contacto);
}

int intentar_ingresar_nombre_apellido(Contacto **contactos, int size, Contacto *contacto)
{
        int indice, resultado;
        ingresar_nombre_apellido(contacto->apellido, contacto->apellido_nombres);

        indice = buscar_contacto_por_apellido_nombres(contactos, size, contacto->apellido_nombres);
        if(indice == -1)
                resultado = 1;
        else
                resultado = 0;


        return resultado;
}

int buscar_contacto_por_apellido_nombres(Contacto **contactos, int size, TCad apellido_nombres)
{
	int indice = -1;
	for (int i = 0; i < size; i++) {
		if(strcmp(contactos[i]->apellido_nombres, apellido_nombres) == 0)
			indice = i;
	}
	return indice;
}
void buscar_contactos_por_apellido(Contacto **contactos, int size, TCad apellido, Contacto **resultados, int *resultados_size)
{
        *resultados_size = 0;
	for (int i = 0; i < size; i++) {
		if(strcmp(contactos[i]->apellido, apellido) == 0) {
                        resultados[*resultados_size] = contactos[i];
                        *resultados_size += 1;
                }		
	}
}
void ingresar_fecha_de_nacimiento(Contacto *contacto)
{
        int anio, mes, dia, bisiesto, dia_invalido = 0;
        printf("ingrese la fecha de nacimiento\n");
        ingresar_entero("anio: ", &anio);
        if(anio%4 == 0) {
                if(anio%100 == 0) {
                        if(anio%400 == 0)
                                bisiesto = 1;
                        else
                                bisiesto = 0;
                } else {
                        bisiesto = 1;
                }
        } else {
                bisiesto = 0;
        }

        ingresar_entero("mes: ", &mes);
        while ((mes > 12) || (mes < 1))
                ingresar_entero("mes invalido, por favor ingresar uno valido: ", &mes);
        
        
        do {
                if(dia_invalido)
                        ingresar_entero("dia invalido, porfavor ingresar uno valido: ", &dia);
                else
                        ingresar_entero("dia: ", &dia);

                dia_invalido = 0;

                if((bisiesto && (mes == 2) && (dia > 29)) || (!bisiesto && (mes == 2) && (dia > 28)))
                        dia_invalido = 1;

                if(((mes == 3) || (mes == 5) || (mes == 6) || (mes == 9) || (mes == 11)) && (dia > 30))
                        dia_invalido = 1;

                if((dia > 31) || (dia < 1))
                        dia_invalido = 1;

        }while (dia_invalido);

        contacto->fecha_de_nacimiento.anio = anio;
        contacto->fecha_de_nacimiento.mes = mes;
        contacto->fecha_de_nacimiento.dia = dia;
}
void mostrar_contacto(Contacto *contacto)
{
        printf("apellido y nombres: %s\n", contacto->apellido_nombres);
        printf("telefono: %d\n", contacto->celular);
        printf("direccion: %s\n", contacto->direccion);
        printf("fecha de nacimiento: %d/%d/%d\n", contacto->fecha_de_nacimiento.anio, contacto->fecha_de_nacimiento.mes, contacto->fecha_de_nacimiento.dia);
}
void ingresar_nombre_apellido(TCad apellido, TCad apellido_nombres)
{
        TCad nombres;
        ingresar_texto("apellido: ", apellido, TCAD_SIZE_MAX);
        ingresar_texto("nombres: ", nombres, TCAD_SIZE_MAX);
        strcpy(apellido_nombres, apellido);

        strcat(apellido_nombres, " ");
        strcat(apellido_nombres, nombres);
}
void ordenar_por_nombre_apellido(Contacto **contactos, int size)
{
        int j;
        Contacto *aux;
        for (int i = 1; i < size; i++) {
                j = i - 1;
                while ((j >= 0) && (strcmp(contactos[j+1]->apellido_nombres, contactos[j]->apellido_nombres) < 0)) {
                        aux = contactos[j+1];
                        contactos[j+1] = contactos[j];
                        contactos[j] = aux;
                        j--;
                }
        }
}

//utilidades
void ingresar_entero(char *mensaje, int *salida)
{
	printf("%s", mensaje);
	scanf("%d", salida);
	limpiar_entrada();
}
void ingresar_char(char *mensaje, char *salida)
{
	printf("%s", mensaje);
	scanf("%c", salida);
	limpiar_entrada();
}
void ingresar_texto(char *mensaje, char *salida, int max_size)
{
	printf("%s", mensaje);
	console_read(salida, max_size);
}
void console_read(char *salida, int max_size)
{
	char c;
	int i = 0;
	while((i < max_size-1) && ((c = getchar()) != '\n') && (c != EOF))
	{
		salida[i] = c;
		i++;
	}
	salida[i] = '\0';
	
	if((c != '\n') && (c != EOF))
		while(((c = getchar()) != '\n') && (c != EOF));
}
void limpiar_entrada()
{
	char c = getchar();
	if((c != '\n') && (c != EOF))
		while(((c = getchar()) != '\n') && (c != EOF));
}