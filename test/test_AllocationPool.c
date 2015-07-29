#include "unity.h"
#include "AllocationPool.h"

void setUp(void) {}

void tearDown(void) {}

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