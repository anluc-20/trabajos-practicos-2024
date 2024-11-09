#include <stdio.h>
#define T_MAX 30

typedef char String[T_MAX];

/*
Ejercicio 3: Se necesitan cargar los datos de un alumno, con el siguiente orden: DNI, Apellido, Nombre
y Fecha de Nacimiento (aaaammdd). Posteriormente mostrar los datos del alumno ingresado.
Nota: ¿Qué problemas encuentra cuando se ejecuta el programa? Que acciones debemos realizar en
caso de evidenciar problemas para resolver la situación. 

*/

void ingresar_texto(char *mensaje, char *cadena, int max_size);
void ingresar_fecha(char *fecha, char *year, char *month, char *day);
void console_read(char *buffer, int max_size);


int main()
{
        String dni, apellido, nombre, fecha, year, month, day, string;

        ingresar_texto("ingrese el dni: ", dni, 10);
        ingresar_texto("ingrese el apellido: ", apellido, T_MAX);
        ingresar_texto("ingrese el nombre: ", nombre, T_MAX);
        ingresar_fecha(fecha, year, month, day);
        printf("alumno\n");
        printf("DNI: %s\n", dni);
        printf("Apellido: %s\n", apellido);
        printf("Nombre: %s\n", nombre);
        printf("Fecha de Nacimiento: %s/%s/%s\n", year, month, day);

        return 0;
}

void ingresar_fecha(char *fecha, char *year, char *month, char *day)
{
        int i = 0, j = 0;
        printf("ingresar Fecha: ");
        console_read(fecha, 9);

        for (j = 0; j < 4; j++) {
                year[j] = fecha[i];
                i++; 
        }
        year[j] = '\0';

        for (j = 0; j < 2; j++) {
                month[j] = fecha[i];
                i++; 
        }
        month[j] = '\0';

        for (j = 0; j < 2; j++) {
                day[j] = fecha[i];
                i++; 
        }
        day[j] = '\0';
}
void ingresar_texto(char *mensaje, char *cadena, int max_size)
{
        printf("%s", mensaje);
        console_read(cadena, max_size);
}

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