#include "unity.h"
#include "MemoryDescription.h"

void setUp(void) {}

void tearDown(void) {}

/**
 *  To test the memoryDescription whether will work as the logic
 */
void test_createMemoryDescription_given_next_and_memory_both_return_NULL(){
  MemoryDescription *newMemDesc = createMemoryDescription(__LINE__, 500, __FILE__);
  TEST_ASSERT_EQUAL(500, newMemDesc->dataSize);
  TEST_ASSERT_NULL(newMemDesc->memoryAddress);
  TEST_ASSERT_NULL(newMemDesc->next);
}