#include<stdio.h>
#define PI 3.141592

/*Dado el radio de un círculo, mostrar su perímetro y su superficie*/
int main(){

    int radio;
    printf("ingrese el radio: ");
    scanf("%d", &radio);
    
    float perimetro=2*PI*radio;
    float area=PI*radio*radio;
    
    printf("perimetro: %f \narea: %f", perimetro, area);
    
    return 0;
}