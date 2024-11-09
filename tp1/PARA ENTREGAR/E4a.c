#include <stdio.h>  // Inclusi�n de la biblioteca est�ndar de entrada/salida

// Funci�n principal del programa
int main (void) {  // Inicio de la funci�n main
	
	// Declaraci�n de variables enteras para el d�a, mes y a�o
	int d, m, a;  // Identificadores de variables de tipo entero
	
	// Solicitud de datos al usuario
	printf("ingrese datos: ");  // Sentencia simple - Salida de datos
	
	// Lectura de la entrada del usuario y asignaci�n a las variables correspondientes
	scanf("%d", &d);  // Sentencia simple - Entrada de datos
	scanf("%d", &m);  // Sentencia simple - Entrada de datos
	scanf("%d", &a);  // Sentencia simple - Entrada de datos
	
	// Verificaci�n de la validez del mes
	if (m < 1 || m > 12)  // Sentencia compuesta - Estructura de control de selecci�n
		printf("\n Datos invalido");  // Sentencia simple - Salida de datos
	else  // Sentencia compuesta - Estructura de control alternativa
		// Verificaci�n de la validez del a�o
		if (a < 1900 || a > 2024)  // Sentencia compuesta - Estructura de control de selecci�n
			printf("\n Datos invalido");  // Sentencia simple - Salida de datos
		else  // Sentencia compuesta - Estructura de control alternativa
			// Verificaci�n de la validez del d�a
			if (d < 1 || d > 31)  // Sentencia compuesta - Estructura de control de selecci�n
				printf("\n Datos invalido");  // Sentencia simple - Salida de datos
			else  // Sentencia compuesta - Estructura de control alternativa
				printf("\n Datos validos");  // Sentencia simple - Salida de datos
	
	// Retorno de valor 0, indicando que el programa termin� correctamente
	return 0;  // Sentencia simple - Salida del programa
}  // Fin de la funci�n main
