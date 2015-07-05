#include <malloc.h>
#include "AllocationPool.h"
#include "Smalloc.h"

Allocation *createAllocationPool(int lineNumber, int lengthOfSpace, int fileName){
  Allocation *newAlloc = malloc(sizeof(Allocation));
  newAlloc->lineNumber = lineNumber;
  newAlloc->lengthOfSpace = lengthOfSpace;
  newAlloc->fileName = fileName;
  newAlloc->memory = NULL;
  newAlloc->next = NULL;
  return newAlloc;
}