#define CONJUNTO_CHAR_MAX_SIZE 30
typedef struct {
        char elementos[CONJUNTO_CHAR_MAX_SIZE];
        int size;
} ConjuntoChar;

ConjuntoChar generar_conjunto_aleatorio();
void mostrar_conjunto(ConjuntoChar conjunto);
int intentar_agregar_elemento_al_conjunto(ConjuntoChar *p_conjunto, char elemento);
int buscar_elemento(const ConjuntoChar *p_conjunto, char elemento);
ConjuntoChar unir_conjuntos(ConjuntoChar A, ConjuntoChar B);