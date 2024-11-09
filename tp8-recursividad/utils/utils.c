#include "utils.h"

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
void ingresar_long(char *mensaje, long *salida)
{
        printf("%s", mensaje);
        scanf("%ld", salida);
        limpiar_entrada();
}
void ingresar_double(char *mensaje, double *salida)
{
        printf("%s", mensaje);
        scanf("%lf", salida);
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
/*void menu(int *salir, MenuOption *opciones, void *param, int cant_funciones, char *mensaje)
{
        char opcion, opcion_max = cant_funciones + 97; //a es 97 en codigo ascii, al sumar 97 y el indice del ultimo elemento del array, obtenemos la letra correspondiente a ese indice. Por ejemplo si el indice es 4, obtendremos 'e'. Ademas, guardamos un espacio para la opcion salir
        int indice;
        ingresar_char(mensaje, &opcion);
        while ((opcion < 'a') || (opcion > opcion_max)) {
             ingresar_char("opcion invalida, por favor ingresar una opcion valida: ", &opcion);
        }
        indice = opcion - 97; //restamos 97 para ajustar la opcion a un indice valido del array. Por ejemplo si tenemos 'e' la resta sera 4, por lo que accederemos al cuarto elemento del array.
        if(indice == cant_funciones)
                *salir = 1;
        else
                opciones[indice](param);
}*/