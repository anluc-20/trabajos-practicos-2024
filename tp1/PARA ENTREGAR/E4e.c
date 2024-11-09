#include <stdio.h>  // Inclusión de la biblioteca estándar de entrada/salida

// Declaración del prototipo de la función analiza
int analiza(int num);  // Declaración de módulo (función) - Identificador de función

// Función principal del programa
int main() {  // Inicio de la función main
	
	// Declaración de variables enteras
	int x, may, men, b;  // Identificadores de variables de tipo entero
	
	// Inicialización de la variable bandera b
	b = 0;  // Sentencia simple - Asignación de valor a una variable
	
	// Solicitud de un número natural al usuario
	printf("Ingrese un número natural: \n");  // Sentencia simple - Salida de datos
	
	// Lectura del número ingresado por el usuario y asignación a la variable x
	scanf("%d", &x);  // Sentencia simple - Entrada de datos
	
	// Ciclo que se ejecuta mientras x sea mayor que 0
	while (x > 0) {  // Sentencia compuesta - Estructura de control de repetición
		
		// Verificación si el número es primo llamando a la función analiza
		if (analiza(x) == 1) {  // Sentencia compuesta - Estructura de control de selección
			
			// Si es la primera vez que se encuentra un primo
			if (b == 0) {  // Sentencia compuesta - Estructura de control de selección
				may = x;  // Sentencia simple - Asignación de valor a la variable mayor
				men = x;  // Sentencia simple - Asignación de valor a la variable menor
				b = 1;  // Sentencia simple - Actualización de la variable bandera
			} else {  // Sentencia compuesta - Estructura de control alternativa
				// Actualización del mayor primo encontrado
				if (may < x)  // Sentencia compuesta - Estructura de control de selección
					may = x;  // Sentencia simple - Asignación de valor a la variable mayor
				
				// Actualización del menor primo encontrado
				if (men > x)  // Sentencia compuesta - Estructura de control de selección
					men = x;  // Sentencia simple - Asignación de valor a la variable menor
			}
		}
		
		// Solicitud de un nuevo número natural al usuario
		printf("Ingrese un número natural: \n");  // Sentencia simple - Salida de datos
		scanf("%d", &x);  // Sentencia simple - Entrada de datos
	}
	
	// Verificación final y salida de resultados
	if (b == 0)  // Sentencia compuesta - Estructura de control de selección
		printf("\nNo se ingresaron primos");  // Sentencia simple - Salida de datos
	else  // Sentencia compuesta - Estructura de control alternativa
		printf("El mayor primo natural: %d, el menor primo natural es: %d", may, men);  // Sentencia simple - Salida de datos
	
	// Retorno de valor 0, indicando que el programa terminó correctamente
	return 0;  // Sentencia simple - Salida del programa
}  // Fin de la función main

// Definición de la función analiza, que recibe un entero y retorna si es primo o no
int analiza(int num) {  // Inicio de la función analiza
	
	// Declaración de variables enteras
	int pd, ret;  // Identificadores de variables de tipo entero
	
	// Inicialización del divisor potencial (pd) en 2
	pd = 2;  // Sentencia simple - Asignación de valor a una variable
	
	// Ciclo que verifica si num es divisible por algún número entre 2 y num/2
	while (pd <= num / 2 && num % pd != 0)  // Sentencia compuesta - Estructura de control de repetición
		pd++;  // Sentencia simple - Incremento del divisor potencial
	
	// Verificación final para determinar si num es primo
	if (pd > num / 2 && num != 1)  // Sentencia compuesta - Estructura de control de selección
		ret = 1;  // Sentencia simple - Asignación de valor a la variable de retorno (es primo)
	else  // Sentencia compuesta - Estructura de control alternativa
		ret = 0;  // Sentencia simple - Asignación de valor a la variable de retorno (no es primo)
	
	// Retorno del valor que indica si num es primo o no
	return ret;  // Sentencia simple - Salida de la función
}  // Fin de la función analiza
