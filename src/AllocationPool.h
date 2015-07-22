#ifndef AllocationPool_H
#define AllocationPool_H

typedef struct MemoryDescription_t MemoryDescription;
struct MemoryDescription_t{
  MemoryDescription *next;
  int lineNo;
  int lengthOfSpace;
  char *fileNameMemory;
  char *header;
  char *memoryStor;
  char *footer;
};

typedef struct{
  MemoryDescription *head;
  MemoryDescription *tail;
  int noOfLinkedDesc;
} Allocation;

Allocation *createAllocationPool();
MemoryDescription *createMemoryDescription(int lineNo, int lengthOfSpace, char *fileNameMemory);

#endif // AllocationPool_H
