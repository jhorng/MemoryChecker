#ifndef LinkedList_H
#define LinkedList_H
#include "ErrorObject.h"
#include "MemoryDescription.h"

#include "CException.h"




void addToList(MemoryDescription *newMemDesc);
MemoryDescription* searchInAllocPool(char *targetAddress,MemoryDescription **prev);
MemoryDescription* moveBetweenList(char *dataAddress, char *fileName, int lineNumber);

#endif // LinkedList_H
