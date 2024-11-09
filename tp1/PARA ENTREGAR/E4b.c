#include <stdio.h>  // Inclusión de la biblioteca estándar de entrada/salida

// Declaración del prototipo de la función mes
void mes(int m);  // Declaración de módulo (función) - Identificador de función

// Función principal del programa
int main(void) {  // Inicio de la función main
	
	// Declaración de variables enteras para el día, mes y año
	int d, m, a;  // Identificadores de variables de tipo entero
	
	// Solicitud de la fecha al usuario
	printf("ingrese fecha: ");  // Sentencia simple - Salida de datos
	
	// Lectura de la entrada del usuario y asignación a las variables correspondientes
	scanf("%d", &d);  // Sentencia simple - Entrada de datos
	scanf("%d", &m);  // Sentencia simple - Entrada de datos
	scanf("%d", &a);  // Sentencia simple - Entrada de datos
	
	// Impresión del día ingresado por el usuario
	printf("\n%d de ", d);  // Sentencia simple - Salida de datos
	
	// Llamada a la función mes para imprimir el nombre del mes
	mes(m);  // Sentencia de estructura - Llamada a función
	
	// Impresión del año ingresado por el usuario
	printf(" de %d", a);  // Sentencia simple - Salida de datos
	
	// Retorno de valor 0, indicando que el programa terminó correctamente
	return 0;  // Sentencia simple - Salida del programa
}  // Fin de la función main

// Definición de la función mes, que recibe un entero y muestra el nombre del mes correspondiente
void mes(int m) {  // Inicio de la función mes
	switch(m) {  // Sentencia compuesta - Estructura de control de selección múltiple
	case 1: printf("enero"); break;  // Sentencia simple - Salida de datos y finalización de caso
	case 2: printf("febrero"); break;  // Sentencia simple - Salida de datos y finalización de caso
	case 3: printf("marzo"); break;  // Sentencia simple - Salida de datos y finalización de caso
	case 4: printf("abril"); break;  // Sentencia simple - Salida de datos y finalización de caso
	case 5: printf("mayo"); break;  // Sentencia simple - Salida de datos y finalización de caso
	case 6: printf("junio"); break;  // Sentencia simple - Salida de datos y finalización de caso
	case 7: printf("julio"); break;  // Sentencia simple - Salida de datos y finalización de caso
	case 8: printf("agosto"); break;  // Sentencia simple - Salida de datos y finalización de caso
	case 9: printf("septiembre"); break;  // Sentencia simple - Salida de datos y finalización de caso
	case 10: printf("octubre"); break;  // Sentencia simple - Salida de datos y finalización de caso
	case 11: printf("noviembre"); break;  // Sentencia simple - Salida de datos y finalización de caso
	case 12: printf("diciembre"); break;  // Sentencia simple - Salida de datos y finalización de caso
	}  // Fin de la estructura switch
}  // Fin de la función mes

