#include <stdio.h>
#include <malloc.h>
#include "AllocationPool.h"
#include "Smalloc.h"

Allocation *createAllocationPool(){
  Allocation *alloc = malloc(sizeof(Allocation));
  alloc->head = NULL;
  alloc->tail = NULL;
  alloc->noOfLinkedDesc = 0;
  return alloc;
}

memoryDescription *createMemoryDescription(int lineNo, int lengthOfSpace, char *fileNameMemory){
  memoryDescription *newMemDesc = malloc(sizeof(memoryDescription));
  newMemDesc->next = NULL;
  newMemDesc->lineNo = lineNo;
  newMemDesc->lengthOfSpace = lengthOfSpace;
  newMemDesc->fileNameMemory = fileNameMemory;
  newMemDesc->memoryStor = NULL;
  return newMemDesc;
}