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
  if(pq->size == 0)
  {
    pq->heapArray[0].data = data;
    pq->heapArray[0].priority = priority;
    pq->size++;
  }
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  while(pq->heapArray[posicion].priority > pq->heapArray[posicion].priority)
  {
    if(pq->heapArray[posicion].priority > pq->heapArray[posicion].priority)
    {
      aux = pq->heapArray[posicion];
      pq->heapArray[posicion] = pq->heapArray[padre];
      pq->heapArray[padre] = aux;
      posicion = padre;
      padre = (posicion-1)/2
    }
    
  }
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *nuevoHeap;
  nuevoHeap = malloc(3 * sizeof(Heap));
  nuevoHeap->heapArray = malloc(3 * sizeof(Heap));
  nuevoHeap->size = 0;
  nuevoHeap->capac = 3;
  return nuevoHeap;
}
