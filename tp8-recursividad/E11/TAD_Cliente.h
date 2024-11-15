#include "TAD_Cadena.h"

typedef struct{
	TCadena ape, nom;
	long dni;
	float saldo;
}RCliente;

RCliente cargar_cliente();
void modificar_cliente(RCliente *cliente);
void mostrar_cliente(RCliente);
long retornar_DNI(RCliente);
float retornar_saldo(RCliente);
int comparar_DNI(RCliente, long);
