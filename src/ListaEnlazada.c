/*
ListaEnlazada.c
IE-0117 Laboratorio 05

Implementación de una lista enlazada simple.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ListaEnlazada.h"

// Crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        return NULL;
    }

    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

// Insertar al inicio
void insertarInicio(Nodo **cabeza, int dato) {
    Nodo* nuevo = crearNodo(dato);

    if (nuevo == NULL)
        return;

    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// Insertar al final
void insertarFinal(Nodo **cabeza, int dato) {

    Nodo* nuevo = crearNodo(dato);

    if (nuevo == NULL)
        return;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        return;
    }

    Nodo* actual = *cabeza;

    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
}

// Insertar en una posición
void insertarPosicion(Nodo **cabeza, int dato, int posicion) {

    if (posicion == 0) {
        insertarInicio(cabeza, dato);
        return;
    }

    Nodo* actual = *cabeza;

    for (int i = 0; i < posicion - 1 && actual != NULL; i++) {
        actual = actual->siguiente;
    }

    if (actual == NULL)
        return;

    Nodo* nuevo = crearNodo(dato);

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
}

// Eliminar un elemento
void eliminarElementoLista(Nodo **cabeza, int dato) {

    if (*cabeza == NULL)
        return;

    Nodo* actual = *cabeza;
    Nodo* anterior = NULL;

    while (actual != NULL && actual->dato != dato) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
        return;

    if (anterior == NULL)
        *cabeza = actual->siguiente;
    else
        anterior->siguiente = actual->siguiente;

    free(actual);
}

// Buscar un elemento
int buscarElementoLista(Nodo *cabeza, int dato) {

    while (cabeza != NULL) {

        if (cabeza->dato == dato)
            return 1;

        cabeza = cabeza->siguiente;
    }

    return 0;
}

// Imprimir lista
void imprimirLista(Nodo *cabeza) {

    while (cabeza != NULL) {

        printf("%d -> ", cabeza->dato);

        cabeza = cabeza->siguiente;
    }

    printf("NULL\n");
}

// Liberar memoria
void liberarLista(Nodo **cabeza) {

    Nodo* actual = *cabeza;

    while (actual != NULL) {

        Nodo* siguiente = actual->siguiente;

        free(actual);

        actual = siguiente;
    }

    *cabeza = NULL;
}
