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
  
/*   printf("aaheader = %p\n", ptrMemory->headerAddress);
  printf("memory = %p\n", ptrMemory->memoryAddress);
  printf("footer = %p\n", ptrMemory->footerAddress); */
  
  patternRepeat(5, CODE_PATTERN, headerPtr);//generate pattern for header and footer
  patternRepeat(5, CODE_PATTERN, footerPtr);

  return ptrMemory;
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
  int slen = strlen(pattern);
  for ( i=0 ; i<(timesToCopy); i++){
    temp=(pointer+(i*slen));
   strcpy((temp),pattern);
    if(((i+2)*slen)>FOOTER_SIZE)//if the pattern will overflow, break from loop
      break;
  }
 // *temp = '\0';
}

/**
 *  @brief check repetitive patterns in the memory
 *  @arg
 */
void patternCheck(char *pointer){
  int checkingValue, i=-1;
  char memory[HEADER_SIZE];
  patternRepeat(5,"xyZa",memory);

  checkingValue = strcmp(memory,pointer);

  if(checkingValue!=0){
    for(i=0;i<HEADER_SIZE;i++){
      checkingValue=strncmp(memory,pointer,i);
      if(checkingValue!=0)
        break;
    }
  }
}



/**
 * @brief The main function for SafeMalloc.
 *        throwError is to prevent users enter unwanted "size" when using safeMalloc().
 */
void *_safeMalloc(int size, int lineNumber, char *fileName){
  MemoryDescription *memDesc = (MemoryDescription *)malloc(sizeof(MemoryDescription)); 
  MemoryDescription *allocAddr = (MemoryDescription *)malloc(sizeof(MemoryDescription));
  
  ///////////////////// pending
  // if(!(size>0)){
    // throwError
  // }
  //////////////////// pending
  
  allocAddr = allocateAddress(size);
  memDesc = createMallocMemDesc(lineNumber, size, fileName, allocAddr);
   addToList(memDesc);
  
  

 printf("Size: %d\n", memDesc->dataSize);
 printf("Line number: %d\n", memDesc->mallocLine);
 printf("File name: %s\n", memDesc->mallocFile);
 // return allocAddr->memoryAddress;
}