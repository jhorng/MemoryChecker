#include <stdio.h>
#include "LinkedList.h"
#include "AllocationPool.h"
#include "MemoryDescription.h"
#include "Smalloc.h"
#include <malloc.h>

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
void addToList(MemoryDescription *newMemDesc){//finux
   if( allocationHead== NULL){
        if(newMemDesc == NULL){
            printf("!!! fail to create node !!!");//need to throwError here,pending
                  return;
          }

		allocationHead = newMemDesc;
    allocationTail = newMemDesc;
    return; 
    }

    allocationTail->next = newMemDesc;
    allocationTail = newMemDesc;
    return; 
}

MemoryDescription* searchInAllocPool(char *targetAddress,MemoryDescription **prev){
    MemoryDescription *searchPtr = allocationHead;
    MemoryDescription *tmp = NULL;
    int found = 0;
   // printf("\n Searching the list for value [%p] \n",targetAddress);
  while(searchPtr != NULL){
    if(searchPtr->memoryAddress == targetAddress){
      found = 1;
      break;
    }else{
      tmp = searchPtr;
      searchPtr = searchPtr->next;
    }
  }

  if(found == 1){
    if(prev!=NULL)
      *prev=tmp;
      return searchPtr;
  }else{
    return NULL;
  }
}

MemoryDescription* moveBetweenList(char *dataAddress){
  MemoryDescription *deletionPtr = NULL;
  MemoryDescription *prevPtr     = NULL;
  
  deletionPtr = searchInAllocPool(dataAddress,&prevPtr);
  if(deletionPtr== NULL)
  // throwError(ERR_FREE_INVALID_LOCATION,"File %s:line %d: No such location to free",fileName,lineNumber);
              
  if( freeHead== NULL){//passing to free pool
		freeHead = deletionPtr;
    freeTail = deletionPtr;
  }else{
    freeTail->next = deletionPtr;
    freeTail       = deletionPtr;
  }
  
  if(prevPtr != NULL)//delete maneuver
    prevPtr->next = deletionPtr->next;

  if(deletionPtr == allocationTail){
    allocationTail = prevPtr;
  }else if(deletionPtr == allocationHead){
     allocationHead = deletionPtr->next;
  }
  
  free(deletionPtr);
  deletionPtr = NULL;
  return freeTail;
  
  
}






/**
 *
 *     -------------         -----------------------         -----------------------
 *    | Allocation |  --->  | MemoryDescription(2) | ---->  | MemoryDescription(1) | ----> ......
 *    -------------         -----------------------         -----------------------
 *
 *  @breif link allocation and memory description.
 *         New memoryDescription will be added at the first description.
 */
void listAddFirst(Allocation *alloc, MemoryDescription *newMemDesc){
  if(alloc->head==NULL && alloc->tail==NULL){
    alloc->head = newMemDesc;
    alloc->tail = newMemDesc;
  }
  else{
    newMemDesc->next=alloc->head;
    alloc->head=newMemDesc;
  }
  alloc->noOfLinkedDesc++;
}


