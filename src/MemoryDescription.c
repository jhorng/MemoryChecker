#include <stdlib.h>
#include "MemoryDescription.h"

MemoryDescription *createMemoryDescription(int lineNumber, int sizeDefined, char *fileName){
  MemoryDescription *newMemDesc = (MemoryDescription *)malloc(sizeof(MemoryDescription));
  newMemDesc->next = NULL;
  newMemDesc->mallocLine = lineNumber;
  newMemDesc->dataSize = sizeDefined;
  newMemDesc->mallocFile = fileName;
  newMemDesc->headerAddress = NULL;
  newMemDesc->memoryAddress = NULL;
  newMemDesc->footerAddress = NULL;
  return newMemDesc;
}