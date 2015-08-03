#include <stdlib.h>
#include <string.h>
#include "Sfree.h"
#include "ErrorObject.h"
#include "MemoryDescription.h"
#include "LinkedList.h"


void *_safeFree(char *dataAddress, int lineNumber, char *fileName){
  MemoryDescription *freePtr;

  freePtr=moveBetweenList(dataAddress);
  freePtr->freeLine      =lineNumber;
  freePtr->freeFile      =fileName;
  patternRepeat(freePtr->dataSize, "#", freePtr->memoryAddress);
}