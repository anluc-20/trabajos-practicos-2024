#include <stdio.h>

int main() {
	int digito;
	
	printf("Ingrese un digito: ");
	scanf("%d",&digito);
	
	
	printf("Usted ingreso el digito: 9");
	switch(digito) {
		case 1: 	
			printf("uno");
			break;
		case 2: 	
			printf("dos");
			break;
		case 3: 	
			printf("tres");
			break;
		case 4: 	
			printf("cuatro");
			break;
		case 5: 	
			printf("cinco");
			break;
		case 6: 	
			printf("seis");
			break;
		case 7: 	
			printf("siete");
			break;
		case 8: 	
			printf("ocho");
			break;
		case 9: 	
			printf("nueve");
			break;
	}
	
	return 0;
}

