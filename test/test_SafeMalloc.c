#include <string.h>
#include "unity.h"
#include "Smalloc.h"
#include "AllocationPool.h"

void setUp(void){}

void tearDown(void){}

void test1(){
  safeMalloc();
}

/**
 *  HEAD -----+
 *  TAIL -----|
 *           \/
 *          NULL
 */
void test_createAllocationPool_given_head_and_tail_both_return_NULL(){
  Allocation *newAlloc = createAllocationPool();
  TEST_ASSERT_NULL(newAlloc->head);
  TEST_ASSERT_NULL(newAlloc->tail);
  TEST_ASSERT_EQUAL(0, newAlloc->noOfLinkedDesc);
  printf("--Allocation--\nHead: %i\nTail: %i\n", newAlloc->head, newAlloc->tail);
  printf("Number of linked memory description: %d\n\n", newAlloc->noOfLinkedDesc);
}

/**
 *  To test the function whether will work as the logic
 */
void test_createMemoryDesciption_given_next_and_memory_both_return_NULL(){
  memoryDesciption *newMemDesc = createMemoryDesciption(__LINE__, 500, __FILE__);
  TEST_ASSERT_EQUAL(500, newMemDesc->lengthOfSpace);
  TEST_ASSERT_NULL(newMemDesc->memory);
  TEST_ASSERT_NULL(newMemDesc->next);
  printf("--MemoryDescription--\nMemory: %i\n", newMemDesc->memory);
  printf("Next: %i\n", newMemDesc->next);
  printf("Line Number: %i\n", newMemDesc->lineNo);
  printf("Length of Space: %i\n", newMemDesc->lengthOfSpace);
  printf("File name: %s\n", newMemDesc->fileName);
}

void test_linkedList_given_two_memory_description_should_return_two_memory_description(){
  Allocation *newAlloc = createAllocationPool();
  linkedList(newAlloc, createMemoryDesciption(__LINE__, 400, __FILE__));
  linkedList(newAlloc, createMemoryDesciption(__LINE__, 500, __FILE__));
  // TEST_ASSERT_EQUAL(400, newAlloc->head->lengthOfSpace);
}








