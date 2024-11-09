#include <stdio.h>

/*
Problema:
	Cree un programa que ingrese una fracción de la forma A/B y que a continuación devuelva
	la fracción irreductible equivalente. ejemplo se A= 6 y B= 8; ( 6 / 8 )entonces Ar= 3 y Br= 4 ( 3 / 4 )
	Nota: Generar un procedimiento que reciba A y B, que devuelva Ar y Br

Casos de prueba 1:
	Entrada: A = 4, B = 8;
	Salida: Ar = 1, Br = 2;

Caso de prueba 2:

	Entrada: A = 10, B = 15
	Salida: Ar = 2, Br = 3

Caso de prueba 3:

	Entrada: A = 100, B = 25
	Salida: Ar = 4, Br = 1

Caso de prueba 4:

	Entrada: A = 7, B = 49
	Salida: Ar = 1, Br = 7

Caso de prueba 5:

	Entrada: A = 22, B = 8
	Salida: Ar = 11, Br = 4

Reducir fraccion:
	Determinar si A mod B es 0
		Si
			Asignar Ar = A/B;
			Asignar Br = 1;
			Retornar;
	Determinar si B mod A es 0
		Si
			Asignar Ar = 1;
			Asignar Br = B/A;
			Retornar;
	Asignar Ar = A y Br = B
	Asignar a menor el menor entre A y B
	Asignar I = 2
	Mientras que I < menor/2
		Determinar si Ar mod I == 0 y Br mod I == 0
		Si
			Asignar Ar /= I
			Asignar Br /= I
			Asignar menor /= I
			Asignar I = 1;
		I++
		
	
*/
void obtenerIrreductible(int, int, int*, int*);
int abs(int);
int main() {
	while (1) {
		int a, b, ar = 0, br = 0;
		printf("Ingrese a: \n");
		scanf("%d", &a);
		printf("Ingrese b: \n");
		scanf("%d", &b);
		
		obtenerIrreductible(a,b,&ar,&br);
		printf("ar = %d, br = %d\n", ar, br);
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

