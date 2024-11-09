#include "lista_numeros.h"
#include <stdio.h>

void inicializar_lista(ListaNumeros *lista)
{
        lista->size = 0;
}
void mostrar_lista(ListaNumeros *lista)
{
        int i;
        for (i = 0; i < lista->size; i++) {
                printf("%d, ", lista->elementos[i]);
        }
}
void agregar_numero(ListaNumeros *lista, int numero)
{
        lista->elementos[lista->size++] = numero;
}