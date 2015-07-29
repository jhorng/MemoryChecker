#ifndef AllocationPool_H
#define AllocationPool_H

typedef struct MemoryDescription_t MemoryDescription;
struct MemoryDescription_t{
  MemoryDescription *next;
  int lineNumber;
  int lengthOfSpace;
  char *fileNameMemory;
  char *headerAddress;
  char *memoryAddress;
  char *footerAddress;
};

typedef struct{
  MemoryDescription *head;
  MemoryDescription *tail;
  int noOfLinkedDesc;
} Allocation;

Allocation *createAllocationPool();
MemoryDescription *createMemoryDescription(int lineNo, int lengthOfSpace, char *fileNameMemory);

#endif // AllocationPool_H
