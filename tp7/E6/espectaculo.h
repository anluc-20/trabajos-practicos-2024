#include "../fecha/fecha.h"
#include "../hora/hora.h"
#define CAD_MAX_SIZE 30
#define ESPECTACULOS_MAX_SIZE 30

/*
Ejercicio 6: Una empresa multi-sala de espectáculos nos contrata para que le construyamos un software 
que permita administrar los espectáculos que ofrece.   
Para ello en la 1era reunión que mantenemos con el encargado de espectáculos nos comenta los datos 
que necesita registrar de cada uno de ellos, los cuales son: “
Código del  espectáculo;
Nombre  del espectáculo;
Fecha de inicio;
Fecha de fin;
Horario inicio;
Horario Fin;
Nro. de Sala
” También nos explica 
las acciones a realizar con cada uno de los espectáculos:  
• Cargar los datos de un espectáculo.  
• Mostrar los datos de un espectáculo.  
• Retornar el nro. de sala de un espectáculo.  
• Modificar la fecha de inicio o fin de un espectáculo.  
• Modificar la hora de inicio o fin de un espectáculo.  
Nuestro  trabajo  consiste  en  crear  los  TADs  necesarios  que  permita  realizar  lo  propuesto  por  nuestro 
cliente.  Luego  un  programa  que  utilizando  los  TADs  creados  permita  administrar  una  lista  de  N 
espectáculos. 
*/

typedef char Cadena[CAD_MAX_SIZE];

typedef struct {
        int codigo;
        Cadena nombre;
        Fecha fecha_inicio;
        Fecha fecha_fin;
        Hora hora_inicio;
        Hora hora_fin;
        int sala;
} Espectaculo;

typedef struct {
        Espectaculo *p[ESPECTACULOS_MAX_SIZE];
        int size;
} ListaEspectaculo;

typedef Espectaculo EspectaculoArray[ESPECTACULOS_MAX_SIZE];
typedef int (*Comparador)(Espectaculo*, Espectaculo*);

void inicializar_lista_espectaculo(ListaEspectaculo *espectaculos, EspectaculoArray array);
void ingresar_espectaculo(Espectaculo *espectaculo, int codigo);
void ingresar_fecha_espectaculo(Espectaculo *espectaculo);
void ingresar_hora_espectaculo(Espectaculo *espectaculo);
int intentar_agregar_espectaculo(ListaEspectaculo *espectaculos);
void mostrar_espectaculo(const Espectaculo *espectaculo);
void mostrar_lista_espectaculo(ListaEspectaculo *espectaculos);

void ordenar_lista_espectaculo(ListaEspectaculo *espectaculos, Comparador comparador);
int buscar_espectaculo(ListaEspectaculo *espectaculos, Comparador comparador, Espectaculo filtro);
void buscar_espectaculos(ListaEspectaculo *espectaculos, ListaEspectaculo *salida, Comparador comparador, Espectaculo filtro);
int buscar_espectaculo_por_codigo(ListaEspectaculo *espectaculos, int codigo);

int comparar_por_codigo(Espectaculo *a, Espectaculo *b);
int comparar_por_sala(Espectaculo *a, Espectaculo *b);