#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "CException.h"
#include "Smalloc.h"
#include "AllocationPool.h"
#include "ErrorObject.h"
#include "MemoryDescription.h"

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
 */

void *_safeMalloc(int size, int lineNumber, char *fileName){
  MemoryDescription *memDesc, *allocAddr;

  memDesc = createMallocMemDesc(lineNumber, size, fileName);
  allocAddr = allocateAddress(size);
  
  printf("Size: %d\n", memDesc->dataSize);
  printf("Line number: %d\n", memDesc->mallocLine);
  printf("File name: %s\n", memDesc->mallocFile);
  
  // patternRepeat(5,CODE_PATTERN,headerPtr);
  // patternRepeat(1,CODE_PATTERN,footerPtr);
}