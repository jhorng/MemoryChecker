#include <stdlib.h>
#include "unity.h"
#include "LinkedList.h"
#include "AllocationPool.h"
#include "MemoryDescription.h"

void setUp(void) {}

void tearDown(void) {}

// set Allocation as global variable
Allocation *alloc = NULL;

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

  listAdd(alloc, createMemoryDescription(1234, 400, "C:/ThisFile.c"));

  TEST_ASSERT_EQUAL(400, alloc->head->dataSize);
  TEST_ASSERT_EQUAL(1234, alloc->head->mallocLine);
  TEST_ASSERT_EQUAL("C:/ThisFile.c", alloc->head->mallocFile);
  TEST_ASSERT_EQUAL(1, alloc->noOfLinkedDesc);
  TEST_ASSERT_NULL(alloc->tail->next);
  printf("--Linked list--\n");
  printf("Next: %p\n", alloc->head->next);
  printf("Line Number: %i\n", alloc->head->mallocLine);
  printf("Length of Space: %i\n", alloc->head->dataSize);
  printf("File name: %s\n", alloc->head->mallocFile);
  printf("Memory: %p\n", alloc->head->memoryAddress);
  printf("Total number of linked file(s): %d\n\n\n", alloc->noOfLinkedDesc);
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

  listAdd(alloc, createMemoryDescription(80, 400, "C:/testFile.c"));
  listAdd(alloc, createMemoryDescription(102, 500, "C:/Dummy.c"));

  TEST_ASSERT_EQUAL(80, alloc->head->mallocLine);
  TEST_ASSERT_EQUAL(400, alloc->head->dataSize);
  TEST_ASSERT_EQUAL("C:/testFile.c", alloc->head->mallocFile);
  TEST_ASSERT_EQUAL(102, alloc->tail->mallocLine);
  TEST_ASSERT_EQUAL(500, alloc->tail->dataSize);
  TEST_ASSERT_EQUAL("C:/Dummy.c", alloc->tail->mallocFile);
  TEST_ASSERT_EQUAL(2, alloc->noOfLinkedDesc);
  TEST_ASSERT_NULL(alloc->tail->next);
  printf("--MemoryDescription[1]--\n");
  printf("Next[1]: %p\n", alloc->head->next);
  printf("Line Number[1]: %i\n", alloc->head->mallocLine);
  printf("Length of Space[1]: %i\n", alloc->head->dataSize);
  printf("File name[1]: %s\n", alloc->head->mallocFile);
  printf("Memory[1]: %p\n\n", alloc->head->memoryAddress);

  printf("--MemoryDescription[2]--\n");
  printf("Next[2]: %p\n", alloc->tail->next);
  printf("Line Number[2]: %i\n", alloc->tail->mallocLine);
  printf("Length of Space[2]: %i\n", alloc->tail->dataSize);
  printf("File name[2]: %s\n", alloc->tail->mallocFile);
  printf("memory[2]: %p\n", alloc->tail->memoryAddress);

  printf("Total number of linked file(s): %d\n\n", alloc->noOfLinkedDesc);
}