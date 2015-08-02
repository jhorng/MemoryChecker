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

// void listIncreaseOrder(MemoryDescription *ptr1, MemoryDescription *ptr2){
  // Allocation *alloc = createAllocationPool();
  // MemoryDescription *ptr1, *ptr2 = (MemoryDescription *)malloc(sizeof(MemoryDescription));
  // if (ptr2->next->dataSize >= ptr1->dataSize){
    // listAddLast(alloc, );
  // }
  // else
     // listAddFirst();
// }