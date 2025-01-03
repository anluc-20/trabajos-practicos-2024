/*
Ejercicio 12: Diseñe un programa recursivo que permita mediante un menú, administrar una lista de
pacientes. Los datos a registrar por cada paciente serán: Apellido y Nombre, DNI, Tipo de Atención
(Clínica, Odontología, Traumatología), Fecha de Atención. El programa debe generar, dado un Tipo de
Atención y una Fecha de Atención, una nueva lista ordenada (Q-Sort) por el Apellido de los pacientes,
que se deben atender ese día. También dadas dos fechas indicar la cantidad de pacientes que se han
atendido entre esas fechas.
Nota: Ejercicio subido en el sitio para completar los módulos recursivos
*/
#include <stdio.h>
#include "TAD_ListaPacientes.h"

void opciones();
void menu_recursivo(TLista *, TLista *);

int main(void) {
	TLista A, D;

	A=carga_pacientes();
	
	menu_recursivo(&A, &D);
	return 0;
}
void opciones(){
	printf("\n=======Menu de opciones========");
	printf("\nIngrese 1: agregar un nuevo paciente a la lista");
	printf("\nIngrese 2: eliminar un paciente de la lista");
	printf("\nIngrese 3: modificar los datos de un paciente de la lista");
	printf("\nIngrese 4: mostrar la lista");
	printf("\nIngrese 5: generar y mostrar ordenada la lista de atencion segun un tipo y una fecha");
	printf("\nIngrese 6: cantidad de pacientes atendidos entre dos fechas");
	printf("\nIngrese 0: para salir del MENU");
}

void menu_recursivo(TLista *A, TLista *D){
	int rta, cant;
	
	opciones();
	printf("\nIngrese su eleccion: ");
	scanf("%d", &rta);
        getchar(); //limpio el salto de linea
	switch(rta){
	case 0: printf("\nA elegido Salir del Programa"); break;
	case 1:
		if(retorna_tam(*A)<10) 
			agrega_pacientes(A);	
		else
			printf("\nNo se puede agregar un paciente, lista llena");
		
		menu_recursivo(A, D);		
		break;
	case 2:
		if(retorna_tam(*A) !=0)
			elimina_pacientes(A);
		else
			printf("\nNo se puede eliminar un paciente, lista vacia");
		
		menu_recursivo(A, D); 
		break;
	case 3:
		if(retorna_tam(*A)>0){ 
			modifica_pacientes(A);
		}
		else
			printf("\nNo se puede modificar un paciente, lista vacia");
		
		menu_recursivo(A, D);		
		break;
	case 4:
		if(retorna_tam(*A)>0){ 
			mostra_pacientes(*A);
			printf("\nSe mostro exitosamente la lista de pacientes");
		}
		else
			printf("\nNo se puede mostrar la lista de pacientes, lista vacia");
		
		menu_recursivo(A, D);		
		break;
	case 5:
		if(retorna_tam(*A)>0){ 
			*D = genera_atencion(*A);
			if(retorna_tam(*D)>0){ 
				ordena_pacientes(D);
				mostra_pacientes(*D);
			}
			else
				printf("\nNo se pudo generar nueva lista");
		}	
		else
			printf("\nlista principal vacia");
		
		menu_recursivo(A, D);		
		break;
	case 6:
		if(retorna_tam(*A)>0){
			cant=cantidad_pacientes(*A);
			if (cant>0) printf("\nLa cantidad de pacientes atendidos es = %d ",cant);
			else printf("\n no hay pacientes atendidos en esas fechas");
		}
		else
			printf("\nNo se puede mostrar la cantidad de atencion, lista vacia");
		
		menu_recursivo(A, D);		
		break;	
	default:
		printf("\nA ingresado un valor no valido");
		menu_recursivo(A, D);
		break;
	}
}	
