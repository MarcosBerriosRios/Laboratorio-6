#include <stdio.h>
#include <stdlib.h>

#ifndef _ABB_H_
#define _ABB_H_

typedef int Info;

typedef struct Nodo {
  Info dato;
  struct Nodo *izq;
  struct Nodo *der;
}Nodo;

/* Funciones de las operaciones */
Nodo *crearNodo(Info dato);
Nodo *buscarMin(Nodo *node);
Nodo *buscarMax(Nodo *node);
Nodo *insertar(Nodo *node, Info dato);
Nodo *eliminar(Nodo *node, Info dato);
Nodo *buscar(Nodo *node, Info dato);
Nodo *eliminarArbol(Nodo *a);
void inorden(Nodo *node);
void preorden(Nodo *node);
void postorden(Nodo *node);
#endif /* _ABB_H_ */
