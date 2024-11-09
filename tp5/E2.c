#include <stdio.h>
#define T_MAX 6

typedef char String[T_MAX];
/*

Ejercicio 2: Crear un programa que permita ingresar y mostrar dos Cadenas en las variables llamadas
Pal y OPal. Utilizar la siguiente declaración para el tipo de dato cadena: typedef char TCad [6];
Resolver:
a) Utilizando las sentencias printf() y scanf()
b) Utilizando las sentencias gets() y puts().
Nota: Para probar el programa usar los siguientes textos: “Casa Blanca” y “hipopótamos”, en ese orden y
viceversa ¿cuáles problemas se pueden observar? 

*/

void mostrar_caracteres(char *string);
void ingreso_string(char *mensaje, char *salida);
void ingreso_string_alt(char *mensaje, char *salida);

int main() 
{
        String Palta, OPalta;
        //ingreso_string_alt("ingrese Palta: ", Palta);
        //ingreso_string_alt("ingrese OPalta: ", OPalta);
        ingreso_string("ingrese Palta: ", Palta);
        ingreso_string("ingrese OPalta: ", OPalta);
        puts(Palta);
        puts(OPalta);

        return 0;
}

void mostrar_caracteres(char *string)
{
        int i = 0;
        while (string[i] != '\0') {
                printf("%c\n", string[i]);
                i++;
        }
}
void ingreso_string(char *mensaje, char *string)
{
        printf("%s", mensaje);
        scanf("%s", string);
}
void ingreso_string_alt(char *mensaje, char *string)
{
        puts(mensaje);
        fgets(string, T_MAX, stdin);
}
