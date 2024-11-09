#include <stdio.h>
typedef struct {
        float a;
        float b;
} Complejo;

Complejo sumar_complejos(Complejo A, Complejo B);
Complejo restar_complejos(Complejo A, Complejo B);
Complejo multiplicar_complejos(Complejo A, Complejo B);
Complejo dividir_complejos(Complejo A, Complejo B);
void mostrar_complejo(Complejo complejo);
void ingresar_complejo(char *mensaje, Complejo *complejo);