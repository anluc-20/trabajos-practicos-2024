#include<stdio.h>

//Dados tres números naturales que representan los ángulos internos de un triángulo, se pide determinar si el triángulo es Rectángulo (tiene un ángulo recto, de 90º), Obtusángulo (tiene un ángulo obtuso, más de 90º) o Acutángulo (tiene tres ángulos agudos, menos de 90º). Nota: Se debe chequear que la suma de los ángulos interiores sea 180° para procesar el pedido. 
int main()
{
    int a,b,c;
    
    printf("Ingrese a: ");
    scanf("%d",&a);
    
    printf("Ingrese b: ");
    scanf("%d",&b);
    
    printf("Ingrese c: ");
    scanf("%d",&c);
    
    
    if(((a+b+c)!=180)||(a<1||b<1||c<1))
    {
        printf("angulos no validos");
        return 0;
    }
    
    if(a==90||b==90||c==90)
    {
        printf("rectangulo");
    }
    if(a>90||b>90||c>90)
    {
        printf("obtusangulo");
    }
    if(a<90&&b<90&&c<90)
    {
        printf("acutangulo");
    }
    
    return 0;
}