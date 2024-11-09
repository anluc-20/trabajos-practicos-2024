#include <stdio.h>
#include <stdint.h>	

void modificarFloat(float original) {

	uint32_t *num_as_int = (uint32_t *)&original;
	
	// Extracción de partes del número
	uint32_t sign = (*num_as_int >> 31) & 0x1;
	uint32_t exponent = (*num_as_int >> 23) & 0xFF;
	uint32_t mantissa = *num_as_int & 0x7FFFFF;
	
	printf("Original: %f\n", original);
	printf("Signo: %u, Exponente: %u, Mantisa: %u\n", sign, exponent, mantissa);
	
	// Modificar el exponente
	exponent += 10; // Aumentar el exponente en 1 (equivalente a multiplicar por 2)
	
	// Reconstruir el número con el nuevo exponente
	*num_as_int = (sign << 31) | (exponent << 23) | mantissa;
	printf("Modificado: %f\n", original);
}

int convertirRealAEntero(float numeroPositivo) {
	int cont=0, entero;
	int aux = numeroPositivo;
	printf("\nfloat : %f",numeroPositivo);
	while(aux!=0) {
		aux /= 10;
		cont++;
	}
	
	cont = 7-cont;
	
	for(int i = 0; i<cont; i++) {
		numeroPositivo *= 10.0;
		printf("\nfloat : %f",numeroPositivo);
	}
	
	entero = numeroPositivo;
	return entero;
}

int main() {
	int n, npares=0;
	float promedio = 0, numero;
	
	printf("Ingrese la cantidad de numeros: ");
	scanf("%d",&n);
	
	for(int i = 0; i<n; i++) {
		int digito, aux, band = 0;

		printf("Ingrese un numero: ");
		scanf("%f",&numero);

		aux = convertirRealAEntero(numero);
		modificarFloat(numero);
		
		printf("aux: %d",aux);
		
		if(numero < 0)
			aux = -numero;
		else
			aux = numero;
		
		
		
		if(numero==0) {
			npares++;
			continue;	
		}		
		
		
		while((aux != 0)&(band==0)) {
			digito = aux%10;
			aux = aux/10;
			printf("digito: %d",digito);
			if((digito%2)!=0)
				band = 1;
		}
		
		if(band==0) {
			promedio += numero;
			npares++;
			printf("sume al promedio: %f",numero);
		}
		
	}
	if(npares>0)
		promedio /= npares;
	
	printf("\nEl promedio de numeros con digitos pares es: %f", promedio);
	
	
	return 0;
}

