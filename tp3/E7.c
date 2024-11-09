#include <stdio.h>

/*
Problema:
	Diseñe un programa que permita el ingreso de N fracciones de la forma (A/B) y muestre la
	mayor y la menor de ellas, indicando además su expresión irreductible. 

DE:
	la cantidad de fracciones -> N
	la fraccion -> A/B

DS:
	la mayor fraccion y su expresion irreductible 
	la menor fraccion y su expresion irreductible 

Caso de prueba 1:

	Entrada: N=4, (A,B)= (2,6),(4,2),(5,1),(10,3)
	Salida: mayor = (5,1), irreductible = (5,1), menor = (2,6), irreductible = (1,3)

Caso de prueba 2:

	Entrada: N = 3, (A,B) = (1,2), (3,4), (5,10)
	Salida: mayor = (3,4), irreductible = (3,4), menor = (1,2), irreductible = (1,2)

Caso de prueba 3:

	Entrada: N = 5, (A,B) = (8,12), (7,14), (3,9), (6,18), (4,16)
	Salida: mayor = (8,12), irreductible = (2,3), menor = (4,16), irreductible = (1,4)

Caso de prueba 4:

	Entrada: N = 2, (A,B) = (11,13), (22,26)
	Salida: mayor = (11,13), irreductible = (11,13), menor = (22,26), irreductible = (11,13)

Caso de pruba 5:

	Entrada: N = 4, (A,B) = (-3,4), (6,-8), (2,-3), (4,5)
	Salida: mayor = (4,5), irreductible = (4,5), menor = (-3,4), irreductible = (-3,4)

Tareas: 
	Ingresar N, A, B
	
	Determinar si es la primera fraccion
	Si
		Guardar en mayor, la fraccion como decimal y en  Amay, Bmay sus partes
		Guardar en menor, la fraccion como decimal y en  Amen, Bmen sus partes
	Determinar si fraccion > mayor
	Si 	
		Guardar en mayor, la fraccion como decimal y en  Amay, Bmay sus partes
		
	Determinar si A/B es menor que menor
	Si 	
		Guardar en menor, la fraccion como decimal y en  Amen, Bmen sus partes

	Mostrar mayor y menor, y tambien sus expresiones irreductibles
*/
void obtenerIrreductible(int, int, int*, int*);
void ingresoEntero(const char* mensaje, int* salida);
int abs(int);

int main() {
	int n, a, b, aMay, bMay, aMen, bMen, aIrr, bIrr;
	double mayor, menor, fraccion;
	while (1) {
		ingresoEntero("ingrese n: ", &n);
		for(int i = 0; i<n; i++) {
			ingresoEntero("ingrese A: ", &a);
			ingresoEntero("ingrese B: ", &b);
			fraccion = (double)a/b;
			if(i == 0) {
				mayor = fraccion;
				aMay = a;
				bMay = b;
				menor = fraccion;
				aMen = a;
				bMen = b;
			}
			if(fraccion > mayor) {
				mayor = fraccion;
				aMay = a;
				bMay = b;
			}
			if(fraccion < menor) {
				menor = fraccion;
				aMen = a;
				bMen = b;
			}	
		}
		obtenerIrreductible(aMay, bMay, &aIrr, &bIrr);
		printf("mayor: %d/%d, irreductible: %d/%d\n", aMay, bMay, aIrr, bIrr);
		obtenerIrreductible(aMen, bMen, &aIrr, &bIrr);
		printf("menor: %d/%d, irreductible: %d/%d\n", aMen, bMen, aIrr, bIrr);
	}
	return 0;
}
void obtenerIrreductible(int a, int b, int* ar, int* br) {
	int menor, i, signo;
	signo = a * b;
	
	*ar = abs(a);
	*br = abs(b);
	
	if(*ar%b == 0) {
		*ar = *ar / *br;
		*br = 1;
		if(signo<0)
			*ar = -(*ar);
		return;
	}
	if(b%a == 0) {
		*br = *br / *ar;
		*ar = 1;
		if(signo<0)
			*ar = -(*ar);
		return;
	}
	
	menor = ((a<b? a : b)/2)+1;
	
	i = 2;
	
	while(i < menor) {
		if((*ar%i == 0)&&(*br%i==0))
		{
			*ar/=i;
			*br/=i;
			menor=(menor/i)+1;
			i=1;
		}
		i++;
	}
	
	if(signo<0)
		  *ar = -*ar;
}
int abs(int x) {
	return x>0? x :-x;
}
void ingresoEntero(const char* mensaje, int* salida) {
	printf("%s",mensaje);
	scanf("%d",salida);
}

