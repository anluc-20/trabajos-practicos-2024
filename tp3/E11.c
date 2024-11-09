#include <stdio.h>

/*

Una persona que requiere registrarse en una app, debe elegir una contraseña de 6 dígitos,
todos distintos. Si el usuario ingresa un número con cifras repetidas, la app le advierte el error y le sugiere
una nueva clave, compuesta por las cifras no repetidas del número ingresado, a la que le agregan nuevos
dígitos sin repetir. Los dígitos se agregan siempre como cifra menos significativa. Diseñe e implemente
un programa modular, que reciba un número entero y lo modifique de acuerdo al criterio explicado
anteriormente.

Ejemplos: clave ingresada = 337498 clave sugerida = 374980 (una posible salida)
clave ingresada = 237744 clave sugerida = 237401 (una posible salida)
clave ingresada = 444444 clave sugerida = 401235 (una posible salida) 

*/
void ingresoEntero(const char*, int*);
void eliminarDigitosRepetidos(int, int*, int*, int*);
void llenarConCeros(int*, int);
int abs(int);

int main() {
	int n, x, resultado, tamanoObjetivo, i, cantidadDeDigitos;
	int digitosOcupados[9];
	
	
	ingresoEntero("ingrese n: ", &n);
	for(int j = 0; j<n; j++) {
		
		resultado = 0, tamanoObjetivo = 6, i = 0, cantidadDeDigitos = 0;
		llenarConCeros(digitosOcupados,9);
		
		ingresoEntero("ingrese x: ", &x);
		eliminarDigitosRepetidos(x, &resultado, digitosOcupados, &cantidadDeDigitos);
		printf("numero sin repetidos: %d\n", resultado);
		while(cantidadDeDigitos<tamanoObjetivo) {
			if(digitosOcupados[i]==0) {
				resultado = (resultado*10) + i;
				cantidadDeDigitos++;
			}
			i++;
		}
		printf("numero completado: %d\n", resultado);
	}
	
	
	return 0;
}


int abs(int x) {
	return x>0? x :-x;
}
void ingresoEntero(const char* mensaje, int* salida) {
	printf("%s",mensaje);
	scanf("%d",salida);
}

void eliminarDigitosRepetidos(int x, int* resultado, int* digitosOcupados, int* cantidadDeDigitos) {
	int dig, aux, mult = 1;
	
	aux = abs(x);
	while(aux!=0) {
		dig = aux%10;
		aux = aux/10;
		
		if(digitosOcupados[dig]==0)
		{
			*resultado += dig * mult;
			mult *= 10;
			*cantidadDeDigitos = *cantidadDeDigitos+1;
		}
		digitosOcupados[dig]=1;
	}
}
void llenarConCeros(int* array, int size) {
	for(int i = 0; i<size; i++)
		array[i] = 0;
}
