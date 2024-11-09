#include "../utils/utils.h"
#include "conjunto_de_caracteres.h"
#include <stdio.h>
#define OPCIONES "a) Agregar un nuevo elemento al conjunto A.\nb) Agregar un nuevo elemento al conjunto B.\nc) Mostrar el conjunto A\nd) Mostrar el conjunto B\ne) Mostrar la unión de los conjuntos A y B.\nf) Dado un carácter determinar si pertenece a el Conjunto A o Conjunto B o está en ambos conjuntos.\ng) Salir\nopcion: "
/*
Ejercicio 2: Realizar la especificación e implementación de un TAD que permita registrar un conjunto de
caracteres, con la posibilidad de realizar las siguientes tareas:
 Generar al azar un conjunto,
 Mostrar el conjunto
 Agregar un elemento al conjunto
 Determinar si un elemento pertenece o no al conjunto
Crear el conjunto resultante de la unión
de dos.
Luego generar un programa que utilizando el TAD_Conjunto permita generar el conjunto A y B y que a
través de un menú permita:
a) Agregar un nuevo elemento al conjunto A.
b) Agregar un nuevo elemento al conjunto B.
c) Mostrar el conjunto A.
d) Mostrar el conjunto B
e) Mostrar la unión de los conjuntos A y B.
f) Dado un carácter determinar si pertenece a el Conjunto A o Conjunto B o está en ambos
conjuntos.
Nota: El conjunto no debe tener elementos repetidos y debe estar ordenado ascendentemente. 
*/

//opciones del menu
void agregar_elemento_a_A(void *conjuntos_void);
void agregar_elemento_a_B(void *conjuntos_void);
void mostrar_A(void *conjuntos_void);
void mostrar_B(void *conjuntos_void);
void mostrar_union_de_A_B(void *conjuntos_void);
void determinar_si_caracter_esta_en_A_o_B(void *conjuntos_void);

//funcionees
void agregar_elemento_al_conjunto(ConjuntoChar *p_conjunto);

int main()
{
        int salir = 0, cant_funciones = 6;
        MenuOption opciones[] = {
                agregar_elemento_a_A,
                agregar_elemento_a_B,
                mostrar_A,
                mostrar_B,
                mostrar_union_de_A_B,
                determinar_si_caracter_esta_en_A_o_B
        };
        ConjuntoChar conjuntos[] = { generar_conjunto_aleatorio(), generar_conjunto_aleatorio()};
        while(!salir)
                menu(&salir, opciones, conjuntos, cant_funciones, OPCIONES);
        return 0;
}

//opciones del menu
void agregar_elemento_a_A(void *conjuntos_void)
{
        ConjuntoChar *p_conjuntos = conjuntos_void;
        agregar_elemento_al_conjunto(&p_conjuntos[0]);
}
void agregar_elemento_a_B(void *conjuntos_void)
{
        ConjuntoChar *p_conjuntos = conjuntos_void;
        agregar_elemento_al_conjunto(&p_conjuntos[1]);
}
void mostrar_A(void *conjuntos_void)
{
        ConjuntoChar *p_conjuntos = conjuntos_void;
        mostrar_conjunto(p_conjuntos[0]);
}
void mostrar_B(void *conjuntos_void)
{
        ConjuntoChar *p_conjuntos = conjuntos_void;
        mostrar_conjunto(p_conjuntos[1]);
}
void mostrar_union_de_A_B(void *conjuntos_void)
{
        ConjuntoChar *p_conjuntos = conjuntos_void;
        ConjuntoChar a_union_b = unir_conjuntos(p_conjuntos[0], p_conjuntos[1]);
        mostrar_conjunto(a_union_b);
}
void determinar_si_caracter_esta_en_A_o_B(void *conjuntos_void)
{
        ConjuntoChar *p_conjuntos = conjuntos_void;
        char caracter;
        int indice_a, indice_b;
        ingresar_char("ingrese el caracter: ", &caracter);

        indice_a = buscar_elemento(&p_conjuntos[0], caracter);
        indice_b = buscar_elemento(&p_conjuntos[1], caracter);

        if(indice_a == -1)
                printf("el caracter no se encuentra en A\n");
        else
                printf("el caracter se encuentra en A\n");

        if(indice_b == -1)
                printf("el caracter no se encuentra en B\n");
        else
                printf("el caracter se encuentra en B\n");
}

void agregar_elemento_al_conjunto(ConjuntoChar *p_conjunto)
{
        char elemento;
        int exito;
        ingresar_char("ingrese el elemento a agregar: ", &elemento);
        exito = intentar_agregar_elemento_al_conjunto(p_conjunto, elemento);
        if(exito)
                printf("se ha agregado correctamente el caracter.\n");
        else
                printf("no se pudo agregar el caracter, ya existe o el conjunto esta lleno.\n");
}