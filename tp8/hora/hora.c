#include "hora.h"
#include <stdio.h>
#include "../utils/utils.h"
Hora ingresar_hora(char *mensaje)
{
        Hora hora;
        printf("%s", mensaje);
        ingresar_entero("hora: ", &hora.hora);
        while ((hora.hora < 0) || (hora.hora > 23))
                ingresar_entero("hora invalida, ingrese hora valida: ", &hora.hora);
        ingresar_entero("minutos: ", &hora.minuto);
        while ((hora.minuto < 0) || (hora.minuto > 59))
                ingresar_entero("minutos invalidos, ingrese minutos validos: ", &hora.minuto);
        sprintf(hora.todo_junto, "%.2d:%.2d", hora.hora, hora.minuto);
        return hora;
}
void mostrar_hora(Hora hora)
{
        printf("%d:%d\n", hora.hora, hora.minuto);
}
Hora restar_horas(Hora hora1, Hora hora2)
{
        Hora resto;
        if(hora1.minuto < hora2.minuto)
        {
                hora1.minuto += 60;
                hora1.hora--;
        }
        resto.hora = hora1.hora - hora2.hora;
        resto.minuto = hora1.minuto - hora2.minuto;
        
        return resto;
}