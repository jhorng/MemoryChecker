#ifndef Smalloc_H
#define Smalloc_H

#include "AllocationPool.h"

#define DATA_SIZE   100
#define HEADER_SIZE 21
#define FOOTER_SIZE 21  //HEADER_SIZE AND FOOTER_SIZE MUST BE THE SAME!!

#define safeMalloc(size) _safeMalloc(size,__LINE__,__FILE__)

void *_safeMalloc(int size,int lineNumber, char *fileName);
void patternRepeat( int timesToCopy,char *pattern, char *pointer);
void linkedList(Allocation *alloc, memoryDescription *newMemDesc);

#endif // Smalloc_H
