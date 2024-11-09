#include <stdio.h>
#include <string.h>

#define STR_MAX_SIZE 30
#define PAIS_MAX_SIZE 30

typedef char String[STR_MAX_SIZE];

typedef struct {
        int codigo;
        String nombre;
        String capital;
        String continente;
}  Pais;
/*
Ejercicio 1: Crear un programa que permita el ingreso de una lista de N países, de cada País se guarda
la siguiente información: “Código del País, Nombre del país, Capital del país y Continente al que
pertenece.”
Se debe realizar la carga de la lista de países y posteriormente ordenar la lista por Código del país, luego
utilizando un menú poder realizar las siguientes operaciones:
a) Añadir un nuevo País preservando el orden.
b) Dado un Código de un país, modificar la Capital que se tiene registrada.
c) Dado un Código de un país, eliminar dicho registro.
d) Dada una Capital, mostrar el País al que pertenece. 
*/

void menu(int *salir, Pais **paises_p, int *size);

//opciones del menu
void agregar_pais_preservando_orden(Pais **paises_p, int *size);
void ingresar_codigo_y_modificar_capital(Pais **paises_p, int size);
void ingresar_codigo_y_eliminar_pais(Pais **paises_p, int *size);
void ingresar_capital_y_mostrar_pais(Pais **paises_p, int size);


//funciones y procedimientos
void ingresar_pais(Pais *pais);
void ordenar_paises_por_codigo(Pais **paises_p, int size);
void agregar_pais(Pais **paises_p, int *size, Pais *pais);
void modificar_capital(Pais *pais, String capital);
void eliminar_pais_por_indice(Pais **paises_p, int *size, int indice);
int buscar_pais_por_codigo(Pais **paises_p, int size, int codigo);
int buscar_pais_por_capital(Pais **paises_p, int size, String capital);
void mostrar_pais(Pais *pais);
void enlazar_paises_y_punteros(Pais *paises, Pais **punteros, int size);



//utilidades
void console_read(char *buffer, int max_size);
void ingresar_texto(char *mensaje, char *cadena, int max_size);
void ingresar_entero(char *mensaje, int *salida);
void ingresar_char(char *mensaje, char *salida);
void limpiar_entrada();

int main()
{
        int n, salida = 0;
        Pais paises[PAIS_MAX_SIZE];
        Pais *paises_p[PAIS_MAX_SIZE];

        enlazar_paises_y_punteros(paises, paises_p, PAIS_MAX_SIZE);

        ingresar_entero("ingrese la cantidad de paises: ", &n);
        for (int i = 0; i < n; i++) {
                printf("[%d/%d]\n", i, n - 1);
                ingresar_pais(&paises[i]);
        }

        ordenar_paises_por_codigo(paises_p, n);

        while (!salida) 
                menu(&salida, paises_p, &n);

        return 0;
}

void menu(int *salir, Pais **paises_p, int *size)
{
        char opcion;
        ingresar_char("a) Añadir un nuevo País preservando el orden.\nb) Dado un Código de un país, modificar la Capital que se tiene registrada.\nc) Dado un Código de un país, eliminar dicho registro.\nd) Dada una Capital, mostrar el País al que pertenece.\ne) mostrar lista de paises.\nf) salir\nopcion: \n", &opcion);
        while((opcion < 'a') || (opcion > 'g'))
                ingresar_char("opcion invalida, por favor ingrese una opcion valida: ", &opcion);

        switch (opcion) {
                case 'a':
                        agregar_pais_preservando_orden(paises_p, size);
                        
                        break;
                        
                case 'b':
                        ingresar_codigo_y_modificar_capital(paises_p, *size);
                        
                        break;

                case 'c':
                        ingresar_codigo_y_eliminar_pais(paises_p, size);

                        break;

                case 'd':
                        ingresar_capital_y_mostrar_pais(paises_p, *size);

                        break;
                
                case 'e':
                        for (int i = 0; i < *size; i++) {
                               printf("[%d/%d]\n", i, *size - 1);
                               mostrar_pais(paises_p[i]);
                        }
                        break;

                case 'f':
                        printf("saliendo...\n");
                        *salir = 1;
                        break;
        }
}

//opciones del menu
void agregar_pais_preservando_orden(Pais **paises_p, int *size)
{
        ingresar_pais(paises_p[*size]);
        printf("se ha agregado correctamente %s.\n", paises_p[*size]->nombre);
        *size += 1;
        ordenar_paises_por_codigo(paises_p, *size);
}
void ingresar_codigo_y_modificar_capital(Pais **paises_p, int size)
{
        int codigo, indice;
        String capital;
        ingresar_entero("ingrese el codigo del pais: ", &codigo);
        indice = buscar_pais_por_codigo(paises_p, size, codigo);
        if(indice != -1) {
                printf("ingrese la nueva capital de %s.\n", paises_p[indice]->nombre);
                ingresar_texto(NULL, capital, STR_MAX_SIZE);
                modificar_capital(paises_p[indice], capital);
                printf("se ha modificado correctamente la capital de %s.\n", paises_p[indice]->nombre);
        } else {
                printf("no se encontro el pais con dicho codigo.\n");
        }
}
void ingresar_codigo_y_eliminar_pais(Pais **paises_p, int *size)
{
        int codigo, indice;
        ingresar_entero("ingrese el codigo del pais: ", &codigo);
        indice = buscar_pais_por_codigo(paises_p, *size, codigo);
        if(indice != -1) {
                eliminar_pais_por_indice(paises_p, size, indice);
                printf("se ha modificado correctamente el pais con codigo %d.\n", codigo);
        } else {
                printf("no se encontro el pais con dicho codigo.\n");
        }
}
void ingresar_capital_y_mostrar_pais(Pais **paises_p, int size)
{
        int indice;
        String capital;
        ingresar_texto("ingrese la capital: ", capital, STR_MAX_SIZE);
        indice = buscar_pais_por_capital(paises_p, size, capital);
        if(indice != -1)
                mostrar_pais(paises_p[indice]);
        else
                printf("no se encontro el pais con dicha capital.\n");
}

//funciones y procedimientos
void ingresar_pais(Pais *pais)
{
        ingresar_entero("codigo: ", &pais->codigo);
        ingresar_texto("nombre: ", pais->nombre, STR_MAX_SIZE);
        ingresar_texto("capital: ", pais->capital, STR_MAX_SIZE);
        ingresar_texto("continente: ", pais->continente, STR_MAX_SIZE);
}
void ordenar_paises_por_codigo(Pais **paises_p, int size)
{
        int j;
        Pais *aux;
        for (int i = 1; i < size; i++) {
                j = i - 1;
                while ((j >= 0) && (paises_p[j+1]->codigo < paises_p[j]->codigo)) {
                        aux = paises_p[j+1];
                        paises_p[j+1] = paises_p[j];
                        paises_p[j] = aux;
                        j--;
                }
        }
}
void modificar_capital(Pais *pais, String capital)
{
        strcpy(pais->capital, capital);
}
void eliminar_pais_por_indice(Pais **paises_p, int *size, int indice)
{
        *size -= 1;
        for (int i = indice; i < *size; i++) {
                paises_p[i] = paises_p[i+1];
        }
}
int buscar_pais_por_codigo(Pais **paises_p, int size, int codigo)
{
        int inicio = 0, fin = size - 1, m = (inicio + fin) / 2;
        while ((inicio < fin) && (paises_p[m]->codigo != codigo)) {
                if(paises_p[m]->codigo > codigo)
                        fin = m - 1;
                else
                        inicio = m + 1;

                m = (inicio + fin) / 2;
        }
        if (paises_p[m]->codigo == codigo)
                return m;
        else
                return -1;
}
int buscar_pais_por_capital(Pais **paises_p, int size, String capital)
{
        for (int i = 0; i < size; i++) {
                if(strcmp(paises_p[i]->capital, capital) == 0)
                        return i;
        }
        return -1;
}
void mostrar_pais(Pais *pais)
{
        printf("codigo: %d\n", pais->codigo);
        printf("nombre: %s\n", pais->nombre);
        printf("capital: %s\n", pais->capital);
        printf("continente: %s\n", pais->continente);
}

void enlazar_paises_y_punteros(Pais *paises, Pais **punteros, int size)
{
        for (int i = 0; i < size; i++) {
                punteros[i] = &paises[i];
        }
}


//utilidades
void console_read(char *buffer, int max_size)
{
        char c;
        int i = 0;

        while((i < max_size - 1) && ((c = getchar()) != EOF) && (c != '\n')) {      
                buffer[i] = c;
                i++;
        }
        buffer[i] = '\0';

        if((c != '\n') && (c != EOF))
                while (((c = getchar()) != '\n') && (c != EOF));
}
void ingresar_texto(char *mensaje, char *cadena, int max_size)
{
        printf("%s", mensaje);
        console_read(cadena, max_size);
}
void ingresar_entero(char *mensaje, int *salida)
{
     printf("%s", mensaje);
     scanf("%d", salida);
     limpiar_entrada();
}
void ingresar_char(char *mensaje, char *salida)
{
        printf("%s", mensaje);
        scanf(" %c", salida);
        limpiar_entrada();
}
void limpiar_entrada()
{
        char c = getchar();
        if((c != '\n') && (c != EOF))
                while (((c = getchar()) != '\n') && (c != EOF)); 
}