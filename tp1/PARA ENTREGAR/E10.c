#include <stdio.h>

int main() {
	int consumo;
	int valorBasico=1000, valorPorM3=1;
	int importe=0;
	
	printf("Ingrese consumo: ");
	scanf("%d",&consumo);
	
	importe = valorBasico;
	
	if(consumo >= 2000) {
		importe = importe + ((consumo-1000) * valorPorM3 * 2);
	}
	if((consumo>1000) & (consumo<2000)) {
		importe = importe + ((consumo-1000) * valorPorM3);
	}
	
	printf("El importe a pagar es: %d", importe);
	
	return 0;
}

