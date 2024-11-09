typedef struct {
        int hora;
        int minuto;
        char todo_junto[6];
} Hora;

Hora ingresar_hora(char *mensaje);
Hora restar_horas(Hora a, Hora b);
char* obtener_hora_como_cadena(Hora *hora);