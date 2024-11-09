#include <stdio.h>

int busqueda_binaria(int *array, int size, int buscado);

int main() 
{
        int array[20] = {3, 8, 12, 17, 23, 27, 35, 41, 46, 52, 58, 63, 69, 74, 81, 86, 92, 97, 103, 110};
        int buscado;

        while (1) {
                scanf("%d", &buscado);
                int indice = busqueda_binaria(array, 20, buscado);
                if(indice != -1)
                        printf("el elemento %d, se encuentra en [%d]\n", buscado, indice);
                else
                        printf("no se encontro el numero\n");
        }
        
        return 0;
}

int busqueda_binaria(int *array, int size, int buscado)
{
        int inicio = 0, fin = size - 1, m = (inicio + fin) / 2;
        while((inicio < fin) && array[m] != buscado) {
                if(array[m] > buscado)
                        fin = m - 1;
                else
                        inicio = m + 1;

                m = (inicio + fin) / 2;
        }
        if(array[m] == buscado)
                return m;
        else
                return -1;
}