#include <stdio.h>   // Inclusión de la biblioteca estándar de entrada/salida
#include <stdlib.h>  // Inclusión de la biblioteca estándar de utilidades (para usar abs)

// Declaración del prototipo de la función may
int may(int num);  // Declaración de módulo (función) - Identificador de función

// Función principal del programa
int main() {  // Inicio de la función main
	
	// Declaración de variables enteras
	int i, n, x;  // Identificadores de variables de tipo entero
	
	// Solicitud de la cantidad de datos que se van a ingresar
	printf("Ingrese cantidad de datos: \n");  // Sentencia simple - Salida de datos
	
	// Lectura de la cantidad de datos (n) que se va a procesar
	scanf("%d", &n);  // Sentencia simple - Entrada de datos
	
	// Ciclo que se ejecuta n veces para procesar cada dato ingresado
	for (i = 1; i <= n; i++) {  // Sentencia compuesta - Estructura de control de repetición
		
		// Solicitud de un dato (número entero) al usuario
		printf("Ingrese un dato: \n");  // Sentencia simple - Salida de datos
		
		// Lectura del dato ingresado por el usuario
		scanf("%d", &x);  // Sentencia simple - Entrada de datos
		
		// Llamada a la función may para obtener el dígito mayor del número
		// y mostrar el resultado al usuario
		printf("Digito mayor: %d\n", may(x));  // Sentencia de estructura - Llamada a función y salida de datos
	}
	
	// Retorno de valor 0, indicando que el programa terminó correctamente
	return 0;  // Sentencia simple - Salida del programa
}  // Fin de la función main

// Definición de la función may, que recibe un entero y retorna el dígito mayor
int may(int num) {  // Inicio de la función may
	
	// Declaración de variables enteras
	int d, my = -1;  // Identificadores de variables de tipo entero
	
	// Obtención del valor absoluto de num (en caso de que sea negativo)
	num = abs(num);  // Sentencia simple - Asignación de valor a una variable (uso de la función abs)
	
	// Ciclo que recorre cada dígito del número
	while (num != 0) {  // Sentencia compuesta - Estructura de control de repetición
		
		d = num % 10;  // Sentencia simple - Obtención del último dígito del número
		
		num = num / 10;  // Sentencia simple - Reducción del número (eliminar el último dígito)
		
		// Comparación para encontrar el dígito mayor
		if (d > my)  // Sentencia compuesta - Estructura de control de selección
			my = d;  // Sentencia simple - Actualización de la variable my
	}
	
	// Retorno del dígito mayor encontrado
	return my;  // Sentencia simple - Salida de la función
}  // Fin de la función may
