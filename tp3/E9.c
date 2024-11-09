#include <stdio.h>

/*
Problema:
	Dada una cantidad no determinada de números naturales, para cada número natural primo,
	calcular su número invertido y para cada número natural no primo (compuesto) modificarlo eliminando
	todos sus dígitos primos.

Caso de prueba 1:
	Número   Resultado
	45       compuesto 4
	57       compuesto 0
	12       compuesto 1
	1        compuesto 1
	7        7
	13       31

Caso de prueba 2:
	Número   Resultado
	8        compuesto 8
	29       92
	30       compuesto 0
	2        2
	17       71
	81       compuesto 81

Caso de prueba 3:
	123      compuesto 1
	345      compuesto 4
	567      compuesto 6
	89       98
	16       compuesto 16 
	20       compuesto 0

Caso de prueba 4:
	22       compuesto 0
	33       compuesto 0
	44       compuesto 44
	55       compuesto 0
	66       compuesto 66
	11       11
	19       91

Caso de prueba 5:
	14       compuesto 14
	15       compuesto 1
	21       compuesto 1
	37       73
	83       38
	91       compuesto 91
*/
int invertirNumero(int );
void ingresoEntero(const char*, int*);
int abs(int);
int esPrimo(int);
int eliminarDigitosPrimos(int);

int main() {
	int x;
	ingresoEntero("ingrese x: ", &x);
	while(x>0) {
		if(esPrimo(x))
			printf("x es primo, su invertido es: %d\n", invertirNumero(x));
		else	
			printf("x es compuesto, x sin digitos primos es: %d\n", eliminarDigitosPrimos(x));
		
		ingresoEntero("ingrese x: ", &x);
	}
	
	return 0;
}


int invertirNumero(int x) {
	int resultado = 0, aux, dig;
	aux = x>0 ? x : -x;
	
	while(aux != 0) {
		dig = aux%10;
		resultado = (resultado *10) + dig;
		aux = aux/10;
	}
	return x>0 ? resultado : -resultado;
}

int abs(int x) {
	return x>0? x :-x;
}
void ingresoEntero(const char* mensaje, int* salida) {
	printf("%s",mensaje);
	scanf("%d",salida);
}
int esPrimo(int x) {
	int divisores = 2, mitad = (x/2)+1, i = 2;
	while((divisores < 3)&&(i<mitad)) {
		if(x%i==0)
			divisores++;
		
		i++;
	}
	if(divisores>2||x==1)
		return 0;
	else
		return 1;
}

int eliminarDigitosPrimos(int x) {
	int dig, aux, resultado = 0, mult = 1;
	aux = abs(x);
	while(aux!=0) {
		dig = aux%10;
		aux = aux/10;
		
		if(!esPrimo(dig))
		{
			resultado += dig * mult;
			mult *= 10;
		}
	}
	return resultado;
}

