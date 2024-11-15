#include <stdio.h>
#include "TAD_ListaCliente.h"

void opciones();
void menu_recursivo(TLista *, TLista *);

int main(void) {
	TLista A, D;
	A = inicializa();
	D = inicializa();
	A=cargar_clientes();
	
	menu_recursivo(&A, &D);
	return 0;
}
void opciones(){
	printf("\n=======Menu de opciones========");
	printf("\nIngrese 1: agregar un nuevo cliente a la lista");
	printf("\nIngrese 2: eliminar un cliente de la lista");
	printf("\nIngrese 3: modificar los datos de un cliente de la lista");
	printf("\nIngrese 4: mostrar la lista");
	printf("\nIngrese 5: genera y muestra la lista de deudores");
	printf("\nIngrese 0: para salir del MENU");}

void menu_recursivo(TLista *A, TLista *D){
		int rta;
		
		opciones();
		printf("\nIngrese su eleccion: ");
		scanf("%d", &rta);
		switch(rta){
		case 0: printf("\nA elegido Salir del Programa"); break;
		case 1: if(retorna_tam(*A)<10){
					agrega_cliente(A);}
				else  printf("\nNo se puede agregar un cliente, lista llena");
				menu_recursivo(A, D);		
				break;
		case 2: if(retorna_tam(*A)!=0){
					elimina_cliente(A);}
				else  printf("\nNo se puede eliminar un cliente, lista vacia");
				menu_recursivo(A, D); 
				break;
		case 3: if(retorna_tam(*A)>0){ 
					modifica_cliente(A);
					printf("\nSe modifico exitosamente el cliente");}
				else  printf("\nNo se puede modificar un cliente, lista vacia");
				menu_recursivo(A, D);		
				break;
		case 4: if(retorna_tam(*A)>0){ 
					mostrar_clientes(*A);
					printf("\nSe mostro exitosamente la lista de cliente");}
				else  printf("\nNo se puede mostrar la lista de cliente, lista vacia");
				menu_recursivo(A, D);		
				break;
		case 5: if(retorna_tam(*A)>0){ 
					genera_deudor(*A, D);
					if(retorna_tam(*D)>0){
						ordena_clientes(D);
						mostrar_clientes(*D);
					}
					else  printf("\nNo se puede mostrar la lista de deudores, lista vacia");
				}	
				else  printf("\nNo Lista vacia");
				menu_recursivo(A, D);		
				break;
		default: printf("\nA ingresado un valor no valido");
				menu_recursivo(A, D);
				break;
		}
	}	
