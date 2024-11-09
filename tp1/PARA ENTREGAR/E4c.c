#include <stdio.h>  // Inclusión de la biblioteca estándar de entrada/salida

// Función principal del programa
int main() {  // Inicio de la función main
	
	// Declaración de variables enteras
	int x, aux, s, d, b, c;  // Identificadores de variables de tipo entero
	
	// Inicialización de la variable contadora c
	c = 0;  // Sentencia simple - Asignación de valor a una variable
	
	// Solicitud de un número natural al usuario
	printf("\n ingrese natural");  // Sentencia simple - Salida de datos
	
	// Lectura de la entrada del usuario y asignación a la variable x
	scanf("%d", &x);  // Sentencia simple - Entrada de datos
	
	// Ciclo principal que se ejecuta mientras x sea mayor que 0
	while (x > 0) {  // Sentencia compuesta - Estructura de control de repetición
		
		aux = x;  // Sentencia simple - Asignación de valor a una variable
		s = 0;  // Sentencia simple - Inicialización de la variable suma
		
		// Ciclo que calcula la suma de los dígitos del número
		while (x != 0) {  // Sentencia compuesta - Estructura de control de repetición
			d = x % 10;  // Sentencia simple - Asignación de valor a una variable (obtención del último dígito)
			s = s + d;  // Sentencia simple - Suma acumulativa de los dígitos
			x = x / 10;  // Sentencia simple - Reducción del número (eliminar el último dígito)
		}
		
		x = aux;  // Sentencia simple - Restauración del valor original de x
		b = 0;  // Sentencia simple - Inicialización de la variable bandera
		
		// Ciclo que verifica si algún dígito no divide a la suma s
		while ((x != 0) && (b == 0)) {  // Sentencia compuesta - Estructura de control de repetición
			d = x % 10;  // Sentencia simple - Obtención del último dígito
			
			// Verificación de divisibilidad
			if (d != 0 && s % d != 0)  // Sentencia compuesta - Estructura de control de selección
				b = 1;  // Sentencia simple - Actualización de la variable bandera
			else  // Sentencia compuesta - Estructura de control alternativa
				x = x / 10;  // Sentencia simple - Reducción del número (eliminar el último dígito)
		}
		
		// Si todos los dígitos dividen a la suma, se incrementa el contador c
		if (b == 0)  // Sentencia compuesta - Estructura de control de selección
			c = c + 1;  // Sentencia simple - Incremento del contador
		
		// Solicitud de un nuevo número natural al usuario
		printf("\n ingrese natural");  // Sentencia simple - Salida de datos
		scanf("%d", &x);  // Sentencia simple - Entrada de datos
	}
	
	// Verificación final y salida de resultados
	if (c == 0)  // Sentencia compuesta - Estructura de control de selección
		printf("\n ninguno cumple");  // Sentencia simple - Salida de datos
	else  // Sentencia compuesta - Estructura de control alternativa
		printf("\n cumplen %d", c);  // Sentencia simple - Salida de datos
	
	// Retorno de valor 0, indicando que el programa terminó correctamente
	return 0;  // Sentencia simple - Salida del programa
}  // Fin de la función main

