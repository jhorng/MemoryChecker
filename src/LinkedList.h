#ifndef LinkedList_H
#define LinkedList_H

#include "MemoryDescription.h"




void addToList(MemoryDescription *newMemDesc);
MemoryDescription* searchInAllocPool(char *targetAddress,MemoryDescription **prev);
MemoryDescription* moveBetweenList(char *dataAddress, int lineNumber, char* fileName);

#endif // LinkedList_H
