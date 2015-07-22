#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "CException.h"
#include "Smalloc.h"
#include "AllocationPool.h"
#include "ErrorObject.h"

void *_safeMalloc(int size, int lineNumber, char *fileName){
  void *headerPtr,
       *dataPtr,
       *footerPtr;
       
  char message[100];
       
  if(size==0)
    return NULL;
  else if(size>DATA_SIZE){
    printf(message,"Unable to create (%d) space at line %d from file %s\n",size,lineNumber,fileName);
    throwError(message, ERR_EXCEED_DATA_SIZE);
  } 

  void *space = malloc(sizeof(HEADER_SIZE+size+FOOTER_SIZE));
  
  headerPtr   = space;
  dataPtr     = space+HEADER_SIZE;
  footerPtr   = dataPtr +size;
  
  
  patternRepeat(5,CODE_PATTERN,headerPtr); 
 //patternRepeat(1,CODE_PATTERN,footerPtr); 
  

  printf("foot :%d\n",lineNumber);
  printf("foot :%s\n",fileName);
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

/**
 *  @brief check repetitive patterns in the memory
 *  @arg  
 */
void patternCheck(char *pointer){
  int checkingValue, i=-1;
  char memory[HEADER_SIZE];
  patternRepeat(5,"xyZa",memory);
  
  checkingValue =strcmp(memory,pointer);
  
  
  if(checkingValue!=0){
    for(i=0;i<HEADER_SIZE;i++){
      checkingValue=strncmp(memory,pointer,i);
      if(checkingValue!=0) 
        break;
    }
  }
  
  /* 
  printf("no%s",memory);
  printf("no%d",i); */
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