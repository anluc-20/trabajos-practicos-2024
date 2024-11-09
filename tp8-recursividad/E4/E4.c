/*
Ejercicio 4: 
Dada la siguiente definición recursiva: 
resto(x, y) {
        x < y -> x;
        x >= y -> resto(x-y, y);
}
 Formule el módulo recursivo y la traza para el cálculo del resto (22,5). 
Nota: Esta función permite encontrar el resto de la división entera entre X e Y.
*/

#include <stdio.h>
int resto(int x, int y);

int main()
{
        int x, y;
        x = 22;
        y = 5;
        printf("el resto de dividir %d entre %d es: %d", x, y, resto(x, y));
        return 0;
}

int resto(int x, int y)
{
        if(x < y)
                return x;
        else
                return resto(x-y, y);
}

/*
        resto(22, 5)
                resto(17, 5)
                        resto(12, 5)
                                resto(7, 5)
                                        resto(2, 5) -> 2
*/
