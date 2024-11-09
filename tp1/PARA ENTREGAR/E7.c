#include<stdio.h>

//E7 Dadas las estaturas de tres personas, calcular la estatura promedio. (No utilizar ciclos) 
int main()
{
    int estatura1, estatura2, estatura3;
    printf("Ingrese estatura 1: ");
    scanf("%d",&estatura1);
    
    printf("Ingrese estatura 2: ");
    scanf("%d",&estatura2);
    
    printf("Ingrese estatura 3: ");
    scanf("%d",&estatura3);
    
    double promedio=(estatura1+estatura2+estatura3)/3;
    
    printf("estatura promedio: %lf",promedio);
    return 0;
}