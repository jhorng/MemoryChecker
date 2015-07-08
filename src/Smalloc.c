#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Smalloc.h"


void *_safeMalloc(int size,int lineNumber, char *fileName){
  void *headerPtr = HEADER_SIZE,
       *dataPtr   = DATA_SIZE,
       *footerPtr = FOOTER_SIZE;
       
       
  void *space = malloc(sizeof(HEADER_SIZE+DATA_SIZE+FOOTER_SIZE));
  
  headerPtr   = space;
  dataPtr     = space+headerSize;
  footerPtr   = dataPtr +dataSize;
  
    
  printf("space:%p\n",space);
  printf("head :%p\n",headerPtr);
  printf("data :%p\n",dataPtr);
  printf("foot :%p\n",footerPtr);
  
  return;
}


/**
 *  @brief Copy repetitive patterns into memory
 *  @arg timesToCopy The number of times to copy
 *  @arg pattern     The pattern to copy to the destination
 *  @arg pointer     The destination to point to
 */
void patternRepeat(int timesToCopy, char *pattern, char *pointer) {
  *pointer="xx";
  printf("%x\n",*pointer);
  
}

