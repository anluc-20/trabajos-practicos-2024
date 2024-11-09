#include <stdio.h>
typedef void (*MenuOption)(void*);
typedef struct {
        int elementos[30];
        int size;
} Lista;

void limpiar_entrada()
{
        char c = getchar();
        if((c != '\n') && (c != EOF))
                while (((c = getchar()) != '\n') && (c != EOF)); 
}
void ingresar_char(char *mensaje, char *salida)
{
        printf("%s", mensaje);
        scanf(" %c", salida);
        limpiar_entrada();
}
void menu(int *salir, MenuOption *opciones, void *param, int size, char *mensaje)
{
        char opcion, opcion_max = size + 97; //a es 97 en codigo ascii, al sumar 97 y el indice del ultimo elemento del array, obtenemos la letra correspondiente a ese indice. Por ejemplo si el indice es 4, obtendremos 'e'. Ademas, guardamos un espacio para la opcion salir
        int indice;
        ingresar_char(mensaje, &opcion);
        while ((opcion < 'a') || (opcion > opcion_max)) {
             ingresar_char("opcion invalida, por favor ingresar una opcion valida: ", &opcion);
        }
        indice = opcion - 97; //restamos 97 para ajustar la opcion a un indice valido del array. Por ejemplo si tenemos 'e' la resta sera 4, por lo que accederemos al cuarto elemento del array.
        if(indice == size)
                *salir = 1;
        else
                opciones[indice](param);
}

void mostrar_lista(void *lista_void)
{
        Lista *lista = lista_void;
        for (int i = 0; i < lista->size; i++) {
                printf("[%d/%d] = %d\n", i, lista->size - 1, lista->elementos[i]);
        }
}
void sumar_elementos_de_lista(void *lista_void)
{
        Lista *lista = lista_void;
        int resultado =  0;
        for (int i = 0; i < lista->size; i++) {
                resultado += lista->elementos[i];
        }
        printf("la suma es: %d\n", resultado);
}

int main()
{
        int salir = 0;
        Lista lista = {
                {34,23,12,1,7},
                5
        };
        MenuOption opciones[] = {
                mostrar_lista,
                sumar_elementos_de_lista
        };
        while(!salir)
                menu(&salir, opciones, &lista, 2, "a) mostrar lista\nb) sumar elementos\nc) salir.\nopcion: ");
        return 0;
}