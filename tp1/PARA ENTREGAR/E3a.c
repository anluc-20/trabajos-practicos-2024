#include<stdio.h>

/*Dado el lado mayor y el lado menor
de un rectángulo, mostrar su
perímetro y su superficie.*/
int main(){

    int ladoMayor, ladoMenor;
    printf("ingrese lado mayor: ");
    scanf("%d", &ladoMayor);
    printf("ingrese lado menor: ");
    scanf("%d", &ladoMenor);
    
    int perimetro=2*ladoMayor+2*ladoMenor, area=ladoMayor*ladoMenor;
    
    printf("perimetro: %d \narea: %d", perimetro, area);
    
    return 0;
}