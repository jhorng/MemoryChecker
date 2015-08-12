#include <stdlib.h>
#include <string.h>
#include "Sfree.h"
#include "ErrorObject.h"
#include "MemoryDescription.h"
#include "LinkedList.h"
#include "CException.h"

#include "CException.h"


void *_safeFree(char *dataAddress, int lineNumber, char *fileName){
  MemoryDescription *freePtr;
  ErrorObject *err; 
  
  int iHeader=-1,iFooter=-1;
  Try{
    freePtr=moveBetweenList(dataAddress, fileName, lineNumber);
  //no error will do below designation
    freePtr->freeLine      =lineNumber;
    freePtr->freeFile      =fileName;
    patternRepeat(freePtr->dataSize, "#", freePtr->memoryAddress);
    iHeader = patternCheck(freePtr->headerAddress, HEADER_SIZE, CODE_PATTERN);
    iFooter = patternCheck(freePtr->footerAddress, FOOTER_SIZE, CODE_PATTERN);
  
    if(iHeader != PASS_TICKET){
      printf("File:%p:%d: note: Memory's header integrity violated when freed@column:%d",fileName,lineNumber,iHeader);   
    }
  
    if(iFooter != PASS_TICKET){
      printf("File:%p:%d: note: Memory's footer integrity violated when freed@column:%d",fileName,lineNumber,iFooter);   
    }
  
  }Catch(err){
    printf("Error: %s\n", err->errorMsg);
    freeError(err);
  }

}