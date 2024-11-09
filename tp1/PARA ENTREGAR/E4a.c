#include <stdio.h>  // Inclusión de la biblioteca estándar de entrada/salida

// Función principal del programa
int main (void) {  // Inicio de la función main
	
	// Declaración de variables enteras para el día, mes y año
	int d, m, a;  // Identificadores de variables de tipo entero
	
	// Solicitud de datos al usuario
	printf("ingrese datos: ");  // Sentencia simple - Salida de datos
	
	// Lectura de la entrada del usuario y asignación a las variables correspondientes
	scanf("%d", &d);  // Sentencia simple - Entrada de datos
	scanf("%d", &m);  // Sentencia simple - Entrada de datos
	scanf("%d", &a);  // Sentencia simple - Entrada de datos
	
	// Verificación de la validez del mes
	if (m < 1 || m > 12)  // Sentencia compuesta - Estructura de control de selección
		printf("\n Datos invalido");  // Sentencia simple - Salida de datos
	else  // Sentencia compuesta - Estructura de control alternativa
		// Verificación de la validez del año
		if (a < 1900 || a > 2024)  // Sentencia compuesta - Estructura de control de selección
			printf("\n Datos invalido");  // Sentencia simple - Salida de datos
		else  // Sentencia compuesta - Estructura de control alternativa
			// Verificación de la validez del día
			if (d < 1 || d > 31)  // Sentencia compuesta - Estructura de control de selección
				printf("\n Datos invalido");  // Sentencia simple - Salida de datos
			else  // Sentencia compuesta - Estructura de control alternativa
				printf("\n Datos validos");  // Sentencia simple - Salida de datos
	
	// Retorno de valor 0, indicando que el programa terminó correctamente
	return 0;  // Sentencia simple - Salida del programa
}  // Fin de la función main
