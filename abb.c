#include "abb.h"

/**
 * Función que crea un nodo e inicializa sus datos y sus punteros izq y der
 * apuntan a NULL
 *
 * @param dato: Info datos
 * @return nuevo: dirección del nuevo nodo creado.
 *
 */

Nodo *crearNodo(Info dato)
{
  Nodo *nodo;
  nodo = (Nodo *) malloc(sizeof(Nodo));
  nodo->dato = dato;
  nodo->izq = nodo->der = NULL;
  return nodo;
}

/**
 * Función que ingresa un nodo al árbol.
 *
 * @param a: puntero a la raíz.
 * @param dato: información a guardar en el nodo.
 *
 * @return dirección de la raíz.
 */

Nodo *insertar(Nodo *a, Info dato)
{
  /* insertar en árbol vacío o en hoja */
  if(a == NULL)
    return crearNodo(dato);
  /* insertar en subárbol izquierdo */
  else if(dato < a->dato)
    a->izq = insertar(a->izq, dato);
  /* insertar en subárbol derecho */
  else if(dato > a->dato)
    a->der = insertar(a->der, dato);
  /* else: Ya está, no se hace nada */
  return a;
}

/**
 * Función que elimina un nodo dado del árbol
 *
 * @param a: puntero a la raíz.
 * @param dato: información a guardar en el nodo.
 *
 * @return dirección de la raíz
 */

Nodo *eliminar(Nodo *a, Info dato)
{
  if(a == NULL)
    printf("El elemento no se encontró.\n");
  /* seguir por la izquierda */
  else if(dato < a->dato)
    a->izq = eliminar(a->izq, dato);
    /* seguir por la derecha */
  else if(dato > a->dato)
    a->der = eliminar(a->der, dato);
  else /* Se encontró */
    {
      Nodo *temp;
      /* Si es un nodo interno con dos hijos */
      if(a->der != NULL && a->izq != NULL)
        {
          /* nodo más a la izquierda del subárbol derecho */
          temp = buscarMin(a->der);
          a->dato = temp->dato; /* copia el nodo */
          a->der = eliminar(a->der, temp->dato);
        }
      else /* con un hijo o es una hoja */
        {
          temp = a;
          /* solo un hijo derecho o sin hijos */
          if(a->izq == NULL)
            a = a->der;
          /* solo un hijo izquierdo */
          else if(a->der == NULL)
            a = a->izq;
          free(temp);
        }
    }
  return a;
}

/**
 * Función que busca un nodo dado en el árbol
 *
 * @param a: puntero a la raíz.
 * @param dato: información a guardar en el nodo.
 *
 * @return dirección de nodo buscado.
 */


Nodo *buscar(Nodo *a, Info dato)
{
  /* No se encontró */
  if(a == NULL)
    return NULL;
  /* seguir por la izquierda */
  else if(dato < a->dato)
    return buscar(a->izq, dato);
  /* seguir por la derecha */
  else if(dato > a->dato)
    return buscar(a->der, dato);
  else  /* Si se encontró */
    return a;
}

/**
 * Función que busca el nodo mínimo del árbol
 *
 * @param a: puntero a la raíz.
 *
 * @return dirección de nodo mínimo.
 */

Nodo* buscarMin(Nodo *a)
{
  if(a == NULL)
    return NULL;
  /* Si no tiene hijo izquierdo */
  if(a->izq == NULL)
    return a; /* lo encontró. */
  else
    return buscarMin(a->izq);
}

/**
 * Función que busca el nodo máximo del árbol
 *
 * @param a: puntero a la raíz.
 *
 * @return dirección de nodo máximo.
 */
Nodo* buscarMax(Nodo *a)
{
  if(a == NULL)
    return NULL;
  /* Si no tiene hijo derecho*/
  if(a->der == NULL)
    return a; /* lo encontró. */
  else
    return buscarMax(a->der);
}

/**
 * Función que recorre el árbol en inorden
 *
 * @param a: puntero a la raíz.
 */

void inorden(Nodo *a)
{
  if(a != NULL)
    {
      inorden(a->izq);
      printf("% d ", a->dato);
      inorden(a->der);
    }
}

/**
 * Función que recorre el árbol en preorden
 *
 * @param a: puntero a la raíz.
 */

void preorden(Nodo *a)
{
  if(a != NULL)
    {
      printf("% d ", a->dato);
      preorden(a->izq);
      preorden(a->der);
    }
}

/**
 * Función que recorre el árbol en postorden
 *
 * @param a: puntero a la raíz.
 */

void postorden(Nodo *a)
{
  if(a != NULL)
    {
      postorden(a->izq);
      postorden(a->der);
      printf("% d ", a->dato);
    }
}

/**
 * Función que elimina el árbol.
 * Primero borra los subarboles y luego la raiz.
 *
 * @param a: puntero a la raíz.
 *
 * @return NULL.
 */

Nodo *eliminarArbol(Nodo *a)
{
  if(a != NULL)
    {
      a->izq = eliminarArbol(a->izq);
      a->der = eliminarArbol(a->der);
      free(a);
    }
  return NULL;
}

/*int altura(avl *t)
{
  if(t==NULL)
    return 0;
  else
    return t->altura;
}*/