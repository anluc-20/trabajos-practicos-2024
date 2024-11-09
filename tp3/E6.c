#include <stdio.h>
#include <math.h>

/*
Problema:
	Dados N números reales, con 4 dígitos decimales de precisión, cree un programa que, para
	cada número real, cambie cada uno de sus dígitos impares por el dígito par anterior. Ejemplo A= 741,3478
	entonces modificado A= 640,2468 
Caso de prueba 1:

	Entrada: N = 4, X = 1.2345, 2.3456, 3.4567, 4.5678;
	Salida: X = 0.2244, 2.2446, 2.4466, 4.4668;

Caso de prueba 2:

	Entrada: N = 3, X = 5.6789, 6.7890, 7.8901
	Salida: X = 4.6688, 6.6880, 6.8800

Caso de prueba 3:

	Entrada: N = 2, X = 9.1234, 0.2468
	Salida: X = 8.0224, 0.2468

Caso de prueba 4:

	Entrada: N = 3, X = 2.1357, 4.5791, 6.9135
	Salida: X = 2.0246, 4.4680, 6.8024

Caso de prueba 5:

	Entrada: N = 1, X = 8.0001
	Salida: X = 8.0000

Tareas:
	Ingresar X
	Separar X en su parte entera y decimal
	Convertir digitos impares en su anterior par
	Juntar parte entera y decimal
	Mostrar x

Convertir digitos impares en su anterior par
	Ingresar X
	Asignar resultado = 0
	Asignar exponente = 0
	Separar digitos
		Determinar si digito es impar
		Si	
			Asignar digito = digito - 1
		Asignar resultado = resultado + digito * 10^exponente
		Asignar exponente = exponente + 1
	Devolver resultado
		
*/

void separarDecimales(double, int, int*, int*);
int reducirDigitosImpares(int);

int main() {
	int n, xEnt, xDec;
	double x, resultado;
	while(1) {
		printf("ingrese n: ");
		scanf("%d", &n);
		for(int i = 0; i<n; i++) {
			printf("\ningrese x: ");
			scanf("%lf",&x);
			separarDecimales(x, 4, &xEnt, &xDec);
			xEnt = reducirDigitosImpares(xEnt);
			xDec = reducirDigitosImpares(xDec);
			resultado = xEnt + ((double)xDec)/10000;
			printf("resultado: %lf\n", resultado);
		}	
	}
	return 0;
}

void separarDecimales(double x, int espaciosDecimales, int* parteEntera, int* parteDecimal) {
	double dec, ent;
	dec = modf(x,&ent);
	*parteEntera = ent;
	*parteDecimal = round(dec*pow(10,espaciosDecimales));
}
int reducirDigitosImpares(int numero) {
	int resultado = 0, exponente = 1;
	int aux, dig;
	aux = numero>0? numero : -numero;
	while(aux != 0) {
		dig = aux%10;
		aux = aux/10;
		if(dig%2!=0)
			dig--;
			
		
		resultado = resultado + dig*exponente;
		exponente *= 10;
	}
	return resultado;
}

