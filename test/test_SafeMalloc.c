#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "unity.h"
#include "Smalloc.h"
#include "AllocationPool.h"

void setUp(void) {}

void tearDown(void) {}

// set Allocation as global variable
Allocation *alloc = NULL;

void test_repeatPattern_given_x_pattern_with_1_times_should_have_x_in_the_memory(){
  char *memory = malloc(20);
  patternRepeat(1,"x",memory);
  TEST_ASSERT_EQUAL_HEX('x', *memory);
}

void test_repeatPattern_given_x_pattern_with_2_times_should_have_xx_in_the_memory(){
  char *memory = malloc(20);
  patternRepeat(2,"xx",memory);
  TEST_ASSERT_EQUAL_HEX('x', *memory);
  TEST_ASSERT_EQUAL_HEX('x', *(memory+1));
  TEST_ASSERT_EQUAL_HEX('x', *(memory+2));
  TEST_ASSERT_EQUAL_HEX('x', *(memory+3));
}

void test_repeatPattern_given_xy_pattern_with_2_times_should_have_xyxy_in_the_memory(){
  char *memory = malloc(20);
  patternRepeat(2,"xy",memory);
  TEST_ASSERT_EQUAL_HEX('x', *memory);
  TEST_ASSERT_EQUAL_HEX('y', *(memory+1));
  TEST_ASSERT_EQUAL_HEX('x', *(memory+2));
  TEST_ASSERT_EQUAL_HEX('y', *(memory+3));
}

void test_repeatPattern_given_xyZa_1_time_should_have_xyZa_1time_only_in_the_memory(){
  char *memory = malloc(20);
  patternRepeat(1,"xyZa",memory);
  TEST_ASSERT_EQUAL_HEX('x', *memory);
  TEST_ASSERT_EQUAL_HEX('y', *(memory+1));
  TEST_ASSERT_EQUAL_HEX('Z', *(memory+2));
  TEST_ASSERT_EQUAL_HEX('a', *(memory+3));
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
}

/**
 *  To test the memoryDescription whether will work as the logic
 */
void test_createMemoryDescription_given_next_and_memory_both_return_NULL(){
  MemoryDescription *newMemDesc = createMemoryDescription(__LINE__, 500, __FILE__);
  TEST_ASSERT_EQUAL(500, newMemDesc->lengthOfSpace);
  TEST_ASSERT_NULL(newMemDesc->memoryAddress);
  TEST_ASSERT_NULL(newMemDesc->next);
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
  alloc = createAllocationPool();

  listAdd(alloc, createMemoryDescription(__LINE__, 400, __FILE__));

  TEST_ASSERT_EQUAL(400, alloc->head->lengthOfSpace);
  TEST_ASSERT_NULL(alloc->tail->next);
  printf("--Linked list--\n");
  printf("Next: %p\n", alloc->head->next);
  printf("Line Number: %i\n", alloc->head->lineNumber);
  printf("Length of Space: %i\n", alloc->head->lengthOfSpace);
  printf("File name: %s\n", alloc->head->fileNameMemory);
  printf("Memory: %p\n", alloc->head->memoryAddress);
  printf("Total number of linked file(s): %d\n\n", alloc->noOfLinkedDesc);
}

/**
 *    ---------         ----------        ----------
 *   / alloc /  ---->  / memDesc / ----> / memDesc / ------+
 *  ---------         ----------        ----------        |
 *                                                       |
 *                                                      \/
 *                                                   -------
 *                                                  / NULL /
 *                                                 -------
 */
void test_linkedList_given_two_memory_description_should_return_two_memory_description(){
  alloc = createAllocationPool();

  listAdd(alloc, createMemoryDescription(__LINE__, 400, __FILE__));
  listAdd(alloc, createMemoryDescription(__LINE__, 500, __FILE__));

  TEST_ASSERT_EQUAL(400, alloc->head->lengthOfSpace);
  TEST_ASSERT_EQUAL(500, alloc->head->next->lengthOfSpace);
  TEST_ASSERT_EQUAL(2, alloc->noOfLinkedDesc);
  TEST_ASSERT_NULL(alloc->tail->next);
  printf("--MemoryDescription[1]--\n");
  printf("Next[1]: %p\n", alloc->head->next);
  printf("Line Number[1]: %i\n", alloc->head->lineNumber);
  printf("Length of Space[1]: %i\n", alloc->head->lengthOfSpace);
  printf("File name[1]: %s\n", alloc->head->fileNameMemory);
  printf("Memory[1]: %p\n\n", alloc->head->memoryAddress);

  printf("--MemoryDescription[2]--\n");
  printf("Next[2]: %p\n", alloc->tail->next);
  printf("Line Number[2]: %i\n", alloc->tail->lineNumber);
  printf("Length of Space[2]: %i\n", alloc->tail->lengthOfSpace);
  printf("File name[2]: %s\n", alloc->tail->fileNameMemory);
  printf("memory[2]: %p\n\n", alloc->tail->memoryAddress);

  printf("Total number of linked file(s): %d\n\n", alloc->noOfLinkedDesc);
}

void test_allocateAddress() {
  MemoryDescription *address = allocateAddress(10);
  TEST_ASSERT_NOT_NULL(address);
  // TEST_ASSERT_EQUAL_PTR(address->memoryStor - HEADER_SIZE, address->header);
  // TEST_ASSERT_EQUAL_PTR(address->memoryStor + address->lengthOfSpace, address->footer);
  printf("Header address: %p\n", address->headerAddress);
}


