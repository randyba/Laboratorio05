#ifndef FUNCIONES_H
#define FUNCIONES_H

/*
funciones.h
IE-0117 Laboratorio 05
*/

//funcion para crear un arreglo con memoria dinamica
int* crearArreglo(int tamano);

//funcion para agregar un elemento al arreglo
void agregarElemento(int* arreglo, int tamano, int elemento);

//funcion para eliminar un elemento del arreglo
void eliminarElemento(int* arreglo, int tamano, int elemento);

//funcion para obtener elemento por indice
int obtenerElemento(int* arreglo, int tamano, int indice);

//funcion para imprimir el arreglo
void imprimirArreglo(int* arreglo, int tamano);

#endif // FUNCIONES_H