#include "fecha.h"
#include <stdio.h>

int main()
{
        Fecha fecha = {
                2000,
                2,
                13,
                20000213
        };
        //730529 dias en total
        printf("desde el anio 0 hasta %d/%d/%d han pasado %d dias.\n", fecha.anio,fecha.mes,fecha.dia, contar_dias(fecha));
}