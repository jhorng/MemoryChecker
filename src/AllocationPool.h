#ifndef AllocationPool_H
#define AllocationPool_H

#include "Smalloc.h"

typedef struct allocation_t Allocation;
struct allocation_t{
  int lineNumber;
  int lengthOfSpace;
  char fileName;
  Space *memory;
  Allocation *next;
};

Allocation *createAllocationPool(int lineNumber, int lengthOfSpace, int fileName);

#endif // AllocationPool_H
