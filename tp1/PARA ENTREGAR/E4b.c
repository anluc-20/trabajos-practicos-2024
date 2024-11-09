#include <stdio.h>  // Inclusi�n de la biblioteca est�ndar de entrada/salida

// Declaraci�n del prototipo de la funci�n mes
void mes(int m);  // Declaraci�n de m�dulo (funci�n) - Identificador de funci�n

// Funci�n principal del programa
int main(void) {  // Inicio de la funci�n main
	
	// Declaraci�n de variables enteras para el d�a, mes y a�o
	int d, m, a;  // Identificadores de variables de tipo entero
	
	// Solicitud de la fecha al usuario
	printf("ingrese fecha: ");  // Sentencia simple - Salida de datos
	
	// Lectura de la entrada del usuario y asignaci�n a las variables correspondientes
	scanf("%d", &d);  // Sentencia simple - Entrada de datos
	scanf("%d", &m);  // Sentencia simple - Entrada de datos
	scanf("%d", &a);  // Sentencia simple - Entrada de datos
	
	// Impresi�n del d�a ingresado por el usuario
	printf("\n%d de ", d);  // Sentencia simple - Salida de datos
	
	// Llamada a la funci�n mes para imprimir el nombre del mes
	mes(m);  // Sentencia de estructura - Llamada a funci�n
	
	// Impresi�n del a�o ingresado por el usuario
	printf(" de %d", a);  // Sentencia simple - Salida de datos
	
	// Retorno de valor 0, indicando que el programa termin� correctamente
	return 0;  // Sentencia simple - Salida del programa
}  // Fin de la funci�n main

// Definici�n de la funci�n mes, que recibe un entero y muestra el nombre del mes correspondiente
void mes(int m) {  // Inicio de la funci�n mes
	switch(m) {  // Sentencia compuesta - Estructura de control de selecci�n m�ltiple
	case 1: printf("enero"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	case 2: printf("febrero"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	case 3: printf("marzo"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	case 4: printf("abril"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	case 5: printf("mayo"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	case 6: printf("junio"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	case 7: printf("julio"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	case 8: printf("agosto"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	case 9: printf("septiembre"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	case 10: printf("octubre"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	case 11: printf("noviembre"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	case 12: printf("diciembre"); break;  // Sentencia simple - Salida de datos y finalizaci�n de caso
	}  // Fin de la estructura switch
}  // Fin de la funci�n mes

