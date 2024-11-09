#include <stdio.h>
typedef void (*MenuOption)(void*);
//utilidades
void console_read(char *buffer, int max_size);
void ingresar_texto(char *mensaje, char *cadena, int max_size);
void ingresar_entero(char *mensaje, int *salida);
void ingresar_long(char *mensaje, long *salida);
void ingresar_double(char *mensaje, double *salida);
void ingresar_char(char *mensaje, char *salida);
void limpiar_entrada();
//void menu(int *salir, MenuOption *opciones, void *param, int cant_funciones, char *mensaje);