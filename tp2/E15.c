#include <stdio.h>
/*
Problema
	Dada una lista de numeros naturales se solicita mostrar los numeros que estan 
	formados solo por digitos pares. Ademas, mostrar el menor y el mayor de estos 
	numero(de los que cumplen la condicion).

Datos de entrada:
	>1 lista de nros N -> X

Datos de salida:
	>Los X que esten formados unicamente por digitos pares
	>El mayor de los que cumplan la condicion
	>El menor de los que cumplan la condicion
	>1 mensaje -> "no hay numeros formados solo por digitos pares"

Casos de prueba 1
	Entrada: X = 1, 4, 28, 13, 22, 45, 67,[0]
	Salida: X = 4,28,22; Mayor = 28; Menor = 4;

Caso de prueba 2:
	Entrada: X = 89, 15, 33, 47, 123, 79,[0]
	Salida: X = Ninguno; Mensaje: "no hay numeros formados solo por digitos pares"

Caso de prueba 3:
	Entrada: X = 18, 284, 821, 76, 90, 47,[0]
	Salida: X = 284; Mayor = 284; Menor = 284;

Tareas:
	1) Ingresar X
	2) Determinar si X esta formado por digitos pares
		Si
			2.1) Mostrar X
			2.2) Determinar si Mayor NO ha sido inicializado
				Si
					2.2.1) Asignar X a Mayor
					2.2.2) Asignar X a Menor
			2.3) Determinar si X > Mayor
				Si
					Asignar X a Mayor
			2.4) Determinar si X < Menor
				Si
					Asignar X a Menor
		Ingresar X
				
	3) Determinar si Mayor ha sido inicializado
		Si 
			Mostrar Menor, Mayor
		No
			Mostrar "no hay numeros formados solo por digitos pares"


	Determinar si X esta formado solo por digitos pares
		Asignar band = 0
		Obtener los digitos de X
			Determinar si digito NO es par
			Si
				Asignar band = 1
				Romper el ciclo
		Determinar si band = 0
		Si
			X solo esta formado por digitos pares
		No
			X no esta formado solo por digitos pares
*/
int soloDigitosPares(int x);

int main() {
	int x;
	int mayor = 0, menor = 0;
	printf("Ingrese x: \n");
	scanf("%d", &x);
	while(x>0) {
		if(soloDigitosPares(x)==1) {
			printf("%d tiene solo digitos pares\n",x);
			if(mayor==0) {
				mayor = x;
				menor = x;
			}
			if(x > mayor)
				mayor = x;
			
			if(x < menor)
				menor = x;
		}
		scanf("%d", &x);
	}
	if(mayor!=0) {
		printf("Mayor: %d\n",mayor);
		printf("Menor: %d\n",menor);
	}
	else {
		printf("no hay numeros formados solo por digitos pares\n");
	}
	
	return 0;
}


int soloDigitosPares(int x) {
	int band = 1, aux = x;
	int dig;
	
	while(aux != 0) {
		dig = aux%10;
		aux = aux/10;
		if((dig%2)!=0) {
			band = 0;
			break;
		}
	}
	return band;
}
