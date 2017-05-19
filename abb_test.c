#include "abb.c"

int main(int argc, char *argv[])
{
  unsigned i, n = 20;
  Nodo *raiz = NULL;
  Info datos[] = {9,1,78,34,6,22,3,4,7,2,9,8,5,45,88,32,10,65,0,42};
  for(i = 0; i < n; i++)
    raiz = insertar(raiz, datos[i]);
  preorden(raiz);
  printf("\n\n");
  inorden(raiz);
  printf("\n\n");
  postorden(raiz);
  printf("\n\n");

  raiz = eliminar(raiz, 78);
  raiz = eliminar(raiz, 0);
  preorden(raiz);
  printf("\n");
  Nodo * temp;
  temp = buscarMin(raiz);
  printf("\nElemento mínimo es % d.\n",temp->dato);
  temp = buscarMax(raiz);
  printf("Elemento máximo es % d.\n",temp->dato);

  int elemento = 8;
  temp = buscar(raiz, elemento);
  printf("El elemento % d: ",
         elemento);
  if(temp == NULL)
    printf("no se encontro.\n");
   else
    printf("se encontro.\n");
  elemento = 50;
  temp = buscar(raiz, elemento);
  printf("El elemento % d: ",
         elemento);
  if(temp == NULL)
    printf("no se encontro.\n");
   else
    printf("se encontro.\n");
  eliminarArbol(raiz);
  return 0;
}