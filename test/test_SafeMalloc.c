#include <string.h>
#include <stdio.h>
#include "unity.h"
#include "Smalloc.h"
#include "AllocationPool.h"

void setUp(void){}

void tearDown(void){}

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

void test_repeatPattern_given_xyZa_6_times_should_have_xyZa_5times_only_in_the_memory(){
  char *memory = malloc(22);
  patternRepeat(6,"xyZa",memory);
  TEST_ASSERT_EQUAL_HEX('x', *memory);
  TEST_ASSERT_EQUAL_HEX('y', *(memory+1));
  TEST_ASSERT_EQUAL_HEX('Z', *(memory+2));
  TEST_ASSERT_EQUAL_HEX('a', *(memory+3));
  TEST_ASSERT_EQUAL_HEX('x', *(memory+4));
  TEST_ASSERT_EQUAL_HEX('y', *(memory+5));
  TEST_ASSERT_EQUAL_HEX('Z', *(memory+6));
  TEST_ASSERT_EQUAL_HEX('a', *(memory+7));
  TEST_ASSERT_EQUAL_HEX('x', *(memory+8));
  TEST_ASSERT_EQUAL_HEX('y', *(memory+9));
  TEST_ASSERT_EQUAL_HEX('Z', *(memory+10));
  TEST_ASSERT_EQUAL_HEX('a', *(memory+11));
  TEST_ASSERT_EQUAL_HEX('x', *(memory+12));
  TEST_ASSERT_EQUAL_HEX('y', *(memory+13));
  TEST_ASSERT_EQUAL_HEX('Z', *(memory+14));
  TEST_ASSERT_EQUAL_HEX('a', *(memory+15));
  TEST_ASSERT_EQUAL_HEX('x', *(memory+16));
  TEST_ASSERT_EQUAL_HEX('y', *(memory+17));
  TEST_ASSERT_EQUAL_HEX('Z', *(memory+18));
  TEST_ASSERT_EQUAL_HEX('a', *(memory+19));
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
  printf("Number of linked memoryStor description: %d\n\n", newAlloc->noOfLinkedDesc);
}

/**
 *  To test the function whether will work as the logic
 */
void test_createMemoryDesciption_given_next_and_memory_both_return_NULL(){
  memoryDesciption *newMemDesc = createMemoryDesciption(__LINE__, 500, __FILE__);
  TEST_ASSERT_EQUAL(500, newMemDesc->lengthOfSpace);
  TEST_ASSERT_NULL(newMemDesc->memoryStor);
  TEST_ASSERT_NULL(newMemDesc->next);
  printf("--MemoryDescription--\nMemory: %i\n", newMemDesc->memoryStor);
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
  printf("--MemoryDescription--\nMemory: %i\n", alloc->head->memoryStor);
  printf("Next: %i\n", alloc->head->next);
  printf("Line Number: %i\n", alloc->head->lineNo);
  printf("Length of Space: %i\n", alloc->head->lengthOfSpace);
  printf("File name: %s\n\n", alloc->head->fileNameMemory);
  printf("Total number of linked file(s): %d\n\n", alloc->noOfLinkedDesc);
}

/**
 *    ---------         ----------      ----------
 *   / alloc /  ---->  / memDesc /     / memDesc / ------+
 *  ---------         ----------      ----------        |
 *                                                      |
 *                                                     \/
 *                                                 -------
 *                                                / NULL /
 *                                               -------
 */
void test_linkedList_given_two_memory_description_should_return_two_memory_description(){
  Allocation *alloc = createAllocationPool();
  
  linkedList(alloc, createMemoryDesciption(__LINE__, 400, __FILE__));
  linkedList(alloc, createMemoryDesciption(__LINE__, 500, __FILE__));
  
  TEST_ASSERT_EQUAL(400, alloc->head->lengthOfSpace);
  TEST_ASSERT_EQUAL(500, alloc->head->next->lengthOfSpace);
  TEST_ASSERT_EQUAL(2, alloc->noOfLinkedDesc);
  TEST_ASSERT_NULL(alloc->tail->next);
  printf("--MemoryDescription[1]--\n");
  printf("memoryStor[1]: %i\n", alloc->head->memoryStor);
  printf("Next[1]: %p\n", alloc->head->next);
  printf("Line Number[1]: %i\n", alloc->head->lineNo);
  printf("Length of Space[1]: %i\n", alloc->head->lengthOfSpace);
  printf("File name[1]: %s\n\n", alloc->head->fileNameMemory);
  
  printf("--MemoryDescription[2]--\n");
  printf("memoryStor[2]: %i\n", alloc->head->next->memoryStor);
  printf("Next[2]: %i\n", alloc->head->next->next);
  printf("Line Number[2]: %i\n", alloc->head->next->lineNo);
  printf("Length of Space[2]: %i\n", alloc->head->next->lengthOfSpace);
  printf("File name[2]: %s\n\n", alloc->head->next->fileNameMemory);
  
  printf("Total number of linked file(s): %d\n\n", alloc->noOfLinkedDesc);
}





