#include "TAD_ListaCliente.h"
#include <stdio.h>

int retorna_tam(TLista L){
	return L.tam;
}
TLista inicializa(){
	TLista aux;
	aux.tam=0;
	return aux;
}
void carga_rec(TVector L, int tam){
        if(tam >= 0) { 
                carga_rec(L, tam - 1);
                L[tam] = cargar_cliente();
        }
}
TLista cargar_clientes(){ 
	TLista L;
	printf("\nIngrese la cantidad de elementos: ");
	scanf("%d", &L.tam);
        getchar(); //limpio el salto de linea
	carga_rec(L.cli, L.tam - 1);// Hay que pasar L.tam - 1, puesto que los arreglos estan indexados desde el 0, el ultimo elemento tiene indice n-1 donde n es el tamaño del arreglo
	return L;
}
int busq_sec_rec(TVector A, int N, long DNI){/*COMPLETAR*/ /*retorna -1 si no lo encuentra sino retorna la posicion*/
        if(N < 0)
                return -1; //recorrimos todo el arreglo y no lo encontramos
        if(retornar_DNI(A[N]) != DNI)
               return busq_sec_rec(A, N - 1, DNI); //aun queda arreglo por recorrer y no encontramos lo que buscamos
        else
                return N; //encontramos el dni
}
void agrega_cliente(TLista *L){ 
	int pos;
	RCliente nvo;
	nvo= cargar_cliente();
	pos= busq_sec_rec(L->cli, L->tam - 1, retornar_DNI(nvo)); //hay que buscar desde el ultimo elemento del arreglo, n-1 donde n es el tamaño...
	if (pos==-1) {
		L->cli[L->tam] = nvo;
                L->tam++;
		printf("\nSe agrego exitosamente el nuevo cliente");
	}
	else printf("\nEl cliente ya esta cargado");
}

void elimina_rec(TVector A, int N, int pos){ /*COMPLETAR*/
        if(pos < N) {
                A[pos] = A[pos+1];
                elimina_rec(A, N, pos + 1);
        }
}
void elimina_cliente(TLista *A){ 
	int pos;
	long DNI;
	printf("\nIngrese el DNI del cliente a eliminar: ");
	scanf("%ld", &DNI);
	pos= busq_sec_rec(A->cli, A->tam - 1, DNI);
	if (pos!=-1) {
		elimina_rec(A->cli, A->tam - 1, pos);
		printf("\nSe elimino exitosamente el cliente");
		A->tam--;
	}
	else printf("\nEl cliente no se encuentra");
}
void modifica_cliente(TLista *A){ 
	int pos;
	long DNI;
	printf("\nIngrese el DNI del cliente a modificar: ");
	scanf("%ld", &DNI);
	pos= busq_sec_rec(A->cli, A->tam - 1, DNI);
	if (pos!=-1) modificar_cliente(&A->cli[pos]);
	else printf("\nEl cliente no se encuentra");
}
void mostrar_rec(TVector A, int tam){ /*COMPLETAR*/
        if(tam >= 0) {
                mostrar_rec(A, tam - 1);
                mostrar_cliente(A[tam]);
        }
}
void mostrar_clientes(TLista A){
	mostrar_rec(A.cli, A.tam - 1);
}
void genera_rec(TVector A, int N, TVector D, int *M){/*COMPLETAR*/
        if( N > 0)
                genera_rec(A, N - 1, D, M);

        if(retornar_saldo(A[N]) < 0) {
                D[*M] = A[N];
                *M += 1;
        }
}
TLista genera_deudor(TLista A){
	TLista D;
	D=inicializa();
	genera_rec(A.cli, A.tam - 1, D.cli, &D.tam);
        return D;
}


int obtener_pivot(TVector A, int ini, int fin)
{
        int apuntador, i;
        RCliente aux;
        apuntador = ini - 1;
        for (i = ini; i <= fin; i++) {
                if(retornar_saldo(A[i]) <= retornar_saldo(A[fin])) {
                        apuntador++;
                        aux = A[i];
                        A[i] = A[apuntador];
                        A[apuntador] = aux;
                }
        }
        return apuntador;
}
void q_sort(TVector A, int ini, int fin) {/*COMPLETAR*/
        int pivot;
        if(ini >= fin)
                return; // la sublista es de tamaño 1 o menor, retornamos

        pivot = obtener_pivot(A, ini, fin);
        q_sort(A, ini, pivot - 1); // sublista izquierda
        q_sort(A, pivot + 1, fin); // sublista derecha

}
void ordena_clientes(TLista *D){
	int ini,fin;
	ini=0; //inicio deberia ser 0
	fin=D->tam - 1; //fin deberia ser n-1 donde n es el tamaño del arreglo
	q_sort(D->cli, ini, fin);
}
