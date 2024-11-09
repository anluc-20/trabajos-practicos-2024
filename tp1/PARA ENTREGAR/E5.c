#include<stdio.h>

//Calcular la cantidad de horas, minutos y segundos que existen en una cantidad de segundos ingresada por el usuario. 
int main()
{
    int segundosE, segundosRes, horas, minutos;
    printf("Ingrese segundos: ");
    scanf("%d", &segundosE);
    
    horas=segundosE/3600;
    segundosRes=segundosE%3600;
    minutos=segundosRes/60;
    segundosRes=segundosE%60;
    
    printf("horas: %d, minutos: %d, segundos: %d",horas,minutos,segundosRes);
    return 0;
}