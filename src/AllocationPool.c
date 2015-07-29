#include <stdlib.h>
#include "AllocationPool.h"
#include "MemoryDescription.h"

Allocation *createAllocationPool(){
  Allocation *alloc = (Allocation *)malloc(sizeof(Allocation));
  alloc->head = NULL;
  alloc->tail = NULL;
  alloc->noOfLinkedDesc = 0;
  return alloc;
}

// listAdd(Allocation *alloc, MemoryDescription *newMemDesc);