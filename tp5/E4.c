#include <stdio.h>

#define T_MAX 50

typedef char String[T_MAX];

void obtener_mayor_palabra(char *cadena, char *palabra);
int contar_palabras(char *cadena);

int main(int argc, char *argv[]) {
    String texto, palabra;
    int cantidad_palabras;

    printf("Ingrese el texto: ");
    fgets(texto, T_MAX, stdin);
    
    obtener_mayor_palabra(texto, palabra);
    cantidad_palabras = contar_palabras(texto);

    printf("La palabra más larga es: %s\n", palabra);
    printf("La cantidad de palabras es: %d\n", cantidad_palabras);

    return 0;
}

void obtener_mayor_palabra(char *cadena, char *palabra) {
    int i = 0, cant = 0, cant_may = 0, i_fin = 0;

    while (cadena[i] != '\0') {
        if (cadena[i] == ' ') {
            if (cant > cant_may) {
                cant_may = cant;
                i_fin = i;
            }
            cant = 0;
        } else {
            cant++;
        }
        i++;
    }

    while (cadena[i] != '\0') {
        if (cadena[i] != ' ') {
            cant++;
        } else {
            if (cant > cant_may) { // si la palabra esta al ultimo esto no funciona
                cant_may = cant;
                i_fin = i;
            }
            cant = 0;
        }
        i++;
    }

    if (cant > cant_may) { // cubrimos el caso que falta
        cant_may = cant;
        i_fin = i;
    }

    i = 0;
    for (int j = i_fin - cant_may; j < i_fin; j++) {
        palabra[i] = cadena[j];
        i++;
    }

    palabra[i] = '\0';
}

int contar_palabras(char *cadena) {
    int i = 0, cant = 0;

    while (cadena[i] != '\0') {
        if (cadena[i] == ' ') {
            cant++;
        }
        i++;
    }

    cant++; // Contar la última palabra
    return cant;
}
