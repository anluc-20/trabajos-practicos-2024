#include <stdio.h>

int main() {
	int n, edad, mayor=0, menor=0, promedio=0;
	
	printf("Ingrese la cantidad de deportistas: ");
	scanf("%d",&n);
	
	for(int i = 0; i<n; i++) {
		printf("Ingrese una edad: ");
		scanf("%d",&edad);
		
		if(mayor == 0) {
			mayor = edad;
			menor = edad;
		}

		if(edad > mayor)
		   mayor = edad;
		
		if(edad < menor)
			menor = edad;
		
		promedio += edad;
	}
	
	promedio /= n;
	printf("La edad promedio entera es: %d", promedio);
	printf("\nLa mayor edad es: %d", mayor);
	printf("\nLa menor edad es: %d", menor);
	
	return 0;
}

