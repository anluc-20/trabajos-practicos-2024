#include <stdio.h>

/*
Problema:
	Cree un programa que ingrese dos valor
	enteros A y B y que, a través de un menú,
	a) muestre el número invertido de A,
	b) muestre el invertido de B,
	c) modifique y muestre ambos números, dejando
	en A el mayor y en B el menor.
	Utilice, convenientemente, los módulos del ejercicio 2. 

Invertir x:
	Asignar resultado = 0
	Obtener el ultimo de digito de X
		Asignar a resultado = (resultado * 10) + digito
		Asignar a X = X / 10

Menu:
	Mostrar "ingrese a, b
	Ingresar a, b
	Mostrar opciones
	Mostrar "ingrese una opcion"
	Si la opcion no es valida Mostrar "opcion no valida, eliga una opcion valida"
	

///---A---///


	
*/
void calcularTiempo(int, int*, int*, int*);
void moverUltimaCifra(int*, int*);
void intercambiarValores(int*, int*);
int invertirNumero(int);

int main() {
	int opcion, a, b;
	printf("Ingrese a: \n");
	scanf("%d", &a);
	printf("Ingrese b: \n");
	scanf("%d", &b);
	printf("Eliga una opcion:\n1. muestre el número invertido de A\n2. muestre el invertido de B\n3. modifique y muestre ambos números, dejando en A el mayor y en B el menor.\n");
	while(1) {
		scanf("%d",&opcion);
		if((opcion>3)||(opcion<1)) {
			printf("Opcion invalida, ingrese una opcion valida: \n");
			continue;
		}
		
		switch(opcion) {
			case 1: 	
				printf("El numero invertido de A es: %d\n", invertirNumero(a));
				break;
			case 2: 	
				printf("El numero invertido de B es: %d\n", invertirNumero(b));
				break;
			case 3:
				if(b>a)
					intercambiarValores(&a,&b);
				printf("Ahora A vale: %d, y B vale: %d\n", a, b);
				break;
		}
	}
	
	return 0;
}

void calcularTiempo(int segundosIn, int* segundosOut, int* minutosOut, int* horasOut) {
	int resto;
	*horasOut = segundosIn/3600;
	resto = segundosIn%3600;
	*minutosOut = resto/60;
	resto = resto%60;
	*segundosOut = resto;
}

void moverUltimaCifra(int* a, int* b) {
	*b = (*b * 10) + *a % 10;
	*a = *a / 10;
}

void intercambiarValores(int* a, int* b) {
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
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

