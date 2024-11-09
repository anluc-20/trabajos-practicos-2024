#include "espectaculo.h"
#include "../utils/utils.h"


void inicializar_lista_espectaculo(ListaEspectaculo *espectaculos, EspectaculoArray array)
{
        int i;
        for (i = 0; i < ESPECTACULOS_MAX_SIZE; i++) {
                espectaculos->p[i] = &array[i];
        }
        espectaculos->size = 0;
}
void ingresar_espectaculo(Espectaculo *espectaculo, int codigo)
{
        ingresar_texto("nombre: ", espectaculo->nombre, CAD_MAX_SIZE);

        ingresar_fecha_espectaculo(espectaculo);
        ingresar_hora_espectaculo(espectaculo);
        
        ingresar_entero("sala: ", &espectaculo->sala);
        espectaculo->codigo = codigo;
}

void ingresar_fecha_espectaculo(Espectaculo *espectaculo)
{
        espectaculo->fecha_inicio = ingresar_fecha("ingrese la fecha de inicio: \n");
        espectaculo->fecha_fin = ingresar_fecha("ingrese la fecha de fin: \n");
        while (dias_entre_fechas(espectaculo->fecha_fin, espectaculo->fecha_inicio) < 0) {
                espectaculo->fecha_fin = ingresar_fecha("la fecha de fin no puede ser menor que la fecha de inicio, ingrese una fecha valida: \n");
        }
}
void ingresar_hora_espectaculo(Espectaculo *espectaculo)
{
        int dias = dias_entre_fechas(espectaculo->fecha_fin, espectaculo->fecha_inicio);
        espectaculo->hora_inicio = ingresar_hora("ingrese la hora de inicio: \n");
        espectaculo->hora_fin = ingresar_hora("ingrese la hora de fin: \n");
        
        if(dias == 0) {
                while (restar_horas(espectaculo->hora_fin, espectaculo->hora_inicio).hora < 0) {
                        espectaculo->hora_fin = ingresar_hora("la hora de fin no puede ser menor que la hora de inicio, ingrese una hora valida: \n");
                }
        }
}

int intentar_agregar_espectaculo(ListaEspectaculo *espectaculos)
{
        Espectaculo filtro;
        int resultado;

        ingresar_entero("codigo: ", &filtro.codigo);
        
        if(buscar_espectaculo(espectaculos, comparar_por_codigo, filtro) != -1) { 
                resultado = 0;     
        } else {
                ingresar_espectaculo(espectaculos->p[espectaculos->size], filtro.codigo);
                espectaculos->size++;
                ordenar_lista_espectaculo(espectaculos, comparar_por_codigo);
                resultado = 1;
        }
        return resultado;
}
void mostrar_espectaculo(const Espectaculo *espectaculo)
{
        printf("%d\t\t", espectaculo->codigo);
        printf("%s\t\t", espectaculo->nombre);
        printf("%s\t\t", espectaculo->fecha_inicio.todo_junto);
        printf("%s\t\t", espectaculo->hora_inicio.todo_junto);
        printf("%s\t\t", espectaculo->fecha_fin.todo_junto);
        printf("%s\t\t", espectaculo->hora_fin.todo_junto);
        printf("%d\n", espectaculo->sala);
}

void mostrar_lista_espectaculo(ListaEspectaculo *espectaculos)
{
        int i;
        printf("Codigo\t\t");
        printf("Nombre\t\t");
        printf("Inicio\t\t\t\t");
        printf("Fin\t\t\t\t");
        printf("Sala\n");

        for (i = 0; i < espectaculos->size; i++)
                mostrar_espectaculo(espectaculos->p[i]);
}

void ordenar_lista_espectaculo(ListaEspectaculo *espectaculos, Comparador comparador)
{
        int i, j;
        Espectaculo *aux;
        for(i = 1; i < espectaculos->size; i++) {
                j = i - 1;
                while((j >= 0) && (comparador(espectaculos->p[j+1], espectaculos->p[j]) < 0)) {
                        aux = espectaculos->p[j+1];
                        espectaculos->p[j+1] = espectaculos->p[j];
                        espectaculos->p[j] = aux;
                        j--;
                }
        }
}
int buscar_espectaculo(ListaEspectaculo *espectaculos, Comparador comparador, Espectaculo filtro)
{
        int inicio, fin, m;
        inicio = 0;
        fin = espectaculos->size - 1;
        m = (inicio + fin) / 2;
        while((inicio < fin) && (comparador(espectaculos->p[m], &filtro) != 0)) {
                if(comparador(espectaculos->p[m], &filtro) > 0)
                        fin = m - 1;
                else
                        inicio = m + 1;
                m = (inicio + fin) / 2;
        }
        if(comparador(espectaculos->p[m], &filtro) != 0)
                m = -1;
        return m;
}
void buscar_espectaculos(ListaEspectaculo *espectaculos, ListaEspectaculo *salida, Comparador comparador, Espectaculo filtro)
{
        int i;
        salida->size = 0;
        for (i = 0; i < espectaculos->size; i++) {
                if(comparador(espectaculos->p[i], &filtro) == 0) {
                        salida->p[salida->size] = espectaculos->p[i];
                        salida->size++;
                }
        }
}
int buscar_espectaculo_por_codigo(ListaEspectaculo *espectaculos, int codigo)
{
        Espectaculo filtro;
        filtro.codigo = codigo;
        return buscar_espectaculo(espectaculos, comparar_por_codigo, filtro);
}

int comparar_por_codigo(Espectaculo *a, Espectaculo *b)
{
        return (a->codigo > b->codigo) - (a->codigo < b->codigo);
}
int comparar_por_sala(Espectaculo *a, Espectaculo *b)
{
        return (a->sala > b->sala) - (a->sala < b->sala);
}