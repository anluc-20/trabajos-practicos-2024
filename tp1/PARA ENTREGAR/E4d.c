#include <stdio.h>   // Inclusi�n de la biblioteca est�ndar de entrada/salida
#include <stdlib.h>  // Inclusi�n de la biblioteca est�ndar de utilidades (para usar abs)

// Declaraci�n del prototipo de la funci�n may
int may(int num);  // Declaraci�n de m�dulo (funci�n) - Identificador de funci�n

// Funci�n principal del programa
int main() {  // Inicio de la funci�n main
	
	// Declaraci�n de variables enteras
	int i, n, x;  // Identificadores de variables de tipo entero
	
	// Solicitud de la cantidad de datos que se van a ingresar
	printf("Ingrese cantidad de datos: \n");  // Sentencia simple - Salida de datos
	
	// Lectura de la cantidad de datos (n) que se va a procesar
	scanf("%d", &n);  // Sentencia simple - Entrada de datos
	
	// Ciclo que se ejecuta n veces para procesar cada dato ingresado
	for (i = 1; i <= n; i++) {  // Sentencia compuesta - Estructura de control de repetici�n
		
		// Solicitud de un dato (n�mero entero) al usuario
		printf("Ingrese un dato: \n");  // Sentencia simple - Salida de datos
		
		// Lectura del dato ingresado por el usuario
		scanf("%d", &x);  // Sentencia simple - Entrada de datos
		
		// Llamada a la funci�n may para obtener el d�gito mayor del n�mero
		// y mostrar el resultado al usuario
		printf("Digito mayor: %d\n", may(x));  // Sentencia de estructura - Llamada a funci�n y salida de datos
	}
	
	// Retorno de valor 0, indicando que el programa termin� correctamente
	return 0;  // Sentencia simple - Salida del programa
}  // Fin de la funci�n main

// Definici�n de la funci�n may, que recibe un entero y retorna el d�gito mayor
int may(int num) {  // Inicio de la funci�n may
	
	// Declaraci�n de variables enteras
	int d, my = -1;  // Identificadores de variables de tipo entero
	
	// Obtenci�n del valor absoluto de num (en caso de que sea negativo)
	num = abs(num);  // Sentencia simple - Asignaci�n de valor a una variable (uso de la funci�n abs)
	
	// Ciclo que recorre cada d�gito del n�mero
	while (num != 0) {  // Sentencia compuesta - Estructura de control de repetici�n
		
		d = num % 10;  // Sentencia simple - Obtenci�n del �ltimo d�gito del n�mero
		
		num = num / 10;  // Sentencia simple - Reducci�n del n�mero (eliminar el �ltimo d�gito)
		
		// Comparaci�n para encontrar el d�gito mayor
		if (d > my)  // Sentencia compuesta - Estructura de control de selecci�n
			my = d;  // Sentencia simple - Actualizaci�n de la variable my
	}
	
	// Retorno del d�gito mayor encontrado
	return my;  // Sentencia simple - Salida de la funci�n
}  // Fin de la funci�n may
