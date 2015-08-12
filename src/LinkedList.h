#ifndef LinkedList_H
#define LinkedList_H
#include "ErrorObject.h"
#include "MemoryDescription.h"

<<<<<<< HEAD
=======
#include "CException.h"

>>>>>>> 4abb9c83d10efeff51e18ec9ae9ffe3f799009a3



void addToList(MemoryDescription *newMemDesc);
MemoryDescription* searchInAllocPool(char *targetAddress,MemoryDescription **prev);
<<<<<<< HEAD
MemoryDescription* moveBetweenList(char *dataAddress, int lineNumber, char* fileName);
=======
MemoryDescription* moveBetweenList(char *dataAddress, char *fileName, int lineNumber);
MemoryDescription* passAllocPointer();
MemoryDescription* passFreePointer();
>>>>>>> 4abb9c83d10efeff51e18ec9ae9ffe3f799009a3

#endif // LinkedList_H
