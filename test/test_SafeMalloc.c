#include <string.h>
#include "unity.h"
#include "Smalloc.h"
#include "AllocationPool.h"

void setUp(void){}

void tearDown(void){}

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
  printf("File name: %s\n\n", newMemDesc->fileNameMemory);
}

/**
 *    ---------         ----------
 *   / alloc /  ---->  / memDesc / ------+
 *  ---------         ----------         |
 *                                      \/
 *                                    -------
 *                                   / NULL /
 *                                  -------
 */
void test_linkedList_given_one_memory_description_should_return_one_memory_description(){
  Allocation *alloc = createAllocationPool();
  
  linkedList(alloc, createMemoryDesciption(__LINE__, 400, __FILE__));
  
  TEST_ASSERT_EQUAL(400, alloc->head->lengthOfSpace);
  TEST_ASSERT_NULL(alloc->head->next);
  TEST_ASSERT_NULL(alloc->head->memory);
  printf("--MemoryDescription--\nMemory: %i\n", alloc->head->memory);
  printf("Next: %i\n", alloc->head->next);
  printf("Line Number: %i\n", alloc->head->lineNo);
  printf("Length of Space: %i\n", alloc->head->lengthOfSpace);
  printf("File name: %s\n\n", alloc->head->fileNameMemory);
}

void test_linkedList_given_two_memory_description_should_return_two_memory_description(){
  Allocation *alloc = createAllocationPool();
  
  linkedList(alloc, createMemoryDesciption(__LINE__, 400, __FILE__));
  linkedList(alloc, createMemoryDesciption(__LINE__, 500, __FILE__));
  
  TEST_ASSERT_EQUAL(400, alloc->head->lengthOfSpace);
  TEST_ASSERT_EQUAL(500, alloc->head->next->lengthOfSpace);
  TEST_ASSERT_NULL(alloc->tail->next);
  printf("--MemoryDescription[1]--\n");
  printf("Memory[1]: %i\n", alloc->head->memory);
  printf("Next[1]: %i\n", alloc->head->memory);
  printf("Line Number[1]: %i\n", alloc->head->lineNo);
  printf("Length of Space[1]: %i\n", alloc->head->lengthOfSpace);
  printf("File name[1]: %s\n\n", alloc->head->fileNameMemory);
  
  printf("--MemoryDescription[2]--\n");
  printf("Memory[2]: %i\n", alloc->head->next->memory);
  printf("Next[2]: %i\n", alloc->head->next->next);
  printf("Line Number[2]: %i\n", alloc->head->next->lineNo);
  printf("Length of Space[2]: %i\n", alloc->head->next->lengthOfSpace);
  printf("File name[2]: %s\n\n", alloc->head->next->fileNameMemory);
}





