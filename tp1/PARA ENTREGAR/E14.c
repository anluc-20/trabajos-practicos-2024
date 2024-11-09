#include <stdio.h>

int main() {
	int n, numero, n0=0, n1=0, n2=0, n3=0, n4=0, n5=0, n6=0, n7=0, n8=0, n9=0;
	int promedio0 = 0, promedio1 = 0, promedio2 = 0, promedio3 = 0, promedio4 = 0, promedio5 = 0, promedio6 = 0, promedio7 = 0, promedio8 = 0, promedio9 = 0;
	
	printf("Ingrese la cantidad de numeros enteros: ");
	scanf("%d",&n);
	
	for(int i = 0; i<n; i++) {
		int digito;
		printf("Ingrese un numero: ");
		scanf("%d",&numero);

		digito = numero%10;
		
		switch(digito) {
			case 0: 	
				promedio0 += numero;
				n0++;
				break;
			case 1: 	
				promedio1 += numero;
				n1++;
				break;
			case 2: 	
				promedio2 += numero;
				n2++;
				break;
			case 3: 	
				promedio3 += numero;
				n3++;
				break;
			case 4: 	
				promedio4 += numero;
				n4++;
				break;
			case 5: 	
				promedio5 += numero;
				n5++;
				break;
			case 6: 	
				promedio6 += numero;
				n6++;
				break;
			case 7: 	
				promedio7 += numero;
				n7++;
				break;
			case 8: 	
				promedio8 += numero;
				n8++;
				break;
			case 9: 	
				promedio9 += numero;
				n9++;
				break;
		}
	}
	if(n0 > 0)
		promedio0 /= n0;
	
	if(n1 > 0)
		promedio1 /= n1;
	
	if(n2 > 0)
		promedio2 /= n2;
	
	if(n3 > 0)
		promedio3 /= n3;
	
	if(n4 > 0)
		promedio4 /= n4;
	
	if(n5 > 0)
		promedio5 /= n5;
	
	if(n6 > 0)
		promedio6 /= n6;
	
	if(n7 > 0)
		promedio7 /= n7;
	
	if(n8 > 0)
		promedio8 /= n8;
	
	if(n9 > 0)
		promedio9 /= n9;
	
	printf("El promedio de numeros que terminan en 0 es: %d", promedio0);
	printf("\nEl promedio de numeros que terminan en 1 es: %d", promedio1);
	printf("\nEl promedio de numeros que terminan en 2 es: %d", promedio2);
	printf("\nEl promedio de numeros que terminan en 3 es: %d", promedio3);
	printf("\nEl promedio de numeros que terminan en 4 es: %d", promedio4);
	printf("\nEl promedio de numeros que terminan en 5 es: %d", promedio5);
	printf("\nEl promedio de numeros que terminan en 6 es: %d", promedio6);
	printf("\nEl promedio de numeros que terminan en 7 es: %d", promedio7);
	printf("\nEl promedio de numeros que terminan en 8 es: %d", promedio8);
	printf("\nEl promedio de numeros que terminan en 9 es: %d", promedio9);
	
	
	return 0;
}

