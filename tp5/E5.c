#include <stdio.h>
#include <string.h>
#define T_MAX 30
#define ARR_MAX 20

typedef char String[T_MAX];

/*
Ejercicio 5: Se tiene una lista de N ciudades de la argentina que se desea ingresar, a continuación, se
solicita ordenar alfabéticamente la lista. A través de un menú, realizar las siguientes operaciones:
a) Mostrar cuántos nombres de ciudades están formadas con una misma vocal, como en el caso
de la ciudad “Salta”;
b) Dada una ciudad, determinar la posición en la que se encuentra dentro de la lista
c) Mostrar toda la lista. 
*/

void ingresar_cadenas(String *cadenas, int size);
void console_read(char *buffer, int max_size);
void ordenar_cadenas(String *cadenas, int size);
int comparar_palabras(char *a, char *b);
int vocales_uniformes(char *cadena);
int buscar_palabra(String *palabras, char *palabra, int size);
void mostrar_array_char(String *array, int size);
void menu(int *salir, String *ciudades, int size);
void mostrar_opciones();
void limpiar_entrada();


int main ()
{
        String ciudades[ARR_MAX];
        int n, salir = 0;
        printf("ingrese la cantidad de ciudades: ");
        scanf("%d", &n);
        limpiar_entrada();
        ingresar_cadenas(ciudades, n);
        ordenar_cadenas(ciudades, n);
        while (!salir)
                menu(&salir, ciudades, n);

        return 0;      
}
void menu(int *salir, String *ciudades, int size)
{
        char opcion, cant, indice;
        String ciudad;
        printf("\ningrese opcion: ");
        mostrar_opciones();
        scanf(" %c", &opcion);
        limpiar_entrada();
        while ((opcion > 99) && (opcion < 100)) {
                printf("opcion no valida, ingrese una opcion valida: \n");
                scanf("%c", &opcion);
                limpiar_entrada();
        }
        switch (opcion) {
                case 'a':
                        cant = 0;
                        for (int i = 0; i < size; i++)
                                if(vocales_uniformes(ciudades[i])) cant++;

                        printf("Hay %d palabras formadas por una misma vocal\n", cant);
                        break;
                case 'b':
                        printf("ingrese la ciudad a buscar: ");
                        console_read(ciudad, T_MAX);
                        indice = buscar_palabra(ciudades, ciudad, size);
                        if(indice != -1)
                                printf("la ciudad %s esta en el indice [%d]\n", ciudad, indice);
                        else
                                printf("la ciudad %s no se encuentra en la lista\n", ciudad);;
                        break;
                case 'c':
                        mostrar_array_char(ciudades, size);
                        break;
                case 'd':
                        printf("saliendo del programa");
                        *salir = 1;
                        break;
        }
}
void mostrar_opciones()
{
        printf("\na. Mostrar cuántos nombres de ciudades están formadas con una misma vocal\nb. Dada una ciudad, determinar la posición en la que se encuentra dentro de la lista\nc. Mostrar toda la lista\nd. salir\n");
}

void console_read(char *buffer, int max_size)
{       char c;
        int i = 0;

        while((i < max_size - 1) && ((c = getchar()) != EOF) && (c != '\n')) {      
                buffer[i] = c;
                i++;
        }
        buffer[i] = '\0';

        if((c != '\n') && (c != EOF))
                while (((c = getchar()) != '\n') && (c != EOF));
}
void limpiar_entrada()
{
        char c = getchar();
        if((c != '\n') && (c != EOF))
                while (((c = getchar()) != '\n') && (c != EOF)); 
}
void mostrar_array_char(String *array, int size) 
{
        for (int i = 0; i < size; i++) {
                printf("[%d/%d] = %s\n", i, size - 1, array[i]);
        }
}
void ingresar_cadenas(String *cadenas, int size)
{
        for (int i = 0; i < size; i++) {
                printf("[%d/%d] = ", i, size - 1);
                console_read(cadenas[i], T_MAX);
        }
}
void ordenar_cadenas(String *cadenas, int size)
{
        int j;
        int p_len, p_1_len, p_2_len;
        String aux;
        for (int i = 1; i < size; i++) {
                j = i - 1;
                p_1_len = strlen(cadenas[j]);
                p_2_len = strlen(cadenas[j+1]);
                p_len = p_1_len < p_2_len ? p_1_len : p_2_len;
                while ((j >= 0) && (strncmp(cadenas[j+1], cadenas[j], p_len) < 0)) {
                      strcpy(aux, cadenas[j]);
                      strcpy(cadenas[j], cadenas[j+1]);
                      strcpy(cadenas[j+1], aux);\
                      j--;
                }
        }
}
int buscar_palabra(String *palabras, char *palabra, int size)
{
        int p_len, p_1_len, p_2_len = strlen(palabra);
        for (int i = 0; i < size; i++) {
                p_1_len = strlen(palabras[i]);
                p_len = p_1_len < p_2_len ? p_1_len : p_2_len;
                if(strncmp(palabras[i], palabra, p_len) == 0) return i;
        }
        return -1;
}
int vocales_uniformes(char *cadena)
{
        int band = 0, i = 0;
        char c;
        while(cadena[i] != '\0')
        {
                
                if((cadena[i] == 'a') || (cadena[i] == 'e') || (cadena[i] == 'i') || (cadena[i] == 'o') || (cadena[i] == 'u')) {
                        if(band == 0) {
                                band = 1;
                                c = cadena[i];
                        }
                        if((band == 1) && (c != cadena[i]))
                                return 0;
                }
                
                i++;
        }

        return 1;
}