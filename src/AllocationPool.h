#ifndef AllocationPool_H
#define AllocationPool_H

#include "Smalloc.h"

typedef struct memoryDesciption_t memoryDesciption;
struct memoryDesciption_t{
  memoryDesciption *next;
  int lineNo;
  int lengthOfSpace;
  char *fileNameMemory;
  void *memory;
};

typedef struct{
  memoryDesciption *head;
  memoryDesciption *tail;
  int noOfLinkedDesc;
} Allocation;

Allocation *createAllocationPool();
memoryDesciption *createMemoryDesciption(int lineNo, int lengthOfSpace, char *fileNameMemory);
void linkedList(Allocation *alloc, memoryDesciption *newMemDesc);

#endif // AllocationPool_H
