#include "Sfree.h"
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "CException.h"
#include "Smalloc.h"
#include "AllocationPool.h"
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