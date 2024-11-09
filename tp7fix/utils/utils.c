#include "utils.h"

//
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