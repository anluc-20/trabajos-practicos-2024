#include <stdio.h>
#include <math.h>

/*

*/
void separarDecimales(double, int, int*, int*);

int main() {
	while (1) {
		double a;
		int aEnt = 0, aDec = 0;
		printf("Ingrese a: \n");
		scanf("%lf", &a);
	
		separarDecimales(a,4,&aEnt,&aDec);
		printf("aEnt = %d, aDec = %d\n", aEnt, aDec);
	}
	
	return 0;
}
void separarDecimales(double x, int espaciosDecimales, int* parteEntera, int* parteDecimal) {
	double dec, ent;
	dec = modf(x,&ent);
	*parteEntera = ent;
	*parteDecimal = round(dec*pow(10,espaciosDecimales));
}

