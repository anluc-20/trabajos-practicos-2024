#include "lista_numeros.h"

int main()
{
        ListaNumeros lista;
        inicializar_lista(&lista);
        agregar_numero(&lista, 6);
        agregar_numero(&lista, 7);
        agregar_numero(&lista,8);
        mostrar_lista(&lista);

        return 0;
}