#include <stdio.h>
#include <string.h>
#include <time.h>
#define STR_MAX_SIZE 30
#define CHAR_ARR_MAX_SIZE 30

typedef char String[STR_MAX_SIZE];
typedef struct {
        String nombre;
        char char_array[CHAR_ARR_MAX_SIZE];
        int size;
} Conjunto;
/*
Ejercicio 12: Se desea crear un programa que permita realizar operaciones con dos conjuntos de letras.
El programa deberá inicializar ambos conjuntos como conjuntos vacíos y posteriormente presentar un
menú que permita:
a) Agregar un elemento a uno de los conjuntos, ingresando para ello el nombre del conjunto
b) Mostrar uno de los dos conjuntos
c) Mostrar el conjunto resultante de la unión de los dos conjuntos
d) Mostrar el conjunto resultante de la intersección de los dos conjuntos
e) Mostrar el conjunto resultante de la diferencia del primer conjunto con el segundo conjunto
f) Mostrar el conjunto resultante de la diferencia del primer conjunto con el segundo conjunto
Nota: La representación de cada conjunto se realizará mediante un registro con tres campos, donde un
campo será el nombre del conjunto, otro campo será el arreglo de los caracteres conteniendo los
elementos del conjunto y el tercer campo será el tamaño del arreglo. 
*/

void menu(int *salir, Conjunto *conjuntos, int size, Conjunto *conjuntoAux);
void reiniciar_conjunto(Conjunto *conjunto);
void agregar_elemento_a_conjunto(Conjunto *conjunto, char elemento);
int buscar_elemento_por_nombre(Conjunto *conjuntos, int size, String nombre);
void mostrar_conjunto(Conjunto *conjunto);
void unir_conjuntos(Conjunto *conjuntoA, Conjunto *conjuntoB, Conjunto *conjuntoC);
void intersectar_conjuntos(Conjunto *conjuntoA, Conjunto *conjuntoB, Conjunto *conjuntoC);
void restar_conjuntos(Conjunto *conjuntoA, Conjunto *conjuntoB, Conjunto *conjuntoC);

//utilidades
void console_read(char *buffer, int max_size);
void ingresar_texto(char *mensaje, char *cadena, int max_size);
void ingresar_entero(char *mensaje, int *salida);
void ingresar_char(char *mensaje, char *salida);
void limpiar_entrada();
int si_o_no();

int main()
{
        int n = 2, salida = 0;
        Conjunto conjuntos[n], conjuntoAux;
        reiniciar_conjunto(&conjuntos[0]);
        reiniciar_conjunto(&conjuntos[1]);

        ingresar_texto("ingrese el nombre del primer conjunto: ", conjuntos[0].nombre, STR_MAX_SIZE);
        ingresar_texto("ingrese el nombre del segundo conjunto: ", conjuntos[1].nombre, STR_MAX_SIZE);

        while (!salida) 
                menu(&salida, conjuntos, n, &conjuntoAux);

        return 0;
}

void menu(int *salir, Conjunto *conjuntos, int size, Conjunto *conjuntoAux)
{
        char opcion, elemento;
        int indice;
        String nombre;
        ingresar_char("eliga una opcion:\na) Agregar un elemento a uno de los conjuntos, ingresando para ello el nombre del conjunto\nb) Mostrar uno de los dos conjuntos\nc) Mostrar el conjunto resultante de la unión de los dos conjuntos\nd) Mostrar el conjunto resultante de la intersección de los dos conjuntos\ne) Mostrar el conjunto resultante de la diferencia del primer conjunto con el segundo conjunto\nf) Mostrar el conjunto resultante de la diferencia del primer conjunto con el segundo conjunto\ng) salir\nopcion: \n", &opcion);
        while((opcion < 'a') || (opcion > 'g'))
                ingresar_char("opcion invalida, por favor ingrese una opcion valida: ", &opcion);

        switch (opcion) {
                case 'a':
                        ingresar_texto("ingresar el nombre del conjunto a insertar: ", nombre, STR_MAX_SIZE);
                        indice = buscar_elemento_por_nombre(conjuntos, size, nombre);
                        if(indice != -1) {
                                printf("[entrando en modo insercion de elementos, escriba 0 para salir]\n");
                                ingresar_char("ingrese el elemento a insertar: ", &elemento);
                                while (elemento != '0') {
                                        agregar_elemento_a_conjunto(&conjuntos[indice], elemento);
                                        printf("se ha agregado el elemento '%c' al conjunto '%s'.\n", elemento, conjuntos[indice].nombre);
                                        ingresar_char("ingrese el elemento a insertar: ", &elemento);
                                }
                        } else {
                                printf("no se encontro el conjunto con el nombre dado\n");
                        }
                        break;
                        
                case 'b':
                        mostrar_conjunto(&conjuntos[si_o_no()]);
                        break;

                case 'c':
                        unir_conjuntos(&conjuntos[0], &conjuntos[1], conjuntoAux);
                        mostrar_conjunto(conjuntoAux);
                        break;

                case 'd':
                        intersectar_conjuntos(&conjuntos[0], &conjuntos[1], conjuntoAux);
                        mostrar_conjunto(conjuntoAux);
                        break;

                case 'e':
                        restar_conjuntos(&conjuntos[0], &conjuntos[1], conjuntoAux);
                        mostrar_conjunto(conjuntoAux);
                        break;

                case 'f':
                        restar_conjuntos(&conjuntos[1], &conjuntos[0], conjuntoAux);
                        mostrar_conjunto(conjuntoAux);
                        break;

                case 'g':
                        printf("saliendo...\n");
                        *salir = 1;
                        break;
        }
}
void reiniciar_conjunto(Conjunto *conjunto)
{
        conjunto->nombre[0] = '\0';
        conjunto->size = 0;
}
void agregar_elemento_a_conjunto(Conjunto *conjunto, char elemento)
{
        conjunto->char_array[conjunto->size] = elemento;
        conjunto->size++;
}
int buscar_elemento_por_nombre(Conjunto *conjuntos, int size, String nombre)
{
        int p_len, p_1_len, p_2_len;
        p_1_len  = strlen(nombre);
        for (int i = 0; i < size; i++) {
                p_2_len = strlen(conjuntos[i].nombre);
                p_len = p_1_len > p_2_len ? p_1_len : p_2_len;
                if(strncmp(conjuntos[i].nombre, nombre, p_len) == 0)
                        return i;
        }
        return -1;
}
void mostrar_conjunto(Conjunto *conjunto)
{
        printf("nombre: %s\n", conjunto->nombre);
        printf("elementos: ");
        for (int i = 0; i < conjunto->size; i++) {
                printf("%c, ", conjunto->char_array[i]);
        }
        printf("\n");
        printf("tamaño: %d\n", conjunto->size);
}
void unir_conjuntos(Conjunto *conjuntoA, Conjunto *conjuntoB, Conjunto *conjuntoC)
{
        reiniciar_conjunto(conjuntoC);
        for (int i = 0; i < conjuntoA->size; i++) {
                conjuntoC->char_array[i] = conjuntoA->char_array[i];
        }
        conjuntoC->size = conjuntoA->size;
        for (int i = 0; i < conjuntoB->size; i++) {
                conjuntoC->char_array[i+conjuntoC->size] = conjuntoB->char_array[i];
        }
        conjuntoC->size += conjuntoB->size;
}
void intersectar_conjuntos(Conjunto *conjuntoA, Conjunto *conjuntoB, Conjunto *conjuntoC)
{
        int band, j;
        Conjunto *mayor = conjuntoA, *menor = conjuntoB, *aux;
        if(conjuntoB->size > conjuntoA->size) {
                aux = mayor;
                mayor = menor;
                menor = aux;
        }
        reiniciar_conjunto(conjuntoC);

        for (int i = 0; i < menor->size; i++) {
                band = 1;
                j = 0;
                while ((j < mayor->size) && band) {
                        if(menor->char_array[i] == mayor->char_array[j]) {
                                conjuntoC->char_array[conjuntoC->size] = menor->char_array[i];
                                conjuntoC->size++;
                                band = 0;
                        } 
                        j++;          
                }
        }
}
void restar_conjuntos(Conjunto *conjuntoA, Conjunto *conjuntoB, Conjunto *conjuntoC)
{
        int j, band = 1;
        reiniciar_conjunto(conjuntoC);
        for (int i = 0; i < conjuntoA->size; i++) {
                j = 0;
                band = 1;
                while ((j < conjuntoB->size) && band) {
                        if(conjuntoA->char_array[i] == conjuntoB->char_array[j])
                                band = 0;
                        j++;          
                }
                if(band) {
                        conjuntoC->char_array[conjuntoC->size] = conjuntoA->char_array[i];
                        conjuntoC->size++;
                }
                        
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
int si_o_no()
{
        return time(NULL)%2;
}