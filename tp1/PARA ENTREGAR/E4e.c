#include <stdio.h>  // Inclusi�n de la biblioteca est�ndar de entrada/salida

// Declaraci�n del prototipo de la funci�n analiza
int analiza(int num);  // Declaraci�n de m�dulo (funci�n) - Identificador de funci�n

// Funci�n principal del programa
int main() {  // Inicio de la funci�n main
	
	// Declaraci�n de variables enteras
	int x, may, men, b;  // Identificadores de variables de tipo entero
	
	// Inicializaci�n de la variable bandera b
	b = 0;  // Sentencia simple - Asignaci�n de valor a una variable
	
	// Solicitud de un n�mero natural al usuario
	printf("Ingrese un n�mero natural: \n");  // Sentencia simple - Salida de datos
	
	// Lectura del n�mero ingresado por el usuario y asignaci�n a la variable x
	scanf("%d", &x);  // Sentencia simple - Entrada de datos
	
	// Ciclo que se ejecuta mientras x sea mayor que 0
	while (x > 0) {  // Sentencia compuesta - Estructura de control de repetici�n
		
		// Verificaci�n si el n�mero es primo llamando a la funci�n analiza
		if (analiza(x) == 1) {  // Sentencia compuesta - Estructura de control de selecci�n
			
			// Si es la primera vez que se encuentra un primo
			if (b == 0) {  // Sentencia compuesta - Estructura de control de selecci�n
				may = x;  // Sentencia simple - Asignaci�n de valor a la variable mayor
				men = x;  // Sentencia simple - Asignaci�n de valor a la variable menor
				b = 1;  // Sentencia simple - Actualizaci�n de la variable bandera
			} else {  // Sentencia compuesta - Estructura de control alternativa
				// Actualizaci�n del mayor primo encontrado
				if (may < x)  // Sentencia compuesta - Estructura de control de selecci�n
					may = x;  // Sentencia simple - Asignaci�n de valor a la variable mayor
				
				// Actualizaci�n del menor primo encontrado
				if (men > x)  // Sentencia compuesta - Estructura de control de selecci�n
					men = x;  // Sentencia simple - Asignaci�n de valor a la variable menor
			}
		}
		
		// Solicitud de un nuevo n�mero natural al usuario
		printf("Ingrese un n�mero natural: \n");  // Sentencia simple - Salida de datos
		scanf("%d", &x);  // Sentencia simple - Entrada de datos
	}
	
	// Verificaci�n final y salida de resultados
	if (b == 0)  // Sentencia compuesta - Estructura de control de selecci�n
		printf("\nNo se ingresaron primos");  // Sentencia simple - Salida de datos
	else  // Sentencia compuesta - Estructura de control alternativa
		printf("El mayor primo natural: %d, el menor primo natural es: %d", may, men);  // Sentencia simple - Salida de datos
	
	// Retorno de valor 0, indicando que el programa termin� correctamente
	return 0;  // Sentencia simple - Salida del programa
}  // Fin de la funci�n main

// Definici�n de la funci�n analiza, que recibe un entero y retorna si es primo o no
int analiza(int num) {  // Inicio de la funci�n analiza
	
	// Declaraci�n de variables enteras
	int pd, ret;  // Identificadores de variables de tipo entero
	
	// Inicializaci�n del divisor potencial (pd) en 2
	pd = 2;  // Sentencia simple - Asignaci�n de valor a una variable
	
	// Ciclo que verifica si num es divisible por alg�n n�mero entre 2 y num/2
	while (pd <= num / 2 && num % pd != 0)  // Sentencia compuesta - Estructura de control de repetici�n
		pd++;  // Sentencia simple - Incremento del divisor potencial
	
	// Verificaci�n final para determinar si num es primo
	if (pd > num / 2 && num != 1)  // Sentencia compuesta - Estructura de control de selecci�n
		ret = 1;  // Sentencia simple - Asignaci�n de valor a la variable de retorno (es primo)
	else  // Sentencia compuesta - Estructura de control alternativa
		ret = 0;  // Sentencia simple - Asignaci�n de valor a la variable de retorno (no es primo)
	
	// Retorno del valor que indica si num es primo o no
	return ret;  // Sentencia simple - Salida de la funci�n
}  // Fin de la funci�n analiza
