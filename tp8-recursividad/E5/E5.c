/*
Ejercicio 5: Mostrar los dígitos de un número natural X de derecha a izquierda. Realizar la traza para X= 
45673. Modificar el módulo para que muestre los dígitos de izquierda a derecha. (¿El módulo recursivo 
lleva return?)
*/

#include <stdio.h>
void mostrar_digitos(int numero);
void mostrar_digitos_inverso(int numero);

int main()
{
        int numero = 45673;
        mostrar_digitos(numero);
        printf("\n");
        mostrar_digitos_inverso(numero);
        return 0;
}

void mostrar_digitos(int numero)
{
        printf("%d\t", numero%10);
        if(numero > 10)
                mostrar_digitos(numero/10);
}

void mostrar_digitos_inverso(int numero)
{
        if(numero > 10) {
                mostrar_digitos_inverso(numero/10);
                printf("%d\t", numero%10);
        } 
        else {
                printf("%d\t", numero);
        }
}

/*
        foo(45673) -> "3"
                foo(4567) -> "7"
                        foo(456) -> "6"
                                foo(45) -> "5"
                                        foo(4) -> "4"
        foo2(45673)
        |        foo2(4567)
        |        |        foo2(456)
        |        |        |        foo2(45)
        |        |        |        |       foo2(4) -> "4"
        |        |        |        -        -> "5"
        |        |        -                -> "6"
        |        -                        -> "7"
        -                                -> "3"
*/