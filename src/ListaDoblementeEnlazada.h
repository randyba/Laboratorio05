#ifndef ListaDoblementeEnlazada_H
#define ListaDoblementeEnlazada_H
/*
ListaDoblementeEnlazada.h
IE-0117 Laboratorio 05

Archivo de encabezado para la lista doblemente enlazada.
*/

// Estructura del nodo
typedef struct NodoDoble {
    int dato;
    struct NodoDoble *siguiente;
    struct NodoDoble *anterior;
} NodoDoble;

//Funcion para crrear un nodo doble

NodoDoble* crearNodoDoble(int dato);

//Funcion para insertar al inicio
void insertarInicioDoble(NodoDoble **cabeza, int dato);

//Funcion para insertar al final
void insertarFinalDoble(NodoDoble **cabeza, int dato);

//Funcion para insertar en una posicion especifica
void insertarPosicionDoble(NodoDoble **cabeza, int dato, int posicion);

//Funcion para eliminar un elemento basado en la data
void eliminarDatoDoble(NodoDoble **cabeza, int dato);

//Funcion para buscar un elemento basado en la data
int buscarDatoDoble(NodoDoble *cabeza, int dato);

//Funcion para imprimir la lista doblemente enlazada
void imprimirListaDobleAdelante(NodoDoble *cabeza);

//Funcion para imprimir la lista doblemente enlazada en reversa
void imprimirListaDobleAtras(NodoDoble *cabeza);

//Funcion para liberar la memoria de la lista doblemente enlazada
void liberarListaDoble(NodoDoble **cabeza);


#endif // ListaDoblementeEnlazada_H