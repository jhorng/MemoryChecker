#ifndef Smalloc_H
#define Smalloc_H

#include "LinkedList.h"

#include "MemoryDescription.h"
#define HEADER_SIZE 21 
#define FOOTER_SIZE 21  
#define CODE_PATTERN "#"// limited to one character only

#define PASS_TICKET -20

#define safeMalloc(size) _safeMalloc(size,__LINE__,__FILE__)

MemoryDescription *allocateAddress(int size);

void *_safeMalloc(int size, int lineNumber, char *fileName);
void patternRepeat(int timesToCopy, char *pattern, char *pointer);
int patternCheck(char *pointer, int sizeNeedCheck, char *pattern);

#endif // Smalloc_H
