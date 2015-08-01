#include "unity.h"
#include "AllocationPool.h"
#include "MemoryDescription.h"
#include "LinkedList.h"


void setUp(void) {}

void tearDown(void) {}

Allocation *alloc = NULL;

/**
 *  HEAD -----+
 *  TAIL -----|
 *           \/
 *          NULL
 */
void test_createAllocationPool_given_head_and_tail_both_return_NULL(){
  alloc = createAllocationPool();
  TEST_ASSERT_NULL(alloc->head);
  TEST_ASSERT_NULL(alloc->tail);
  TEST_ASSERT_EQUAL(0, alloc->noOfLinkedDesc);
}

// void test_check_listIncreaseOrder_given_size_100_and_200_should_return_100_then_200(){
  // alloc=createAllocationPool();
  // listIncreaseOrder(100, 200);
  // TEST_ASSERT_EQUAL(100, alloc->head->dataSize);
  // TEST_ASSERT_EQUAL(200, alloc->tail->dataSize);
// }