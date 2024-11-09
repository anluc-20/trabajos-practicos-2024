#include "utils/utils.h"
#include "complejos/complejos.h"
#define OPCIONES "a) Sumar A + B y mostrar el resultado.\nb) Restar A - B y mostrar el resultado.\nc) Multiplicar A * B y mostrar el resultado.\nd) Dividir A / B y mostrar el resultado.\ne) Salir.\nopcion: "
/*
Ejercicio 1: Un docente de física necesita trabajar con el campo de los números complejos, para
representar ondas electromagnéticas y corrientes eléctricas, por lo que su uso en el campo de la
electrónica o las telecomunicaciones es fundamental. La representación de un complejo
matemáticamente es de la forma (a + b i) donde a y b son números reales y la i es el número imaginario.
Las operaciones básicas que debe realizar son:
 Suma: (a + b.i) + (c + d.i) = (a + c) + (b + d).i
 Resta: (a + b.i) (c + d.i) = (a - c) + (b - d).i
 Producto: (a + b.i) * (c + d.i) = (ac - bd) + (ad + bc).i
 División: (a + b.i) / (c + d.i) = [ (ac + bd)/(cc + dd) ] + [ (bc - ad)/ (cc + dd) ].i
Realizar la especificación e implementación de un TAD_Reg_Complejo, que represente la situación
planteada utilizando el tipo de dato registro.
Implementar un programa que utilice el TAD creado para que, se ingresen dos números complejos A y B
y que a través de un menú se realicen las siguientes operaciones:
a) Sumar A + B y mostrar el resultado.
b) Restar A - B y mostrar el resultado.
c) Multiplicar A * B y mostrar el resultado.
d) Dividir A / B y mostrar el resultado. 
*/
void menu(int *salir, Complejo A, Complejo B);


int main()
{
        int salir = 0;
        Complejo A, B;
        ingresar_complejo("ingrese A: \n", &A);
        ingresar_complejo("ingrese B: \n", &B);

        while(!salir)
                menu(&salir, A, B);
        return 0;
}

void menu(int *salir, Complejo A, Complejo B)
{
        char opcion;
        ingresar_char(OPCIONES,&opcion);
        while((opcion < 'a') || (opcion > 'e'))
                ingresar_char("opcion invalida, ingrese una opcion valida: ",&opcion);

        switch (opcion) {
                case 'a':
                        mostrar_complejo(sumar_complejos(A, B));
                        break;
                case 'b':
                        mostrar_complejo(restar_complejos(A, B));
                        break;
                case 'c':
                        mostrar_complejo(multiplicar_complejos(A, B));
                        break;
                case 'd':
                        mostrar_complejo(dividir_complejos(A, B));
                        break;
                case 'e':
                        printf("saliendo...\n");
                        *salir = 1;
                        break;
        }
}