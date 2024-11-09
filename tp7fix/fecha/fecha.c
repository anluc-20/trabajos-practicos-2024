#include "fecha.h"
#include "../utils/utils.h"
#include <stdio.h>

int es_bisiesto(int anio)
{
        int bisiesto;
        if(anio % 4 == 0) {
                if(anio % 100 == 0) {
                        if (anio % 400 == 0)
                                bisiesto = 1;
                        else
                                bisiesto = 0;
                        
                } else {
                        bisiesto = 1;
                }
        } else {
                bisiesto = 0;
        }
        return bisiesto;
}
Fecha ingresar_fecha(char *mensaje)
{
        Fecha fecha;
        int bisiesto, invalido;
        printf("%s", mensaje);
        ingresar_entero("anio: ", &fecha.anio);
        bisiesto = es_bisiesto(fecha.anio);

        ingresar_entero("mes: ", &fecha.mes);
        while((fecha.mes < 1) || (fecha.mes > 12))
                ingresar_entero("mes invalido, ingresar mes valido: ", &fecha.mes);

        ingresar_entero("dia: ", &fecha.dia);
        invalido = 0;
        do {
                if(invalido)
                      ingresar_entero("dia invalido, ingrese un dia valido: ", &fecha.dia);

                invalido = 0;
                if((fecha.dia > 31) || (fecha.dia < 1))
                        invalido = 1;

                if(((fecha.mes == 4) || (fecha.mes == 6) || (fecha.mes == 9) || (fecha.mes == 11)) && (fecha.dia > 30))
                        invalido = 1;

                if((bisiesto && fecha.mes == 2 && fecha.dia > 29) || (!bisiesto && fecha.mes == 2 && fecha.dia > 28))
                        invalido = 1;

        }while (invalido);
        sprintf(fecha.todo_junto, "%d/%.2d/%.2d", fecha.anio, fecha.mes, fecha.dia);
        return  fecha;
}
int contar_dias(Fecha fecha)
{
        int anios_bisiestos, anios_normales, dias, i;
        int dias_por_mes[] = {31, 28, 31, 30, 31, 30,31,31,30,31,30,31};

        dias = 0;
        if(es_bisiesto(fecha.anio))     
                dias_por_mes[1] = 29;

        for (i = 0; i < fecha.mes-1; i++) {
                dias += dias_por_mes[i];
        }

        dias += fecha.dia;

        anios_bisiestos = (fecha.anio/4) - (fecha.anio/100) + (fecha.anio/400);
        anios_normales = fecha.anio - anios_bisiestos;
        dias += (anios_bisiestos * 366) + (anios_normales * 365);
        
        return dias;
}
int dias_entre_fechas(Fecha fecha_mayor, Fecha fecha_menor)
{
        return contar_dias(fecha_mayor) - contar_dias(fecha_menor);
}

char* obtener_fecha_como_cadena(Fecha *fecha)
{
        return fecha->todo_junto;
}