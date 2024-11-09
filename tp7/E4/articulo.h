#define CADENA_MAX_SIZE 30
#define ARTICULOS_MAX_SIZE 30
/*
Ejercicio  4:  Una  Tienda  que  vende  artículos  de  librería  administra  una  lista  de  N  artículos,  de  cada 
artículo  se  lleva  la  siguiente  información:
Código  del  artículo;
Nombre  del  artículo;
Proveedor;
Stock;
Precio de venta.
Se  necesita  un  programa  convenientemente  modularizado  que  utilizando  el  concepto  de  TAD  permita 
ingresar una lista de N artículos la cual se ordenará a medida que se ingresan los registros por el campo 
DNI. Posteriormente a través de un menú realizar las siguientes operaciones:  
a) Agregar un nuevo artículo a la lista preservando el orden.  
b) Eliminar un artículo de la lista dado su Código.  
c) Mostrar los artículos de la lista.  
d) Mostrar los artículos de un Proveedor ingresado por teclado.  
e) Dado un nivel de stock mínimo ingresado por teclado, generar una nueva lista con los artículos 
que tienen un Stock menor que el ingresado y luego mostrarlo 
*/

typedef char Cadena[CADENA_MAX_SIZE];
typedef struct {
        int codigo;
        Cadena nombre;
        Cadena proveedor;
        int stock;
        double precio;
} Articulo;
typedef int (*Comparador)(Articulo*, Articulo*);

typedef struct {
        Articulo *p[ARTICULOS_MAX_SIZE];
        int size;
} ListaArticulos;

void ingresar_articulo(Articulo *articulo, int codigo);
void ordenar_lista_articulos(ListaArticulos *articulos, Comparador);
void eliminar_articulo(ListaArticulos *articulos, int indice);
void buscar_articulos(const ListaArticulos *articulos, ListaArticulos *salida, Comparador, Articulo comparado);
void inicializar_lista_articulos(ListaArticulos *articulos, Articulo *array);
int buscar_articulo(ListaArticulos *articulos, int codigo);
void agregar_articulo(ListaArticulos *articulos);
void mostrar_articulo(const Articulo *articulo);
void mostrar_articulos(const ListaArticulos *articulos);