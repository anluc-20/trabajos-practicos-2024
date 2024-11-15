#include "TAD_Cliente.h"

RCliente cargar_cliente(){
	RCliente nvo;
	fflush(stdin);
	printf("\nIngrese el Nombre del cliente: ");
	cargar_cadena(nvo.nom);
	fflush(stdin);
	printf("\nIngrese el Apellido del cliente: ");
	cargar_cadena(nvo.ape);
	fflush(stdin);
	printf("\nIngrese el DNI del cliente: ");
	scanf("%ld", & nvo.dni);
	printf("\nIngrese el Saldo del cliente: ");
	scanf("%f", & nvo.saldo);
	return nvo;
}
void mostrar_cliente(RCliente cliente){
	printf("\nNombre y Apellido del cliente: %s %s\n", cliente.nom, cliente.ape);
	printf("\nDNI del cliente: %ld ----- Su saldo es: %f", cliente.dni, cliente.saldo);
}
void modificar_cliente(RCliente *cliente){
	RCliente nvo;
	nvo= *cliente;
	printf("\n---- Datos actuales del cliente ----");
	mostrar_cliente(nvo);
	printf("\n---- Modificar todos los Datos actuales del cliente ----");
	nvo= cargar_cliente();
	*cliente= nvo;
}
long retornar_DNI(RCliente cliente){
	return cliente.dni;
}
float retornar_saldo(RCliente cliente){
	return cliente.saldo;
}
int comparar_DNI(RCliente cliente, long bus){
        if(cliente.dni==bus)
                return 1;
        else
                return 0;
}

