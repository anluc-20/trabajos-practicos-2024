#include "lista_par.h"
#include <stdlib.h>
#define LISTA_SIZE 30
struct ListaPares {
        ParOrdenado *arr[LISTA_SIZE];
        int size;
};

ListaPares* crear_lista_pares()
{
        ListaPares *pares = NULL;
        pares = malloc(sizeof(ListaPares));
        pares->size = 0;
        return pares;
}
void mostrar_lista_pares(ListaPares *pares)
{
        int i;
        for (i = 0; i < pares->size; i++) {
                mostrar_par_ordenado(pares->arr[i]);
        }
}
void agregar_lista_pares(ListaPares *pares, ParOrdenado *par)
{
        pares->arr[pares->size] = par;
        pares->size++;
}
int operar_lista_y_devuelve_menor(ListaPares *pares)
{
        int menor, aux, i;
        for (i = 0; i < pares->size; i++) {
                aux = operar_par_ordenado(pares->arr[i]);

                if(i == 0)
                        menor = aux;

                if (aux < menor)
                        menor = aux;
        }
        return menor;
}

void eliminar_lista_pares(ListaPares *pares)
{
        int i;
        for (i = 0; i < pares->size; i++) {
                eliminar_par_ordenado(pares->arr[i]);
        }
        free(pares);
        pares = NULL;
}
