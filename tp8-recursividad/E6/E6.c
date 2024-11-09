/*
Ejercicio  6:  La  siguiente  función  retorna  el  enésimo  elemento  de  la  sucesión  de  Fibonacci,  realice  el 
árbol de llamadas para n=4 y para n=7. Pruebe la función fibo, con n= 10, 20, 30, 40, 44, 45, 46, 47, 48, 
49, 50 y 51. ¿Qué observa? ¿Por qué?

demoro un monton y de desbordo el int de paso
*/
#include <stdio.h>
int fibonacci(int posicion);
long long fibonacci2(int posicion);

int main()
{
        int numero;
        numero = 51;
        printf("el elemento numero %d de la sucesion de fibonacci es: %I64d", numero, fibonacci2(numero));
        return 0;
}

int fibonacci(int posicion)
{
        if(posicion == 2)
                return 1;
        if(posicion < 2)
                return 0;
        else
                return fibonacci(posicion-1) + fibonacci(posicion-2);
}
long long fibonacci2(int posicion)
{
        long long i, anterior, resultado, aux;
        resultado = 1;
        anterior = 0;
        if(posicion == 2)
                return 1;
        if(posicion < 2)
                return 0;
        for (i = 2; i < posicion; i++) {
                aux = resultado;
                resultado += anterior;
                anterior = aux;
        }
        return resultado;
}