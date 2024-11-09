#include "cadena.h"

void ingresar_cadena(Cadena mensaje, Cadena cadena)
{
        int i;
        char c;
        printf("%s", mensaje);
        while(((c = getchar()) != '\n') && (c != EOF) && (i < CAD_MAX_SIZE - 1))
                cadena[i++] = c;

        cadena[i] = '\0';

        if((c != '\n') && (c != EOF))
                while(((c = getchar()) != '\n') && (c != EOF));
}
void copiar_cadena(Cadena destino, Cadena fuente)
{
        strcpy(destino, fuente);
}