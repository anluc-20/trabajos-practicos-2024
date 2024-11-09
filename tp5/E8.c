#include <stdio.h>
#include <string.h>
#define STR_MAX_SIZE 30
typedef char String[STR_MAX_SIZE];

/*
Ejercicio 8: Se tienen la siguiente estructura para un inmueble: N° Catastro, Nombre del Propietario,
Calle y N°, Tipo (Terreno, Construcción, Edificado), Metros cuadrados de construcción, Cantidad de
baños, Cantidad de habitaciones.
Se solicita cargar 3 inmuebles y a través de un menú realizar las siguientes operaciones:
a) Mostrar los datos del inmueble con el mayor valor de metros cuadrados de construcción.
b) Ingresar un N° de Catastro y permitir modificar la información del registro.
c) Dado el Nombre del Propietario mostrar todos los inmuebles declarados. 
*/

typedef enum {
        TERRENO,
        CONSTRUCCION,
        EDIFICADO
} TipoInmueble;

typedef struct{
        String nombre;
        int numero;
} Calle;

typedef struct {
        int nro_catastro;
        String nombre_del_propietario;
        Calle calle;
        TipoInmueble tipo;
        int m2;
        int banos;
        int habitaciones;
} Inmueble;

void ingresar_inmueble(Inmueble *inmueble);
void ingresar_calle(Calle *calle);
void ingresar_tipo_inmueble(TipoInmueble *tipo);
void menu(int *salir, Inmueble *inmuebles, int size);
void mostrar_inmueble(Inmueble *inmueble);
void mostrar_calle(Calle *calle);
void mostrar_tipo_inmueble(TipoInmueble *tipo);
int obtener_indice_inmueble_mayor_m2(Inmueble *inmuebles, int size);
void console_read(char *buffer, int max_size);
void ingresar_texto(char *mensaje, char *cadena, int max_size);
void ingresar_entero(char *mensaje, int *salida);
void ingresar_char(char *mensaje, char *salida);
void limpiar_entrada();
int buscar_inmueble_por_catastro(Inmueble *inmuebles, int size, int nro_catastro);
void buscar_inmuebles_por_nombre(Inmueble *inmuebles, int size, String nombre, int *indices_inmuebles, int *indices_size);

int main()
{
        int n = 3, salida = 0;
        Inmueble inmuebles[n];
        for (int i = 0; i < n; i++) {
                printf("[%d/%d]\n", i, n - 1);
                ingresar_inmueble(&inmuebles[i]);
        }
        while (!salida) 
                menu(&salida, inmuebles, n);

        return 0;
}
void ingresar_inmueble(Inmueble *inmueble)
{
        printf("inmueble: \n");
        ingresar_entero("numero de catastro: ", &inmueble->nro_catastro);
        ingresar_texto("nombre del propietario: ", inmueble->nombre_del_propietario, STR_MAX_SIZE);
        ingresar_calle(&inmueble->calle);
        ingresar_tipo_inmueble(&inmueble->tipo);
        ingresar_entero("metros cuadrados: ", &inmueble->m2);
        ingresar_entero("banos: ", &inmueble->banos);
        ingresar_entero("habitaciones: ", &inmueble->habitaciones);
}
void ingresar_calle(Calle *calle)
{
        ingresar_texto("calle: ", calle->nombre, STR_MAX_SIZE);
        ingresar_entero("numero de calle: ", &calle->numero);
}
void ingresar_tipo_inmueble(TipoInmueble *tipo)
{
        int opcion;
        ingresar_entero("ingrese el tipo: \n1. Terreno\n2. Construccion\n3. Edificado\n", &opcion);
        while((opcion < 1) || (opcion > 3))
                ingresar_entero("opcion invalida, por favor ingrese una opcion valida: ", &opcion);

        switch(opcion)
        {
                case 1:
                        *tipo = TERRENO;
                        break;
                case 2:
                        *tipo = CONSTRUCCION;
                        break;
                case 3:
                        *tipo = EDIFICADO;
                        break;
        }
}
void menu(int *salir, Inmueble *inmuebles, int size)
{
        char opcion;
        int indice, nro_catastro, indices_inmuebles[20], indices_size = 0;
        String nombre;
        ingresar_char("eliga una opcion:\na) Mostrar los datos del inmueble con el mayor valor de metros cuadrados de construcción.\nb) Ingresar un N° de Catastro y permitir modificar la información del registro.\nc) Dado el Nombre del Propietario mostrar todos los inmuebles declarados.\nd) salir.\nopcion: \n", &opcion);
        while((opcion < 'a') || (opcion > 'd'))
                ingresar_char("opcion invalida, por favor ingrese una opcion valida: ", &opcion);

        switch (opcion) {
                case 'a':
                        indice = obtener_indice_inmueble_mayor_m2(inmuebles, size);
                        printf("el inmueble con mayor metros cuadrados es: \n");
                        mostrar_inmueble(&inmuebles[indice]);
                        break;
                        
                case 'b':
                        ingresar_entero("ingres el numero de catastro: ", &nro_catastro);
                        indice = buscar_inmueble_por_catastro(inmuebles, size, nro_catastro);
                        if(indice != -1) {
                                printf("modificando inmueble...\n");
                                ingresar_inmueble(&inmuebles[indice]);
                        } else {
                                printf("no se encontro el inmueble, con el numero de catastro solicitado\n");
                        }
                        break;

                case 'c':
                        ingresar_texto("ingrese el nombre del propietario: ", nombre, STR_MAX_SIZE);
                        buscar_inmuebles_por_nombre(inmuebles, size, nombre, indices_inmuebles, &indices_size);
                        if(indices_size > 0) {
                                printf("los inmuebles del propietario son:\n");
                                for (int i = 0; i < indices_size; i++) {
                                        mostrar_inmueble(&inmuebles[indices_inmuebles[i]]);
                                }
                        } else {
                                printf("el propietario no tiene inmuebles\n");
                        }
                        break;

                case 'd':
                        printf("saliendo...\n");
                        *salir = 1;
                        break;
        }
}
void mostrar_inmueble(Inmueble *inmueble)
{
        printf("inmueble: \n");
        printf("numero de catastro: %d\n", inmueble->nro_catastro);
        printf("nombre del propietario: %s\n", inmueble->nombre_del_propietario);
        mostrar_calle(&inmueble->calle);
        mostrar_tipo_inmueble(&inmueble->tipo);
        printf("metros cuadrados: %d\n", inmueble->m2);
        printf("banos: %d\n", inmueble->banos);
        printf("habitaciones: %d\n", inmueble->habitaciones);
}
void mostrar_calle(Calle *calle)
{
        printf("calle: %s\n", calle->nombre);
        printf("numero de calle: %d\n", calle->numero);
}
void mostrar_tipo_inmueble(TipoInmueble *tipo)
{
        printf("tipo de inmueble: ");
        switch(*tipo)
        {
                case TERRENO:
                        printf("Terreno\n");
                        break;
                case CONSTRUCCION:
                        printf("Construccion\n");
                        break;
                case EDIFICADO:
                        printf("Edificado\n");
                        break;
        }
}
int obtener_indice_inmueble_mayor_m2(Inmueble *inmuebles, int size)
{
        int indice_mayor = 0;
        for (int i = 1; i < size; i++) {
                if(inmuebles[i].m2 > inmuebles[indice_mayor].m2)
                        indice_mayor = i;
        }
        return indice_mayor;
}
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
int buscar_inmueble_por_catastro(Inmueble *inmuebles, int size, int nro_catastro)
{
        for (int i = 0; i < size; i++) {
                if(inmuebles[i].nro_catastro == nro_catastro)
                        return i;
        }
        return -1;
}
void buscar_inmuebles_por_nombre(Inmueble *inmuebles, int size, String nombre, int *indices_inmuebles, int *indices_size)
{
        *indices_size = 0;
        int p_len, p_1_len, p_2_len;
        p_1_len  = strlen(nombre);
        for (int i = 0; i < size; i++) {
                p_2_len = strlen(inmuebles[i].nombre_del_propietario);
                p_len = p_1_len < p_2_len ? p_1_len : p_2_len;
                if(strncmp(inmuebles[i].nombre_del_propietario, nombre, p_len) == 0) {
                        indices_inmuebles[*indices_size] = i;
                        *indices_size += 1;
                }
        }
}