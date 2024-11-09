typedef struct {
        int anio;
        int mes;
        int dia;
        char todo_junto[16];
} Fecha;

Fecha ingresar_fecha(char *mensaje);
int contar_dias(Fecha fecha);
int dias_entre_fechas(Fecha fecha_mayor, Fecha fecha_menor);
int es_bisiesto(int anio);