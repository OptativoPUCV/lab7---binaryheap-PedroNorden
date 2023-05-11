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
  return pq->heapArray->data;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size == pq->capac)
  {
     pq->heapArray = realloc(pq->heapArray, pq->capac*2+1);
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
