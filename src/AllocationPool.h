#ifndef AllocationPool_H
#define AllocationPool_H

typedef struct memoryDescription_t memoryDescription;
struct memoryDescription_t{
  memoryDescription *next;
  int lineNo;
  int lengthOfSpace;
  char *fileNameMemory;
  void *memoryStor;
};

typedef struct{
  memoryDescription *head;
  memoryDescription *tail;
  int noOfLinkedDesc;
} Allocation;

Allocation *createAllocationPool();
memoryDescription *createMemoryDescription(int lineNo, int lengthOfSpace, char *fileNameMemory);

#endif // AllocationPool_H
