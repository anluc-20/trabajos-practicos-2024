/*
Ejercicio 2: Para las siguientes situaciones, realice un módulo recursivo y la traza con los datos indicados 
para cada una: 
a) Dado un dígito D, determinar si pertenece a un número entero positivo N. Realizar la traza para 
D=1 y X= 45673. 
b) Dado un número natural, indicar si el mismo es perfecto, abundante o deficiente. 
Nota: Un número natural X se dice que es deficiente si la suma de sus divisores (sin contarse a sí mismo) 
es menor a X. Si la suma de sus divisores es mayor a X se dice que el número es abundante y si es igual 
a X se dice que es perfecto.
*/
#include <stdio.h>

int pertenece(int buscado, int numero);

int main()
{
        int buscado, numero;
        buscado = 0;
        numero = 45673;
        if(pertenece(buscado, numero))
                printf("el numero %d esta en %d\n", buscado, numero);
        else
                printf("el numero %d no esta en %d\n", buscado, numero);

        return 0;
}

int pertenece(int buscado, int numero)
{
        if(numero%10 == buscado) {
                return 1;
        }
        else {
                if(numero > 10)
                        
                        return pertenece(buscado, numero/10);
                else
                        return 0;
        }
}