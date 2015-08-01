#include <stdio.h>
#include "LinkedList.h"
#include "AllocationPool.h"
#include "MemoryDescription.h"

/**
 *
 *     -------------         --------------------
 *    | Allocation |  --->  | MemoryDescription | ----> .......
 *    -------------         --------------------
 *
 *  @breif link allocation and memory description.
 *         New memoryDescription will be added at the last.
 */
void listAddLast(Allocation *alloc, MemoryDescription *newMemDesc){
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