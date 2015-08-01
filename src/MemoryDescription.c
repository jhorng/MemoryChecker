#include <stdlib.h>
#include "MemoryDescription.h"

/**
 * @brief This function stores the values of safeMalloc().
 */
MemoryDescription *createMallocMemDesc(int mallocLine, int sizeDefined, char *mallocFile){
  MemoryDescription *mallocMemDesc = (MemoryDescription *)malloc(sizeof(MemoryDescription));
  mallocMemDesc->next = NULL;
  mallocMemDesc->mallocLine = mallocLine;
  mallocMemDesc->dataSize = sizeDefined;
  mallocMemDesc->mallocFile = mallocFile;
  mallocMemDesc->headerAddress = NULL;
  mallocMemDesc->memoryAddress = NULL;
  mallocMemDesc->footerAddress = NULL;
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