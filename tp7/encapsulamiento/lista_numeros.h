typedef struct {
        int elementos[20];
        int size;
} ListaNumeros;

void inicializar_lista(ListaNumeros *lista);
void mostrar_lista(ListaNumeros *lista);
void agregar_numero(ListaNumeros *lista, int numero);