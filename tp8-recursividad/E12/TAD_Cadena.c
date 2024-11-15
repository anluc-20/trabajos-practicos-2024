#include "TAD_Cadena.h"
#include <stdio.h>
#include <string.h>


void leeCad(TCadena cad, int indice){ /*Completar con proceso recursivo*/
	
	int c = getchar();
	
	if(((c == '\n') || (c == EOF) || (indice >= 19)) && (indice != -1)) {
		cad[indice] = '\0';
		indice = -1;
	}

	if(indice != -1) {
		cad[indice] = c;
		indice++;
	}

	if((c != '\n') && (c != EOF))
		leeCad(cad, indice);

	/*
		si indice == -1
		se puso el caracter de fin de cadena, ya sea por que se encontro un salto de linea
		o se alcanzo el tamanio maximo de la cadena. En cualquier caso, se va a seguir
		llamando la funcion para limpiar la entrada

		si indice != -1
		aun quedan caracteres en la entrada para leer y cargar.
	*/
}
void cargar_cadena(TCadena cad){
	leeCad(cad, 0);
}
int compara_cadena(TCadena cad1, TCadena cad2){
	return strcmp(cad1, cad2);
}