/*
        Ejercicio 2:  
Escribir un programa que cree una lista enlazada considerando lo siguiente:   
a) La  lista  debe  ser  de  números  enteros  positivos  al  azar,  respetando  el  criterio  de  que,  si  el 
número es par se agrega al principio de la lista y si es impar se agrega al final de la lista.  
b) Recorrer la lista para mostrar los elementos por pantalla.  
c) Mostrar todos los números que superen un valor determinado
*/
#include "../lista_enlazada/lista_enteros.h"
#include <stdio.h>

int main()
{
        int numero;
        NodoPtr cabeza = crear_lista();
        
        cargar_lista(&cabeza);
        mostrar_lista(cabeza);
        printf("ingrese un numero: ");
        scanf("%d", &numero);
        mostrar_mayores_que(cabeza, numero);
        return 0;
}