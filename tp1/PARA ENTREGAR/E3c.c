#include<stdio.h>

/*Dada la cantidad de horas que trabaja un obrero por día y el
 valor de la hora trabajada, indicar el importe que debe cobrar
  en el mes. Considerar que el mes
 tiene 30 días y que los días feriados y
  fines de semana se pagan como días laborales. */
int main(){

    float horas,precio;
    printf("ingrese las horas de trabajo por dia: ");
    scanf("%f", &horas);
    printf("ingrese el precio por hora: ");
    scanf("%f", &precio);
    
    float total=horas*precio*30;
    
    printf("salario: %f", total);
    
    return 0;
}