#include "cadena_r.h"

/*
-poner carácter de cierre si c es EOF \n o tamaño maximo alcanzado y aún no se ha pueste el caracter de cierre
-cargar cadena si no se ha puesto el carácter de cierre
-llamar cadena mientras c no es \n ni EOF
*/

void lee_cad(Cadena cadena, int indice)
{
        int c = getchar();


        if(((c == '\n') || (c == EOF) || (indice >= CAD_MAX_SIZE - 1)) && (indice != -1)) {
                cadena[indice] = '\0';
                indice = -1;
        }
        
        if(indice != -1) {
                cadena[indice] = c;
                indice++;
        }
        
        if((c != '\n') && (c != EOF))
                lee_cad(cadena, indice); 

        /*
         * el valor del indice nos indica como se debe
         * comportar la funcion.
         * ---indice != -1---
         *  significa que la funcion debe seguir cargando
         *  la cadena.
         * ---indice == -1---
         *  significa que la funcion ya no debe cargar la cadena
         *  pero aun debe limpiar la entrada.
         *
         */
}

void ingresar_cadena(Cadena cadena)
{
        lee_cad(cadena, 0);
}
void mostrar_cadena(Cadena cadena)
{
        printf("%s\n", cadena);
}
