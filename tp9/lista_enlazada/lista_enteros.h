typedef struct Nodo Nodo;
typedef Nodo *NodoPtr;

struct Nodo {
        int numero;
        NodoPtr siguiente;
};

NodoPtr crear_lista();
void cargar_lista(NodoPtr *cabeza);
void carga_principio(NodoPtr *cabeza, NodoPtr nodo);
void carga_final(NodoPtr *cabeza, NodoPtr nodo);
void mostrar_lista(NodoPtr cabeza);
void mostrar_mayores_que(NodoPtr cabeza, int numero);