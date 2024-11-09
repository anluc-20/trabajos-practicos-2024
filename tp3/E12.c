#include <stdio.h>

/*

Una agencia espacial transmite y recibe mensajes con sus satélites mediante una serie de
bits (0 o 1), Como estos mensajes son números grandes, requieren ser codificados para que viajen por el
espacio. La codificación consiste en reemplazar grupos de bits de un mismo valor por la cantidad de bits
de cada grupo, seguida del valor del bit. Por ejemplo, si el número es = (11000011111) su codificación
resulta: (214051). Cuando la agencia recibe un mensaje codificado hace el proceso inverso para descubrir
el mensaje original.
Se pide crear un programa para que, mediante un menú de opciones, la agencia pueda enviar o recibir
mensajes. Realizar la validación del mensaje a enviar, es decir, que sea efectivamente un número con
sólo unos y ceros.
Al realizar la codificación o decodificación correspondientes se debe reemplazar el mensaje según
corresponda.
Nota: Asumir que los números binarios a codificar siempre empiezan en 1. Utilizar, de entre los tipos de
datos enteros, el que permita el mayor rango para representar el número binario y su codificación. Hacer
pruebas con números no muy grandes pues de otra manera la memoria se desbordará. Más adelante se
podrán utilizar otros tipos de datos que permitan una mejor solución al problema. 


*/
int mensajeEsValido(long long mensaje);
long long codificar(long long binario);
long long decodificar(long long codificado);
void ingresoLL(const char*,long long*);
void ingresoEntero(const char*, int*);
int abs(int);

int main() {
	long long mensaje;
	int opcion;
	printf("Seleccione una opcion:\n1. Enviar mensaje\n2. Recibir mensaje\n");
	while(1) {
		ingresoEntero("ingrese opcion: ", &opcion);
		if((opcion>2)||(opcion<1)) {
			printf("Opcion invalida\n");
			continue;
		}
		
		while(opcion==1) {
			ingresoLL("ingrese mensaje sin codificar: ", &mensaje);
			if(!mensajeEsValido(mensaje)) {
				printf("El mensaje solo debe contener unos y ceros\n");
				continue;
			}
			
			printf("El mensaje codificado es: %I64d\n", codificar(mensaje));
			break;
		}
		while(opcion==2) {
			ingresoLL("ingrese mensaje codificado: ", &mensaje);
			
			printf("El mensaje decodificado es: %I64d\n", decodificar(mensaje));
			break;
		}
	}
	
	return 0;
}


int abs(int x) {
	return x>0? x :-x;
}
void ingresoLL(const char* mensaje, long long* salida) {
	printf("%s",mensaje);
	scanf("%I64d",salida);
}
void ingresoEntero(const char* mensaje, int* salida) {
	printf("%s",mensaje);
	scanf("%d",salida);
}
long long codificar(long long binario) {
	long long resultado =0, mult = 1, aux = binario;
	int dig, num = 0, count = 0;
	
	while(aux!=0) {
		dig = aux%10;
		aux = aux/10;
		
		if(count==0) { //Esto sucede solo en la primera iteracion
			num = dig;
			count++;
			continue;
		}
		
		if((dig!=num)) { //cuando el digito cambia, toca guardar en resultado
			resultado += (count*10 + num)*mult;
			mult *= 100;
			count = 0;
			num = dig;
		}
		count++; //En una iteracion normal solo hay que contar
	}
	resultado += (count*10 + num)*mult;
	
	return resultado;
}

long long decodificar(long long codificado) {
	long long resultado = 0, mult = 1, aux = codificado;
	int n = 0, num = 0;
	
	while(aux!=0) {
		num = aux%10;
		aux = aux/10;
		n = aux%10;
		aux = aux/10;
		
		for (int i= 0; i<n; i++) {
			resultado += num*mult;
			mult *= 10;
		}
		
	}
	
	return resultado;
}
int mensajeEsValido(long long mensaje) {
	int dig = 0;
	while(mensaje!=0) {
		dig = mensaje%10;
		mensaje = mensaje/10;
		
		if((dig!=0)&&(dig!=1)) {
			//printf("encontre un digito invalido: %d", dig);
			return 0;
		}
	}
	return 1;
}
