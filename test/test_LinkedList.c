#include <stdlib.h>
#include "unity.h"
#include "LinkedList.h"
#include "MemoryDescription.h"
#include "ErrorObject.h"

void setUp(void) {}

void tearDown(void) {}

extern MemoryDescription *allocationHead;
extern MemoryDescription *allocationTail;

extern MemoryDescription *freeHead;
extern MemoryDescription *freeTail;

/**
 *    ---------         ----------
 *   / alloc /  ---->  / memDesc / ------+
 *  ---------         ----------         |
 *                                      \/
 *                                    -------
 *                                   / NULL /
 *                                  -------
 */
void test_listAddLast_given_one_memory_description_should_return_one_memory_description(){
  char name = 'C';
  MemoryDescription *ptrAddress = malloc(sizeof(MemoryDescription));
  ptrAddress->memoryAddress = &name;
  
  addToList(createMallocMemDesc(1234, 400, "C:/ThisFile.c", ptrAddress));

  TEST_ASSERT_EQUAL(400, allocationHead->dataSize);
  TEST_ASSERT_EQUAL(1234, allocationHead->mallocLine);
  TEST_ASSERT_EQUAL("C:/ThisFile.c", allocationHead->mallocFile);
  TEST_ASSERT_EQUAL(&name, allocationHead->memoryAddress);
  TEST_ASSERT_NULL(allocationTail->next);
  allocationHead = NULL;
  allocationTail = NULL;
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
void test_listAddLast_given_two_memory_description_should_return_two_memory_description(){
  char letter1 = 'D';
  char letter2 = 'E';
  MemoryDescription *ptrAddress1 = malloc(sizeof(MemoryDescription));
  MemoryDescription *ptrAddress2 = malloc(sizeof(MemoryDescription));
  ptrAddress1->memoryAddress = &letter1;
  ptrAddress2->memoryAddress = &letter2;

  addToList(createMallocMemDesc(80, 400, "C:/testFile.c", ptrAddress1));
  addToList(createMallocMemDesc(102, 500, "C:/Dummy.c", ptrAddress2));

  TEST_ASSERT_EQUAL(80, allocationHead->mallocLine);
  TEST_ASSERT_EQUAL(400, allocationHead->dataSize);
  TEST_ASSERT_EQUAL("C:/testFile.c", allocationHead->mallocFile);
  TEST_ASSERT_EQUAL(&letter1, allocationHead->memoryAddress);
  TEST_ASSERT_EQUAL(102, allocationTail->mallocLine);
  TEST_ASSERT_EQUAL(500, allocationTail->dataSize);
  TEST_ASSERT_EQUAL("C:/Dummy.c", allocationTail->mallocFile);
  TEST_ASSERT_EQUAL(&letter2, allocationTail->memoryAddress);
  TEST_ASSERT_NULL(allocationTail->next);
  allocationHead = NULL;
  allocationTail = NULL;
}
