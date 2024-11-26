/*
 * Ejercicio 3:  Retomar el ejercicio 2 agregando un menú que permita seleccionar las operaciones b) y c) y además las siguientes:  a) Modificar cada número primo, transformándolo en negativo;  b) Insertar, en la lista, delante de cada número par, el número cero.  

b) Recorrer la lista para mostrar los elementos por pantalla.  
c) Mostrar todos los números que superen un valor determinado

 * */
#include "lista_enteros.h"
#include <stdio.h>

void menu(NodoPtr *cabeza);

int main()
{
        NodoPtr cabeza = crear_lista();      
        cargar_lista(&cabeza);
        
        menu(&cabeza);
        return 0;
}

void menu(NodoPtr *cabeza)
{
        int opcion, salir, numero;
        salir = 0;
        while(!salir) {
                printf("\nOpciones:\n0. Salir\n1. Transformar primos en negativos\n2. Insertar 0 delante de los numeros pares\n3. Mostrar lista\n4. Mostrar mayores que\n");
                scanf("%d", &opcion);
                switch (opcion) {
                        case 0:
                                printf("saliendo...\n");
                                salir = 1; 
                                break;

                        case 1:
                                transformar_primos_en_negativos(*cabeza);
                                break;


                        case 2:
                                poner_ceros_adelante_de_pares(*cabeza);
                                break;

                        case 3:
                                mostrar_lista(*cabeza);
                                break;

                        case 4:
                                printf("ingrese un numero: ");
                                scanf("%d", &numero);
                                printf("los mayores que %d son: \n", numero);
                                mostrar_mayores_que(*cabeza, numero);
                                break;

                        default:
                                printf("opcion invalida.\n");
                                break;
                }
        }
}
