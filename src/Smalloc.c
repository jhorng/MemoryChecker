#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Smalloc.h"
#include "AllocationPool.h"
#include "ErrorObject.h"

/**
 *  create a memory block
 *  if size defined is larger than DATA_SIZE,
 *  throw error, ERR_EXCEED_DATA_SIZE.
 */
void *_safeMalloc(int size, int lineNumber, char *fileName){
  void *headerPtr,
       *dataPtr,
       *footerPtr;

  if(size=0)
    return NULL;
  else if(size>DATA_SIZE){
        printf("Unable to create (%d) space at line %d from file %s\n",size,lineNumber,fileName);
        Throw(ERR_EXCEED_DATA_SIZE);
  }

  void *space = (int *) malloc(sizeof(HEADER_SIZE+size+FOOTER_SIZE));

  headerPtr   = space;
  dataPtr     = space+HEADER_SIZE;
  footerPtr   = dataPtr+DATA_SIZE;
  
  fileInfo *info = malloc(sizeof(fileInfo));
  
  info->lineNumber = lineNumber;
  info->sizeDefined = size;
  info->fileName = fileName;
  info->address = dataPtr;
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

  for ( i=0,temp = pointer ; i<timesToCopy; ++i, temp+=slen){
    memcpy(temp, pattern, slen);

    if((temp+slen)>pointer+FOOTER_SIZE) break;
  }
  *temp = '\0';
}

/**
 *  link allocation and memory description
 */
void listAdd(Allocation *alloc, memoryDescription *newMemDesc){
  if(alloc->head==NULL && alloc->tail==NULL){
    alloc->head = newMemDesc;
    alloc->tail = newMemDesc;
  }
  else{
    alloc->tail->next = newMemDesc;
    alloc->tail = newMemDesc;
  }
  alloc->noOfLinkedDesc++;
}
