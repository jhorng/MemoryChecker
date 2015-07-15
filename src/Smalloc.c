#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "CException.h"
#include "Smalloc.h"

#include "ErrorCode.h"



void *_safeMalloc(int size,int lineNumber, char *fileName){
  void *headerPtr,
       *dataPtr,
       *footerPtr;
       
  if(size=0)
    return NULL;
  else if(size>DATA_SIZE){
        printf("Unable to create (%d) space at line %d from file %s\n",size,lineNumber,fileName);
        Throw(ERR_EXCEED_DATA_SIZE);
    } 
    
       
       
  void *space = malloc(sizeof(HEADER_SIZE+size+FOOTER_SIZE));
  
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
void patternRepeat(int timesToCopy, char *pattern, char *pointer){
  char *temp;
  int i;
  size_t slen = strlen(pattern);
  
 // printf("%d\n",patternLength);
  for ( i=0,temp = pointer ; i<timesToCopy; ++i, temp+=slen){
    memcpy(temp, pattern, slen);
    
    if((temp+slen)>pointer+FOOTER_SIZE) break;
  }
  *temp = '\0';

  
}
