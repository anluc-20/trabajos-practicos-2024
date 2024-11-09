typedef struct {
        int hora;
        int minuto;
        char todo_junto[6];
} Hora;

Hora ingresar_hora(char *mensaje);
Hora restar_horas(Hora hora1, Hora hora2);