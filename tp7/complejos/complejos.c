#include "complejos.h"
#include <stdio.h>

Complejo sumar_complejos(Complejo A, Complejo B)
{
        Complejo resultado = {
                A.a + B.a,
                A.b + B.b
        };
        return resultado;
}
Complejo restar_complejos(Complejo A, Complejo B)
{
        Complejo resultado = {
                A.a - B.a,
                A.b - B.b
        };
        return resultado;
}
//(ac - bd) + (ad + bc).i
Complejo multiplicar_complejos(Complejo A, Complejo B)
{
        Complejo resultado = {
                (A.a * B.a) - (A.b * B.b),
                (A.a * B.b) + (A.b * B.a)
        };
        return resultado;
}
//División: [ (ac + bd)/(cc + dd) ] + [ (bc - ad)/ (cc + dd) ].i
Complejo dividir_complejos(Complejo A, Complejo B)
{
        Complejo resultado = {
                ((A.a * B.a) + (A.b * B.b)) / ((B.a * B.a)  + (B.b * B.b)),
                ((A.b * B.a) - (A.a * B.b)) / ((B.a * B.a)  + (B.b * B.b))
        };
        return resultado;
}
void mostrar_complejo(Complejo complejo)
{
        if(complejo.b < 0)
                printf("%f - %fi\n", complejo.a, -complejo.b);
        else
                printf("%f + %fi\n", complejo.a, complejo.b);
}
void ingresar_complejo(char *mensaje, Complejo *complejo)
{
        printf("%s", mensaje);
        printf("parte real: ");
        scanf("%f", &complejo->a);
        printf("parte imaginaria: ");
        scanf("%f", &complejo->b);
}