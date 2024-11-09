#include <stdio.h>  // Inclusi�n de la biblioteca est�ndar de entrada/salida

// Funci�n principal del programa
int main() {  // Inicio de la funci�n main
	
	// Declaraci�n de variables enteras
	int x, aux, s, d, b, c;  // Identificadores de variables de tipo entero
	
	// Inicializaci�n de la variable contadora c
	c = 0;  // Sentencia simple - Asignaci�n de valor a una variable
	
	// Solicitud de un n�mero natural al usuario
	printf("\n ingrese natural");  // Sentencia simple - Salida de datos
	
	// Lectura de la entrada del usuario y asignaci�n a la variable x
	scanf("%d", &x);  // Sentencia simple - Entrada de datos
	
	// Ciclo principal que se ejecuta mientras x sea mayor que 0
	while (x > 0) {  // Sentencia compuesta - Estructura de control de repetici�n
		
		aux = x;  // Sentencia simple - Asignaci�n de valor a una variable
		s = 0;  // Sentencia simple - Inicializaci�n de la variable suma
		
		// Ciclo que calcula la suma de los d�gitos del n�mero
		while (x != 0) {  // Sentencia compuesta - Estructura de control de repetici�n
			d = x % 10;  // Sentencia simple - Asignaci�n de valor a una variable (obtenci�n del �ltimo d�gito)
			s = s + d;  // Sentencia simple - Suma acumulativa de los d�gitos
			x = x / 10;  // Sentencia simple - Reducci�n del n�mero (eliminar el �ltimo d�gito)
		}
		
		x = aux;  // Sentencia simple - Restauraci�n del valor original de x
		b = 0;  // Sentencia simple - Inicializaci�n de la variable bandera
		
		// Ciclo que verifica si alg�n d�gito no divide a la suma s
		while ((x != 0) && (b == 0)) {  // Sentencia compuesta - Estructura de control de repetici�n
			d = x % 10;  // Sentencia simple - Obtenci�n del �ltimo d�gito
			
			// Verificaci�n de divisibilidad
			if (d != 0 && s % d != 0)  // Sentencia compuesta - Estructura de control de selecci�n
				b = 1;  // Sentencia simple - Actualizaci�n de la variable bandera
			else  // Sentencia compuesta - Estructura de control alternativa
				x = x / 10;  // Sentencia simple - Reducci�n del n�mero (eliminar el �ltimo d�gito)
		}
		
		// Si todos los d�gitos dividen a la suma, se incrementa el contador c
		if (b == 0)  // Sentencia compuesta - Estructura de control de selecci�n
			c = c + 1;  // Sentencia simple - Incremento del contador
		
		// Solicitud de un nuevo n�mero natural al usuario
		printf("\n ingrese natural");  // Sentencia simple - Salida de datos
		scanf("%d", &x);  // Sentencia simple - Entrada de datos
	}
	
	// Verificaci�n final y salida de resultados
	if (c == 0)  // Sentencia compuesta - Estructura de control de selecci�n
		printf("\n ninguno cumple");  // Sentencia simple - Salida de datos
	else  // Sentencia compuesta - Estructura de control alternativa
		printf("\n cumplen %d", c);  // Sentencia simple - Salida de datos
	
	// Retorno de valor 0, indicando que el programa termin� correctamente
	return 0;  // Sentencia simple - Salida del programa
}  // Fin de la funci�n main

