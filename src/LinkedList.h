#ifndef LinkedList_H
#define LinkedList_H

#include "AllocationPool.h"

void addToList(MemoryDescription *newMemDesc);//finux
void listAddFirst(Allocation *alloc, MemoryDescription *newMemDesc);
MemoryDescription* searchInAllocPool(char *targetAddress,MemoryDescription **prev);//finux
MemoryDescription* moveBetweenList(char *dataAddress);

#endif // LinkedList_H
