#include <stdio.h>
#include <malloc.h>
#include "AllocationPool.h"
#include "Smalloc.h"

Allocation *createAllocationPool(){
  Allocation *alloc = malloc(sizeof(Allocation));
  alloc->head = NULL;
  alloc->tail = NULL;
  alloc->noOfLinkedDesc = 0;
  return alloc;
}

memoryDesciption *createMemoryDesciption(int lineNo, int lengthOfSpace, char *fileNameMemory){
  memoryDesciption *newMemDesc = malloc(sizeof(memoryDesciption));
  newMemDesc->next = NULL;
  newMemDesc->lineNo = lineNo;
  newMemDesc->lengthOfSpace = lengthOfSpace;
  newMemDesc->fileNameMemory = fileNameMemory;
  newMemDesc->memoryStor = NULL;
  return newMemDesc;
}

void linkedList(Allocation *alloc, memoryDesciption *newMemDesc){
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


