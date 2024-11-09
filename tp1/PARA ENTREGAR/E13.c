#include <stdio.h>

int main() {
	int n, numero, a, b, multiplosA=0, multiplosB=0;
	
	printf("Ingrese la cantidad de numeros enteros: ");
	scanf("%d",&n);
	
	printf("Ingrese a: ");
	scanf("%d",&a);
	
	printf("Ingrese b: ");
	scanf("%d",&b);
	
	
	
	for(int i = 0; i<n; i++) {
		int multA = 0, multB=0;
		printf("Ingrese un numero: ");
		scanf("%d",&numero);
		
		if(numero > 0) {
			if((numero%a)==0)
				multA=1;
			
			if((numero%b)==0)
				multB=1;
			
			if(multA&&!multB)
				multiplosA++;
			
			if(!multA&&multB)
				multiplosB++;
				
		}
	}
	
	printf("El numero %d, tiene %d multiplos naturales", a, multiplosA);
	printf("\nEl numero %d, tiene %d multiplos naturales", b, multiplosB);
	
	return 0;
}

