#ifndef AllocationPool_H
#define AllocationPool_H

typedef struct memoryDescription_t memoryDescription;
typedef struct memoryDescription_t MemoryDescription;
struct memoryDescription_t{
  memoryDescription *next;
  int lineNo;
  int lengthOfSpace;
  char *fileNameMemory;
  char *header;
  char *memoryStor;
  char *footer;
};

typedef struct{
  memoryDescription *head;
  memoryDescription *tail;
  int noOfLinkedDesc;
} Allocation;

Allocation *createAllocationPool();
memoryDescription *createMemoryDescription(int lineNo, int lengthOfSpace, char *fileNameMemory);

#endif // AllocationPool_H
