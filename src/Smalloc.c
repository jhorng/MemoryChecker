#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Smalloc.h"


void *_safeMalloc(int lineNumber, char *fileName){
  void *headerPtr,
       *dataPtr,
       *footerPtr;
       
       
  void *space = malloc(sizeof(HEADER_SIZE+DATA_SIZE+FOOTER_SIZE));
  
  headerPtr   = space;
  dataPtr     = space+HEADER_SIZE;
  footerPtr   = dataPtr +DATA_SIZE;
  
    
  printf("space:%p\n",space);
  printf("head :%p\n",headerPtr);
  printf("data :%p\n",dataPtr);
  printf("foot :%p\n",footerPtr);
  printf("foot :%d\n",lineNumber);
  printf("foot :%s\n",fileName);
  
  return;
}


/**
 *  @brief Copy repetitive patterns into memory
 *  @arg timesToCopy The number of times to copy
 *  @arg pattern     The pattern to copy to the destination
 *  @arg pointer     The destination to point to
 */
void patternRepeat(int timesToCopy, char *pattern, char *pointer) {
  strcpy(pointer,"y");
 
  printf("%c%c\n",*pointer,*(pointer+1));
  
}

