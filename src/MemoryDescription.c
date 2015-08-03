#include <stdlib.h>
#include "MemoryDescription.h"

/**
 * @brief This function stores the values of safeMalloc().
 */
MemoryDescription *createMallocMemDesc(int mallocLine, int sizeDefined, char *mallocFile,MemoryDescription *allocAddr){
  MemoryDescription *mallocMemDesc = (MemoryDescription *)malloc(sizeof(MemoryDescription));
  mallocMemDesc->next          = NULL;
  mallocMemDesc->mallocLine    = mallocLine;
  mallocMemDesc->dataSize      = sizeDefined;
  mallocMemDesc->mallocFile    = mallocFile;
  mallocMemDesc->headerAddress = allocAddr->headerAddress;
  mallocMemDesc->memoryAddress = allocAddr->memoryAddress;
  mallocMemDesc->footerAddress = allocAddr->footerAddress;
  mallocMemDesc->freeLine      = 0;
  mallocMemDesc->freeFile      = NULL;
  return mallocMemDesc;
}

/**
 *  @brief This function stores the values of safeFree().
 */
MemoryDescription *createFreeMemDesc(int freeLine, char *freeFile){
  MemoryDescription *freeMemDesc = (MemoryDescription *)malloc(sizeof(MemoryDescription));
  freeMemDesc->freeLine = freeLine;
  freeMemDesc->freeFile = freeFile;
  return freeMemDesc;
}