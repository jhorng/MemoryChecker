#include "unity.h"
#include "MemoryDescription.h"
#include "LinkedList.h"
#include "ErrorObject.h"

void setUp(void) {}

void tearDown(void) {}

/**
 *  Values are assigned into createMallocMemDesc() and tested out.
 */
// void test_createMallocMemDesc_given_next_and_memory_both_return_NULL(){
  // MemoryDescription *newMemDesc = createMallocMemDesc(50, 500, __FILE__,);
  // TEST_ASSERT_EQUAL(50, newMemDesc->mallocLine);
  // TEST_ASSERT_EQUAL(500, newMemDesc->dataSize);
  // TEST_ASSERT_EQUAL(__FILE__, newMemDesc->mallocFile);
  // TEST_ASSERT_NULL(newMemDesc->memoryAddress);
  // TEST_ASSERT_NULL(newMemDesc->next);
// }

/**
 *  Values are assigned into createFreeMemDesc() and tested out.
 */
void test_createFreeMemDesc_given_next_and_memory_both_return_NULL(){
  MemoryDescription *newMemDesc = createFreeMemDesc(123, __FILE__);
  TEST_ASSERT_EQUAL(123, newMemDesc->freeLine);
  TEST_ASSERT_EQUAL(__FILE__, newMemDesc->freeFile);
}