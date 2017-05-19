#include "abb.h"

/**
 * Funci�n que crea un nodo e inicializa sus datos y sus punteros izq y der
 * apuntan a NULL
 *
 * @param dato: Info datos
 * @return nuevo: direcci�n del nuevo nodo creado.
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
 * Funci�n que ingresa un nodo al �rbol.
 *
 * @param a: puntero a la ra�z.
 * @param dato: informaci�n a guardar en el nodo.
 *
 * @return direcci�n de la ra�z.
 */

Nodo *insertar(Nodo *a, Info dato)
{
  /* insertar en �rbol vac�o o en hoja */
  if(a == NULL)
    return crearNodo(dato);
  /* insertar en sub�rbol izquierdo */
  else if(dato < a->dato)
    a->izq = insertar(a->izq, dato);
  /* insertar en sub�rbol derecho */
  else if(dato > a->dato)
    a->der = insertar(a->der, dato);
  /* else: Ya est�, no se hace nada */
  return a;
}

/**
 * Funci�n que elimina un nodo dado del �rbol
 *
 * @param a: puntero a la ra�z.
 * @param dato: informaci�n a guardar en el nodo.
 *
 * @return direcci�n de la ra�z
 */

Nodo *eliminar(Nodo *a, Info dato)
{
  if(a == NULL)
    printf("El elemento no se encontr�.\n");
  /* seguir por la izquierda */
  else if(dato < a->dato)
    a->izq = eliminar(a->izq, dato);
    /* seguir por la derecha */
  else if(dato > a->dato)
    a->der = eliminar(a->der, dato);
  else /* Se encontr� */
    {
      Nodo *temp;
      /* Si es un nodo interno con dos hijos */
      if(a->der != NULL && a->izq != NULL)
        {
          /* nodo m�s a la izquierda del sub�rbol derecho */
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
 * Funci�n que busca un nodo dado en el �rbol
 *
 * @param a: puntero a la ra�z.
 * @param dato: informaci�n a guardar en el nodo.
 *
 * @return direcci�n de nodo buscado.
 */


Nodo *buscar(Nodo *a, Info dato)
{
  /* No se encontr� */
  if(a == NULL)
    return NULL;
  /* seguir por la izquierda */
  else if(dato < a->dato)
    return buscar(a->izq, dato);
  /* seguir por la derecha */
  else if(dato > a->dato)
    return buscar(a->der, dato);
  else  /* Si se encontr� */
    return a;
}

/**
 * Funci�n que busca el nodo m�nimo del �rbol
 *
 * @param a: puntero a la ra�z.
 *
 * @return direcci�n de nodo m�nimo.
 */

Nodo* buscarMin(Nodo *a)
{
  if(a == NULL)
    return NULL;
  /* Si no tiene hijo izquierdo */
  if(a->izq == NULL)
    return a; /* lo encontr�. */
  else
    return buscarMin(a->izq);
}

/**
 * Funci�n que busca el nodo m�ximo del �rbol
 *
 * @param a: puntero a la ra�z.
 *
 * @return direcci�n de nodo m�ximo.
 */
Nodo* buscarMax(Nodo *a)
{
  if(a == NULL)
    return NULL;
  /* Si no tiene hijo derecho*/
  if(a->der == NULL)
    return a; /* lo encontr�. */
  else
    return buscarMax(a->der);
}

/**
 * Funci�n que recorre el �rbol en inorden
 *
 * @param a: puntero a la ra�z.
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
 * Funci�n que recorre el �rbol en preorden
 *
 * @param a: puntero a la ra�z.
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
 * Funci�n que recorre el �rbol en postorden
 *
 * @param a: puntero a la ra�z.
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
 * Funci�n que elimina el �rbol.
 * Primero borra los subarboles y luego la raiz.
 *
 * @param a: puntero a la ra�z.
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