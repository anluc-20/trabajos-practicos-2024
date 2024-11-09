#include <stdio.h>


/*
Problema:
	Dada una cantidad no determinada de fracciones, de la forma “A/B”, convertir cada fracción
	en irreductible e indicar si la fracción originalmente ingresada sufrió transformación.

Caso de prueba 1:

Entrada: (a,b) = (-1,2), (4,2), (3,2), (6,4), [0,0]
Salida:
		Original   Irreductible   Sufrió cambios?
		-1/2       -1/2           no
		4/2        2/1            sí
		3/2        3/2            no
		6/4        3/2            sí

Caso de prueba 2:

Entrada: (a,b) = (8,12), (10,5), (7,3), [0,0]
Salida:
		Original   Irreductible   Sufrió cambios?
		8/12       2/3            sí
		10/5       2/1            sí
		7/3        7/3            no

Caso de prueba 3:

Entrada: (a,b) = (1,1), [0,0]
Salida:
		Original   Irreductible   Sufrió cambios?
		1/1        1/1            no
Caso de prueba 4:

Entrada: (a,b) = (12,16), (25,50), (-14,7), (18,24), [0,0]
Salida:
		Original   Irreductible   Sufrió cambios?
		12/16      3/4            sí
		25/50      1/2            sí
		-14/7      -2/1           sí
		18/24      3/4            sí
Caso de prueba 5:

Entrada: (a,b) = (1,3), (5,7), (9,11), (3,5), [0,0]
Salida:
		Original   Irreductible   Sufrió cambios?
		1/3        1/3            no
		5/7        5/7            no
		9/11       9/11           no
		3/5        3/5            no
*/
void obtenerIrreductible(int, int, int*, int*);
void ingresoEntero(const char* mensaje, int* salida);
int abs(int x);

int main() {
	int a, b, aIrr = 0, bIrr = 0;
	ingresoEntero("ingrese a: ", &a);
	ingresoEntero("ingrese b: ", &b);
	while(b!=0) {
		obtenerIrreductible(a,b,&aIrr,&bIrr);
		printf("Original: %d/%d, Irreductible: %d/%d\n",a,b,aIrr,bIrr);
		
		printf("Sufrio cambios? ");
		if((a!=aIrr)||(b!=bIrr))
			printf("SI\n");
		else
			printf("NO\n");
	
		ingresoEntero("ingrese a: ", &a);
		ingresoEntero("ingrese b: ", &b);
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
void ingresoEntero(const char* mensaje, int* salida) {
	printf("%s",mensaje);
	scanf("%d",salida);
}
int abs(int x) {
	return x>0? x :-x;
}

