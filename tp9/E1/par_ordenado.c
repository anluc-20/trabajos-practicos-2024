#include "par_ordenado.h"
#include <stdio.h>
#include <stdlib.h>

struct ParOrdenado{
        int x, y;
};

ParOrdenado* crear_par_ordenado()
{
        ParOrdenado *par = NULL;
        par = malloc(sizeof(ParOrdenado));
        printf("x: ");
        scanf("%d", &par->x);
        printf("y: ");
        scanf("%d", &par->y);
        return par;
}


void mostrar_par_ordenado(ParOrdenado *par)
{
        printf("(%d,%d)\n", par->x, par->y);
}
int operar_par_ordenado(ParOrdenado *par)
{
        return 2 * par->x - 10 * par->y;
}

void eliminar_par_ordenado(ParOrdenado *par)
{
        free(par);
        par = NULL;
}
