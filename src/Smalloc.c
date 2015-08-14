#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "MemoryDescription.h"
#include "LinkedList.h"
#include "CException.h"
#include "Smalloc.h"
#include "ErrorObject.h"
#include "Sfree.h"

char *headerPtr, *dataPtr, *footerPtr;

/**
 *  @brief to store the addresses of headerPtr, dataPtr and footerPtr
 *         to MemoryDescription
 */
MemoryDescription *allocateAddress(int size) {
  MemoryDescription *ptrMemory = malloc(sizeof(MemoryDescription));
  char *space = (char *)malloc(sizeof(HEADER_SIZE+size+FOOTER_SIZE));

  headerPtr   = space;
  dataPtr     = space+HEADER_SIZE;
  footerPtr   = dataPtr+size;

  ptrMemory->headerAddress = headerPtr;
  ptrMemory->memoryAddress = dataPtr;
  ptrMemory->footerAddress = footerPtr;
  
  //patternRepeat(HEADER_SIZE, CODE_PATTERN, headerPtr);//generate pattern for header and footer
  //patternRepeat(FOOTER_SIZE, CODE_PATTERN, footerPtr);

  return ptrMemory;
}


/**
 *  @brief Copy repetitive patterns into memory
 *  @arg timesToCopy The number of times to copy
 *  @arg pattern     The pattern to copy to the destination
 *  @arg pointer     The destination to point to
 */
void patternRepeat(int timesToCopy, char *pattern, char *pointer){
  int i;
  int slen = strlen(pattern);
  for ( i=0 ; i<(timesToCopy); i++){
   strcpy((pointer+i),pattern);
  }
}

/**
 *  @brief check repetitive patterns in the memory
 *  @arg
 */
int patternCheck(char *pointer, int sizeNeedCheck, char *pattern){
  int checkResult, numberOfDuplication,i=0;
  char tempMemory[sizeNeedCheck];
  
  if(pattern ==CODE_PATTERN)
    numberOfDuplication =5;
  else
    numberOfDuplication =sizeNeedCheck;
  
  patternRepeat(numberOfDuplication, pattern, tempMemory);
  
  checkResult = strcmp(tempMemory,pointer);
  
  
  if(checkResult !=0){
    for(i=0; i<sizeNeedCheck; i++){
       checkResult = strncmp(tempMemory, pointer, i);
       if(checkResult != 0)
         return i;
    }
  }
  
  return PASS_TICKET;//-20 value means all pass.
}



/**
 * @brief The main function for SafeMalloc.
 *        throwError is to prevent users enter unwanted "size" when using safeMalloc().
 */
void *_safeMalloc(int size, int lineNumber, char *fileName){

  MemoryDescription *memDesc = (MemoryDescription *)malloc(sizeof(MemoryDescription)); 
  MemoryDescription *allocAddr =(MemoryDescription *)malloc(sizeof(MemoryDescription));
  
  allocAddr = allocateAddress(size);
  memDesc = createMallocMemDesc(lineNumber, size, fileName, allocAddr);
  addToList(memDesc);
  
  return allocAddr->memoryAddress;
}