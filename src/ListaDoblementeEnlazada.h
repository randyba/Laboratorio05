#ifndef ListaDoblementeEnlazada_H
#define ListaDoblementeEnlazada_H
/*
ListaDoblementeEnlazada.h
IE-0117 Laboratorio 05
/*
Archivo de encabezado para la lista doblemente enlazada.
*/

// Estructura del nodo
typedef struct NodoDoble {
    int dato;
    struct NodoDoble *siguiente;
    struct NodoDoble *anterior;
} NodoDoble;

#endif // ListaDoblementeEnlazada_H