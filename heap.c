#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size == 0)
    return NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  int posicion = pq->size;
  heapElem aux;
  int padre = (posicion-1)/2;
  if(pq->size == pq->capac)
  {
     pq->heapArray = realloc(pq->heapArray, pq->capac*2+1);
  }
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  pq->size++;
  while(pq->heapArray[posicion].priority > pq->heapArray[padre].priority)
  {
    if(pq->heapArray[posicion].priority > pq->heapArray[padre].priority)
    {
      aux = pq->heapArray[posicion];
      pq->heapArray[posicion] = pq->heapArray[padre];
      pq->heapArray[padre] = aux;
      posicion = padre;
      padre = (posicion-1)/2;
    }
    
  }
}


void heap_pop(Heap* pq)
{
  int pos = 0;
  int hijo1 = 2*pos+1;
  int hijo2 = 2*pos+2;
  heapElem aux;
  pq->heapArray[0] = pq-heapArray[pq->size]
  while(pq->heapArray[pos] > pq->heapArray[hijo1] && pq->heapArray[pos] > pq->heapArray[hijo2])
  {
    if(hijo1 > hijo2)
    {
      aux = pq->heapArray[pos];
      pq->heapArray[pos] = pq->heapArray[hijo1];
      pq-heapArray[hijo1] = aux;
      pos = hijo1;
      hijo1 = 2*pos+1;
    }
    else
    {
      aux = pq->heapArray[pos];
      pq->heapArray[pos] = pq->heapArray[hijo2];
      pq-heapArray[hijo2] = aux;
      pos = hijo2;
      hijo2 = 2*pos+2;
    }
  }
  pq->size--;
}

Heap* createHeap(){
  Heap *nuevoHeap;
  nuevoHeap = malloc(3 * sizeof(Heap));
  nuevoHeap->heapArray = malloc(3 * sizeof(Heap));
  nuevoHeap->size = 0;
  nuevoHeap->capac = 3;
  return nuevoHeap;
}
