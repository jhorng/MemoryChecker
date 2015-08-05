#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "MemoryDescription.h"
#include "Smalloc.h"
#include "CException.h"
#include "ErrorObject.h"

MemoryDescription *allocationHead = NULL;
MemoryDescription *allocationTail = NULL;

MemoryDescription *freeHead = NULL;
MemoryDescription *freeTail = NULL;


/**
 *
 *     -------------         --------------------
 *    | Allocation |  --->  | MemoryDescription | ----> .......
 *    -------------         --------------------
 *
 *  @breif link allocation and memory description.
 *         New memoryDescription will be added at the last.
 */
void addToList(MemoryDescription *newMemDesc){
  if (allocationHead == NULL){
    if (newMemDesc == NULL){
      printf("!!! fail to create node !!!"); // need to throwError here, pending
      return; // To ensure the code to break out.
    }

		allocationHead = newMemDesc;
    allocationTail = newMemDesc;
    return; // To ensure the code to break out.
  }

  allocationTail->next = newMemDesc;
  allocationTail = newMemDesc;
  return; // To ensure the code to break out.
}

MemoryDescription *searchInAllocPool(char *targetAddress, MemoryDescription **prev){
  MemoryDescription *searchPtr = allocationHead;
  MemoryDescription *tmp = NULL;
  int found = 0;
  // printf("\n Searching the list for value [%p] \n",targetAddress);
  while (searchPtr != NULL){
    if (searchPtr->memoryAddress == targetAddress){
      found = 1;
      break;
    }
    else{
      tmp = searchPtr;
      searchPtr = searchPtr->next;
    }
  }

  if(found == 1){
    if(prev!=NULL)
      *prev=tmp;
      return searchPtr;
  }
  else{
    return NULL;
  }
}

MemoryDescription* moveBetweenList(char *dataAddress, char *fileName, int lineNumber){
  MemoryDescription *deletionPtr = NULL;
  MemoryDescription *prevPtr     = NULL;

  deletionPtr = searchInAllocPool(dataAddress, &prevPtr);
  if(deletionPtr == NULL)
    throwError(ERR_FREE_INVALID_LOCATION,"File %s:line %d: No such location to free",fileName,lineNumber);
  if(freeHead == NULL){ //link to free pool
		freeHead = deletionPtr;
    freeTail = deletionPtr;
  }
  else{
    freeTail->next = deletionPtr;
    freeTail       = deletionPtr;
  }

  if(prevPtr != NULL)//delete maneuver
    prevPtr->next = deletionPtr->next;
   
  if(allocationHead==deletionPtr &&allocationTail==deletionPtr){
    allocationHead=allocationTail=NULL;
  }
  else if(deletionPtr == allocationTail){
    allocationTail = prevPtr;
  }
  else if(deletionPtr == allocationHead){
    allocationHead = deletionPtr->next;
  }

  free(deletionPtr);
  deletionPtr = NULL;
  return freeTail;
}