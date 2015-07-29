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

MemoryDescription *createMemoryDescription(int lineNumber, int sizeDefined, char *fileName){
  MemoryDescription *newMemDesc = (MemoryDescription *)malloc(sizeof(MemoryDescription));
  newMemDesc->next = NULL;
  newMemDesc->lineNumber = lineNumber;
  newMemDesc->lengthOfSpace = sizeDefined;
  newMemDesc->fileNameMemory = fileName;
  newMemDesc->headerAddress = NULL;
  newMemDesc->memoryAddress = NULL;
  newMemDesc->footerAddress = NULL;
  return newMemDesc;
}