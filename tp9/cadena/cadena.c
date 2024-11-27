#include "cadena.h"
#include <string.h>

void cargar_cadena(Cadena cadena)
{
        int i, c;
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

int comparar_cadena(Cadena a, Cadena b)
{
        return strcmp(a, b);
}
