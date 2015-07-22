#include <stdio.h>
#include <malloc.h>
#include "AllocationPool.h"
#include "Smalloc.h"

Allocation *createAllocationPool(){
  Allocation *alloc = (Allocation *)malloc(sizeof(Allocation));
  alloc->head = NULL;
  alloc->tail = NULL;
  alloc->noOfLinkedDesc = 0;
  return alloc;
}

memoryDescription *createMemoryDescription(int lineNumber, int sizeDefined, char *fileName){
  memoryDescription *newMemDesc = (memoryDescription *)malloc(sizeof(memoryDescription));
  newMemDesc->next = NULL;
  newMemDesc->lineNo = lineNumber;
  newMemDesc->lengthOfSpace = sizeDefined;
  newMemDesc->fileNameMemory = fileName;
  newMemDesc->memoryStor = NULL;
  return newMemDesc;
}