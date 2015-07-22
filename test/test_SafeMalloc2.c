#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "unity.h"
#include "Smalloc.h"
#include "AllocationPool.h"

void setUp(void) {}

void tearDown(void) {}

void test_allocateMemory() {
  MemoryDescription *memDesc = allocateMemory(10, 1234, "C:/ThisFile.c");

  TEST_ASSERT_NOT_NULL(memDesc);
  TEST_ASSERT_NULL(memDesc->next);
  TEST_ASSERT_EQUAL(1234, memDesc->lineNo);
  TEST_ASSERT_EQUAL_STRING("C:/ThisFile.c", memDesc->fileNameMemory);
  TEST_ASSERT_EQUAL_PTR(memDesc->memoryStor - HEADER_SIZE, memDesc->header);
  TEST_ASSERT_EQUAL_PTR(memDesc->memoryStor + memDesc->lengthOfSpace, memDesc->footer);
}
