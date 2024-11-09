#include "conjunto_de_caracteres.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenar_conjunto(ConjuntoChar *p_conjunto)
{
        int i, j, aux;
        for (i = 1; i < p_conjunto->size; i++) {
                j = i - 1;
                while((j >= 0) && (p_conjunto->elementos[j+1] < p_conjunto->elementos[j])) {
                        aux = p_conjunto->elementos[j+1];
                        p_conjunto->elementos[j+1] = p_conjunto->elementos[j];
                        p_conjunto->elementos[j] = aux;
                        j--;
                }
        }
}
/*
ConjuntoChar generar_conjunto_aleatorio()
{
        ConjuntoChar conjunto;
        int min_char = 33, max_char = 126, i = 0, fin = CONJUNTO_CHAR_MAX_SIZE/3, exito; // ! y ~ respectivamente
        char random_char;
        srand(time(NULL));
        while (i < fin) {
                random_char = rand() % (max_char - min_char + 1) + min_char;
                exito = intentar_agregar_elemento_al_conjunto(&conjunto, random_char);
                if(exito)
                        i++;
        }
        conjunto.size = fin;
        ordenar_conjunto(&conjunto);
        return conjunto;
}*/

//esta version podria ser mas eficiente que la anterior puesto que nos ahorramos la busqueda, y los posibles caracteres duplicados
ConjuntoChar generar_conjunto_aleatorio()
{
        ConjuntoChar conjunto;
        int i, j, indice_random, size = 94, fin = CONJUNTO_CHAR_MAX_SIZE/3;
        char caracteres[size];

        //llenamos el array con caracteres alfanumericos (94 en total)
        for(i = 0; i < size; i++) {
                caracteres[i] = i + 33;
        }

        srand(time(NULL));

        //seleccionamos aleatoriamente un caracter del array caracteres y lo "movemos" al conjunto
        for (i = 0; i < fin; i++) {
                indice_random = rand() % (size + 1);
                conjunto.elementos[i] = caracteres[indice_random];
                size--;
                for(j = indice_random; j < size; j++) {
                        caracteres[j] = caracteres[j+1];
                }
        }

        conjunto.size = fin;
        ordenar_conjunto(&conjunto);
        return conjunto;
}
void mostrar_conjunto(ConjuntoChar conjunto)
{
        int i;
        printf("elementos: {");
        for (i = 0; i < conjunto.size; i++) {
                printf("%c, ", conjunto.elementos[i]);
        }
        printf("}\n");
}
int intentar_agregar_elemento_al_conjunto(ConjuntoChar *p_conjunto, char elemento)
{
        int resultado = 0;
        if(p_conjunto->size < CONJUNTO_CHAR_MAX_SIZE) {
                if(buscar_elemento(p_conjunto, elemento) == -1)
                {
                        p_conjunto->elementos[p_conjunto->size] = elemento;
                        p_conjunto->size++;
                        ordenar_conjunto(p_conjunto);
                        resultado = 1;
                }
        }
        return resultado;
}
int buscar_elemento(const ConjuntoChar *p_conjunto, char elemento)
{
        int indice, inicio = 0, fin = p_conjunto->size - 1, m = (inicio + fin) / 2;
        while((inicio < fin) && (p_conjunto->elementos[m] != elemento)) {
                if(p_conjunto->elementos[m] > elemento)
                        fin = m - 1;
                else
                        inicio = m + 1;
                m = (inicio + fin) / 2;
        }
        if(p_conjunto->elementos[m] == elemento)
                indice = m;
        else
                indice = -1;

        return indice;
}
ConjuntoChar unir_conjuntos(ConjuntoChar A, ConjuntoChar B)
{
        ConjuntoChar C;
        int i;
        C.size = A.size;

        for (i = 0; i < C.size; i++)
                C.elementos[i] = A.elementos[i];

        for (i = 0; i < B.size; i++)
                intentar_agregar_elemento_al_conjunto(&C, B.elementos[i]);

        return C;
}