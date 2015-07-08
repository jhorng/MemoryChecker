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

memoryDesciption *createMemoryDesciption(int lineNo, int lengthOfSpace, char *fileName){
  memoryDesciption *newMemDesc = malloc(sizeof(Allocation));
  newMemDesc->next = NULL;
  newMemDesc->lineNo = lineNo;
  newMemDesc->lengthOfSpace = lengthOfSpace;
  newMemDesc->fileName = fileName;
  newMemDesc->memory = NULL;
  return newMemDesc;
}

void linkedList(Allocation *alloc, memoryDesciption *newMemDesc){
  if (alloc == NULL){
    printf("Allocation cannot be NULL!");
  }
  else if (newMemDesc = NULL)
    printf("Memory description cannot be NULL!");
  else{
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
}