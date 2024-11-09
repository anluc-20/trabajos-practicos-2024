#include <stdio.h>

int main() {
	int n, numero, npares=0;
	float promedio = 0;
	
	printf("Ingrese la cantidad de numeros: ");
	scanf("%d",&n);
	
	for(int i = 0; i<n; i++) {
		int digito, aux, band = 0;
		printf("Ingrese un numero: ");
		scanf("%d",&numero);
		
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
			
			if((digito%2)!=0)
				band = 1;
		}
		
		if(band==0) {
			promedio += numero;
			npares++;
		}
		
	}
	if(npares>0)
		promedio /= npares;
	
	printf("\nEl promedio de numeros con digitos pares es: %f", promedio);
	
	
	return 0;
}

