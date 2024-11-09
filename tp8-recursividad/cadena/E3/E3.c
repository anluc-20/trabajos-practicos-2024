
// Ejercicio  3:  Realice  la  traza  del  siguiente  programa  con  los valores
// 30  y  525.  Elabore  una  consigna indicando qué hace el programa.
#include <stdio.h>
void averigua(int, int);
int main(void) {
        int x;
        printf("\n Ingrese un número natural ");
        scanf("%d", &x);
        averigua(x, 2);
        return 0;
}
void averigua(int N, int f) {
if (N > 1) // n es mayor que 1
        if (N % f == 0) { // si el resto de dividir n y f es 0
                printf("\t %d", f); // muestro f
                averigua(N / f, f); // llamo a averigua(n/f, f)
        } else
                averigua(N, f + 1); // llamo a averigua(n, f+1)
else    // muestro 1
        printf("\t %d", 1);
}

/*
        averigua(30,2) -> "2"
                averigua(15, 2)
                        averigua(15, 3) -> "3"
                                averigua(5, 3)
                                        averigua(5, 4)
                                                averigua(5, 5) -> "5"
                                                        averigua(1, 5) -> "1"
        
        averigua(525, 2)
                averigua(525, 3) -> "3"
                        averigua(175, 3)
                                averigua(175, 4)
                                        averigua(175, 5) -> "5"
                                                averigua(35, 5) -> "5"
                                                        averigua(7, 5)
                                                                averigua(7, 6)
                                                                        averigua(7, 7) -> "1"
        El algoritmo encuentra los factores primos de un numero dado, sin tener en cuenta el 1 que muestra al final(el 1 no es primo)
*/

