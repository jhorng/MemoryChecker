#include <stdio.h>
#include <stdlib.h>
#include "AllocationPool.h"
#include "MemoryDescription.h"
#include "LinkedList.h"

/**
 *
 *  HEAD -----+
 *  TAIL -----|
 *           \/
 *          NULL
 *
 *  @brief create a struct node to as a head to point to the linkedlist.
 */
Allocation *createAllocationPool(){
  Allocation *alloc = (Allocation *)malloc(sizeof(Allocation));
  alloc->head = NULL;
  alloc->tail = NULL;
  alloc->noOfLinkedDesc = 0;
  return alloc;
}

/**
 *  @brief listIncreaseOrder() will arrange the list in according 
 *         to the size assigned by users.
 */
// void listIncreaseOrder(int size){
  // Allocation *alloc = createAllocationPool();
  // MemoryDescription *ptrMemDesc = (MemoryDescription *)malloc(sizeof(MemoryDescription));
  // if (alloc->head->next == NULL){
    // printf("End of linked list!\n");
  // }
  // else {
    // if (size >= ptrMemDesc->dataSize){
      // listAddLast(alloc, ptrMemDesc);
    // }
    // else {
      // listAddFirst(alloc, ptrMemDesc);
    // }
  // }
// }