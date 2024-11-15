#include "TAD_Paciente.h"

typedef RPaciente TVector [10];
typedef struct{
	TVector lis;
	int tam;
} TLista;

TLista inicializa_lista();
int retorna_tam(TLista);
TLista carga_pacientes();
void agrega_pacientes(TLista *);
void elimina_pacientes(TLista *);
void modifica_pacientes(TLista *);
void mostra_pacientes(TLista );
TLista genera_atencion(TLista);
void ordena_pacientes(TLista *);
int cantidad_pacientes(TLista );