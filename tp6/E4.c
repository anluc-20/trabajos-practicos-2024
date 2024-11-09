#include <stdio.h>

#define STR_MAX_SIZE 30
#define ALUMNOS_ARR_MAX_SIZE 20
#define MAX_INSCRIPTOS 2
#define OPCIONES "a) Agregar un alumno a la lista.\nb) Inscribir alumno a curso.\nc) Dar de baja en un curso a un alumno\nd) Eliminar de la lista todos los alumnos que no se encuentren inscriptos en algún curso.\ne) Mostrar la lista de inscriptos en un curso.\nf) Salir.\nopcion:"

typedef char String[STR_MAX_SIZE];

typedef enum {
        CURSO_LLENO = 0,
        YA_EN_UN_CURSO = 1,
        OK = 2
} Inscripcion;

typedef enum {
        NADA = 0,
        FOLCLORE = 1,
        ESPANOL = 2,
        CONTEMPORANEO = 3
} CursoDeVerano;

typedef struct {
        int dni;
        String apellido;
        String nombre;
        CursoDeVerano curso_de_verano;
} Alumno;

/*
Ejercicio 4: Una academia de danzas tiene una lista de alumnos, registrando de cada alumno los
siguientes datos: “DNI del alumno, Apellido y Nombre del alumno, Código de curso de verano ([1] folclore,
[2] español, [3] contemporáneo)”.
Crear un programa que permita cargar la lista de alumnos, inicializando el campo Código de curso en 0.
Luego ordene la lista por DNI del alumno utilizando el método de la Burbuja. Posteriormente, a través de
un menú realizar las siguientes tareas:
a) Agregar un alumno a la lista.
b) Dado el DNI de un alumno inscribirlo a uno de los 3 cursos que se dictan, teniendo en cuenta que el
cupo es de 10 personas para cada curso. Un alumno sólo puede estar inscripto en un curso a la vez.
c) Permitir dar de baja a un alumno de un curso ingresando su DNI. (Cambiar Código a 0)
d) Eliminar de la lista todos los alumnos que no se encuentren inscriptos en algún curso.
e) Dado un Código de curso, mostrar la lista de inscriptos. 
*/

void menu(int *salir, Alumno **alumnos_p, int *size);

//opciones del menu
void ingresar_alumno_agregar_lista(Alumno **alumnos_p, int *size);
void ingresar_dni_inscribir_curso(Alumno **alumnos_p, int size);
void ingresar_dni_dar_baja_curso(Alumno **alumnos_p, int size);
void eliminar_alumnos_sin_curso(Alumno **alumnos_p, int *size);
void ingresar_curso_mostrar_inscriptos(Alumno **alumnos_p, int size);

//funciones y procedimientos
void ingresar_alumno(Alumno *alumno);
int busqueda_binaria_por_dni(Alumno **alumnos_p, int size, int dni);
void ordenar_alumnos_por_dni(Alumno **alumnos_p, int size);
CursoDeVerano ingresar_curso();
void mostrar_alumno(Alumno *alumno);
void mostrar_alumnos(Alumno **alumnos_p, int size);
Inscripcion intentar_inscribir_curso(Alumno **alumnos_p, int size, Alumno *alumno);




//utilidades
void console_read(char *buffer, int max_size);
void ingresar_texto(char *mensaje, char *cadena, int max_size);
void ingresar_entero(char *mensaje, int *salida);
void ingresar_char(char *mensaje, char *salida);
void limpiar_entrada();
void enlazar_array_y_array_p(Alumno *array, Alumno **array_p, int size);
void ingresar_alumnos(Alumno **alumnos_p, int *size);


int main()
{
        int salida = 0, n;
        Alumno alumnos[ALUMNOS_ARR_MAX_SIZE];
        Alumno *alumnos_p[ALUMNOS_ARR_MAX_SIZE];
        enlazar_array_y_array_p(alumnos, alumnos_p, ALUMNOS_ARR_MAX_SIZE);
 
        ingresar_alumnos(alumnos_p, &n);
        ordenar_alumnos_por_dni(alumnos_p, n);

        while (!salida) 
                menu(&salida, alumnos_p, &n);

        return 0;
}

void menu(int *salir, Alumno **alumnos_p, int *size)
{
        char opcion;
        ingresar_char(OPCIONES, &opcion);
        while((opcion < 'a') || (opcion > 'g'))
                ingresar_char("opcion invalida, por favor ingrese una opcion valida: ", &opcion);

        switch (opcion) {
                case 'a':
                        ingresar_alumno_agregar_lista(alumnos_p, size);

                        break;
                        
                case 'b':
                        ingresar_dni_inscribir_curso(alumnos_p, *size);

                        break;

                case 'c':
                        ingresar_dni_dar_baja_curso(alumnos_p, *size);
                        
                        break;

                case 'd':
                        eliminar_alumnos_sin_curso(alumnos_p, size);
                        

                        break;

                case 'e':
                        ingresar_curso_mostrar_inscriptos(alumnos_p, *size);

                        break;
        
                case 'f':
                        printf("saliendo...\n");
                        *salir = 1;
                        break;
                case 'g':
                        mostrar_alumnos(alumnos_p, *size);
                        break;
        }
}

//opciones del menu
void ingresar_alumno_agregar_lista(Alumno **alumnos_p, int *size)
{
        ingresar_alumno(alumnos_p[*size]);
        printf("se ha agregado correctamente al alumno %s %s a la lista.\n", alumnos_p[*size]->apellido, alumnos_p[*size]->nombre);
        *size += 1;
        ordenar_alumnos_por_dni(alumnos_p, *size);
}
void ingresar_dni_inscribir_curso(Alumno **alumnos_p, int size)
{
        int dni, indice;
        Inscripcion inscripcion;
        ingresar_entero("ingrese el dni del alumno: ", &dni);
        indice = busqueda_binaria_por_dni(alumnos_p, size, dni);
        if(indice != -1) {
                inscripcion = intentar_inscribir_curso(alumnos_p, size,alumnos_p[indice]);
                switch (inscripcion) {
                        case CURSO_LLENO:
                                printf(" no se ha podido inscribir al alumno %s %s en el curso, esta lleno.\n", alumnos_p[indice]->apellido, alumnos_p[indice]->nombre);
                                break;

                        case YA_EN_UN_CURSO:
                                printf(" no se ha podido inscribir al alumno %s %s en el curso, el alumno ya se encuentra en uno.\n", alumnos_p[indice]->apellido, alumnos_p[indice]->nombre);
                                break;

                        case OK:
                                printf("el alumno %s %s ha sido inscripto al curso numero [%d].\n", alumnos_p[indice]->apellido, alumnos_p[indice]->nombre, alumnos_p[indice]->curso_de_verano);
                                break;
                        }
                
        } else {
                printf("no se encontro el alumno con tal dni.\n");
        }

}
void ingresar_dni_dar_baja_curso(Alumno **alumnos_p, int size)
{
        int dni, indice, curso_anterior;
        ingresar_entero("ingrese el dni del alumno: ", &dni);
        indice = busqueda_binaria_por_dni(alumnos_p, size, dni);
        if(indice != -1) {
                curso_anterior = alumnos_p[indice]->curso_de_verano;
                alumnos_p[indice]->curso_de_verano = 0;
                printf("se ha dado de baja a el alumno %s %s del curso numero [%d].\n", alumnos_p[indice]->apellido, alumnos_p[indice]->nombre, curso_anterior);
        } else {
                printf("no se encontro el alumno con tal dni.\n");
        }
}
void eliminar_alumnos_sin_curso(Alumno **alumnos_p, int *size)
{
        int i = 0;
        while (i < *size) {
                if(alumnos_p[i]->curso_de_verano == NADA) {
                        printf("se ha eliminado al alumno %s %s.\n", alumnos_p[i]->apellido, alumnos_p[i]->nombre);
                        for (int j = i; j < *size - 1; j++)
                                alumnos_p[j] = alumnos_p[j + 1];
                        *size -= 1;
                } else {
                        i++;
                }    
        }
}
void ingresar_curso_mostrar_inscriptos(Alumno **alumnos_p, int size)
{
        CursoDeVerano curso = ingresar_curso();
        Alumno *inscriptos_p[ALUMNOS_ARR_MAX_SIZE];
        int inscriptos_size = 0;

        for (int i = 0; i < size; i++) {
                if(alumnos_p[i]->curso_de_verano == curso) {
                        inscriptos_p[inscriptos_size] = alumnos_p[i];
                        inscriptos_size++;
                }
        }
        if(inscriptos_size > 0) {
                mostrar_alumnos(inscriptos_p, inscriptos_size);
        } else {
                printf("no hay alumnos inscriptos a este curso.\n");
        }
}

//funciones y procedimientos
void ingresar_alumno(Alumno *alumno)
{
        ingresar_texto("apellido: ", alumno->apellido, STR_MAX_SIZE);
        ingresar_texto("nombre: ", alumno->nombre, STR_MAX_SIZE);
        ingresar_entero("dni: ", &alumno->dni);
        alumno->curso_de_verano = NADA;
}
int busqueda_binaria_por_dni(Alumno **alumnos_p, int size, int dni)
{
        int inicio = 0, fin = size - 1, m = (inicio + fin) / 2;
        while((inicio < fin) && (alumnos_p[m]->dni != dni))
        {
                if(alumnos_p[m]->dni > dni)
                        fin = m - 1;
                else
                        inicio = m + 1;
                m = (inicio + fin) / 2;
        }
        if(alumnos_p[m]->dni == dni)
                return  m;
        else
                return -1;
}
void ordenar_alumnos_por_dni(Alumno **alumnos_p, int size)
{
        Alumno *aux;
        for(int i = size - 1; i > 0; i--) {
                for (int j = 0; j < i; j++) {
                        if(alumnos_p[j]->dni > alumnos_p[j+1]->dni) {
                                aux = alumnos_p[j];
                                alumnos_p[j] = alumnos_p[j+1];
                                alumnos_p[j+1] = aux;
                        }
                }
        }
}
CursoDeVerano ingresar_curso()
{
        
        int opcion;
        CursoDeVerano curso;
        ingresar_entero("ingrese un curso:\nOpcion [1]: FOLCLORE\nOpcion [2]: ESPANOL\nOpcion [3]: CONTEMPORANEO\nopcion: ", &opcion);
        while((opcion < 1) || (opcion > 3))
                ingresar_entero("opcion invalida, por favor ingrese una opcion valida: ", &opcion);

        switch (opcion) {
                case 1:
                        curso = FOLCLORE;
                        break;
                        
                case 2:
                        curso = ESPANOL;
                        break;

                case 3:
                        curso = CONTEMPORANEO;
                        break;
        }
        return curso;
}
void mostrar_alumno(Alumno *alumno)
{
        printf("apellido: %s\n", alumno->apellido);
        printf("nombre: %s\n", alumno->nombre);
        printf("dni: %d\n", alumno->dni);
}
void mostrar_alumnos(Alumno **alumnos_p, int size)
{
        for (int i = 0; i < size; i++) {
                printf("[%d/%d]\n", i, size - 1);
                mostrar_alumno(alumnos_p[i]);
        }
}
Inscripcion intentar_inscribir_curso(Alumno **alumnos_p, int size, Alumno *alumno)
{
        CursoDeVerano curso;
        int inscriptos = 0;

        if(alumno->curso_de_verano != 0)
                return YA_EN_UN_CURSO;
        
        curso = ingresar_curso();

        for (int i = 0; i < size; i++)
                if(alumnos_p[i]->curso_de_verano == curso)
                        inscriptos++;

        if(inscriptos >= MAX_INSCRIPTOS)
                return CURSO_LLENO;
        
        alumno->curso_de_verano = curso;
        return OK;
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
void enlazar_array_y_array_p(Alumno *array, Alumno **array_p, int size)
{
        for (int i = 0; i < size; i++) {
                array_p[i] = &array[i];
        }
}
void ingresar_alumnos(Alumno **alumnos_p, int *size)
{
        ingresar_entero("ingrese el numero de alumnos: ", size);
        for (int i = 0; i < *size; i++) {
                printf("[%d/%d]\n", i, *size - 1);
                printf("ingrese los siguientes datos:\n");
                ingresar_alumno(alumnos_p[i]);
        }
}