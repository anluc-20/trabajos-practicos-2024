#include "par_ordenado.h"

typedef struct ListaPares ListaPares;

ListaPares* crear_lista_pares();
void mostrar_lista_pares(ListaPares *pares);
void agregar_lista_pares(ListaPares *pares, ParOrdenado *par);
int operar_lista_y_devuelve_menor(ListaPares *pares);
void eliminar_lista_pares(ListaPares *pares);

