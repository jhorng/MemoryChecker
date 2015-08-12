#include <stdlib.h>
#include <string.h>
#include "Sfree.h"
#include "ErrorObject.h"
#include "MemoryDescription.h"
#include "LinkedList.h"
#include "CException.h"


void *_safeFree(char *dataAddress, int lineNumber, char *fileName){
  MemoryDescription *freePtr;
  ErrorObject *err; 

  Try{//bad memory access
  //freePtr=moveBetweenList(dataAddress, lineNumber, fileName);
  }Catch(err){
   printf("Error: %s\n", err->errorMsg);
   freeError(err);
  }
  
  freePtr->freeLine      =lineNumber;
  freePtr->freeFile      =fileName;
  patternRepeat(freePtr->dataSize, "#", freePtr->memoryAddress);
  
  
}