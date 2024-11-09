/*
Ejercicio 1: Dado el módulo iterativo que calcula el factorial de un número natural, se solicita replantearlo 
recursivamente y realizar la traza con num=6. 
int factorial(int num){ int i,fact=1; 
for (i=num; i>=1; i--) fact=fact*i; 
return fact; }
*/
#include <stdio.h>
int factorial(int numero);
int main()
{
        int n = 6;
        printf("factorial de %d es %d\n", n, factorial(n));
        return 0;
}

int factorial(int numero)
{
        if(numero == 1)
                return 1;
        else
                return numero * factorial(numero - 1);
}