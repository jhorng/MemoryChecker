#ifndef AllocationPool_H
#define AllocationPool_H

#include "MemoryDescription.h"

typedef struct{
  MemoryDescription *head;
  MemoryDescription *tail;
  int noOfLinkedDesc;
} Allocation;

Allocation *createAllocationPool();
void listIncreaseOrder(int size);

#endif // AllocationPool_H
