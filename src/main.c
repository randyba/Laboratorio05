#include <stdio.h>
#include <stdlib.h>
#include "ArreglosDinamicos.h"
#include "Stack.h"
#include "ListaEnlazada.h"
#include "ListaDoblementeEnlazada.h"

// Funcion principal
int main() {

    int tamano;

    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tamano);

    // Crear arreglo con memoria dinamica
    int *arreglo = crearArreglo(tamano);

    // Agregar elementos al arreglo
    for (int i = 0; i < tamano; i++) {

        int elemento;

        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &elemento);

        agregarElemento(arreglo, tamano, elemento);
    }

    // Imprimir arreglo
    imprimirArreglo(arreglo, tamano);

    // Eliminar un elemento
    int elementoEliminar;

    printf("Ingrese el elemento a eliminar: ");
    scanf("%d", &elementoEliminar);

    eliminarElemento(arreglo, tamano, elementoEliminar);

    // Imprimir nuevamente
    imprimirArreglo(arreglo, tamano);

    // Obtener elemento por indice
    int indice;

    printf("Ingrese el indice del elemento a obtener: ");
    scanf("%d", &indice);

    int elementoObtenido = obtenerElemento(arreglo, tamano, indice);

    printf("Elemento en el indice %d: %d\n", indice, elementoObtenido);

    // Liberar memoria del arreglo
    free(arreglo);


    /**********************
     * PRUEBAS DEL STACK
     **********************/

    Stack pila;

    inicializarStack(&pila, 5);

    printf("\n===== PRUEBAS DEL STACK =====\n");

    push(&pila, 10);
    push(&pila, 20);
    push(&pila, 30);

    printf("Elemento en el tope: %d\n", peek(&pila));

    printf("Elemento eliminado: %d\n", pop(&pila));

    printf("Nuevo elemento en el tope: %d\n", peek(&pila));

    if (isEmpty(&pila)) {
        printf("El stack esta vacio.\n");
    } else {
        printf("El stack no esta vacio.\n");
    }

    liberarStack(&pila);

    //******************************
    //* Prueba de la lista enlazada*
    //****************************** 
    Nodo* lista = NULL;

    insertarInicio(&lista, 10);
    insertarFinal(&lista, 20);
    insertarFinal(&lista, 30);

    printf("\n===== PRUEBAS DE LISTA ENLAZADA =====\n");
    imprimirLista(lista);

    if (buscarElementoLista(lista, 20)) {
        printf("El elemento 20 fue encontrado.\n");
    }

    eliminarElementoLista(&lista, 20);

    printf("Lista despues de eliminar 20:\n");
    imprimirLista(lista);

    liberarLista(&lista);

    //*************************************
    //*PRUEBA DE LISTA DOBLEMENTE ENLAZADA*
    //*************************************

    NodoDoble* listaDoble = NULL;

    //insertar al inicio
    // solicitar al usuario el dato a insertar al inicio
    int datoInicio;
    printf("\n===== PRUEBAS DE LISTA DOBLEMENTE ENLAZADA =====\n");
    printf("\n");
    printf("Ingrese el dato a insertar al inicio: ");
    scanf("%d", &datoInicio);
    //insertamos el dato en el inicio de la lista.
    insertarInicioDoble(&listaDoble, datoInicio);

    //solicitar al usuario el dato a insertar al final
    int datoFinal;
    printf("\nIngrese el dato a insertar al final: ");
    scanf("%d", &datoFinal);
    //insertamos el dato en el final de la lista.
    insertarFinalDoble(&listaDoble, datoFinal);

    //solicitar al usuario el dato a insertar en una posicion especifica
    int datoPosicion, posicion;
    printf("Ingrese el dato a insertar en una posicion especifica: ");
    scanf("%d", &datoPosicion);
    printf("Ingrese la posicion: ");
    scanf("%d", &posicion);
    //insertamos el dato en la posicion especifica de la lista.
    insertarPosicionDoble(&listaDoble, datoPosicion, posicion);

    //solicitar al usuario el dato a eliminar
    int datoEliminar;
    printf("\nIngrese el dato a eliminar: ");
    scanf("%d", &datoEliminar);
    //eliminamos el dato de la lista.
    eliminarDatoDoble(&listaDoble, datoEliminar);

    //solicitar al usuario el dato a buscar
    int datoBuscar;
    printf("\nIngrese el dato a buscar: ");
    scanf("%d", &datoBuscar);
    //buscamos el dato en la lista.
    if (buscarDatoDoble(listaDoble, datoBuscar)== -1) {
        printf("El elemento %d no fue encontrado.\n", datoBuscar);
    } else {//nos aseguramos que se encuentre el dato.
        printf("El elemento %d fue encontrado.\n", datoBuscar);
    }

    //imprimir la lista hacia adelante
    printf("\nImprimiendo Lista doblemente enlazada hacia adelante...\n");
    imprimirListaDobleAdelante(listaDoble);

    //imprimir la lista hacia atras
    printf("\nImprimiendo Lista doblemente enlazada hacia atras...\n");
    imprimirListaDobleAtras(listaDoble);

    //liberar la memoria de la lista doblemente enlazada
    liberarListaDoble(&listaDoble);

    return 0;

}
