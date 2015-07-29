#include <stdio.h>
#include "LinkedList.h"
#include "AllocationPool.h"
#include "MemoryDescription.h"

/**
 *  @breif link allocation and memory description
 */
void listAdd(Allocation *alloc, MemoryDescription *newMemDesc){
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