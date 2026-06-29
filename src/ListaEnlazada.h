#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

/*
ListaEnlazada.h
IE-0117 Laboratorio 05

Archivo de encabezado para la lista enlazada simple.
*/

// Estructura del nodo
typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Prototipos de funciones
Nodo* crearNodo(int dato);
void insertarInicio(Nodo **cabeza, int dato);
void insertarFinal(Nodo **cabeza, int dato);
void insertarPosicion(Nodo **cabeza, int dato, int posicion);
void eliminarElementoLista(Nodo **cabeza, int dato);
int buscarElementoLista(Nodo *cabeza, int dato);
void imprimirLista(Nodo *cabeza);
void liberarLista(Nodo **cabeza);

#endif
