#include <stdio.h>
#include <string.h>

#define CAD_MAX_SIZE 30
typedef char Cadena[CAD_MAX_SIZE];

void cargar_cadena(Cadena cadena);
void copiar_cadena(Cadena destino, Cadena fuente);
int comparar_cadena(Cadena a, Cadena b);
