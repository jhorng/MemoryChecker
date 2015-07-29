#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "unity.h"
#include "Smalloc.h"
#include "MemoryDescription.h"

extern char *headerPtr, *dataPtr, *footerPtr;

void setUp(void) {}

void tearDown(void) {}

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

void test_the_function_of_allocateAddress(){
  MemoryDescription *address = allocateAddress(10);
  TEST_ASSERT_NOT_NULL(address);
  TEST_ASSERT_EQUAL_PTR(headerPtr, address->headerAddress);
  TEST_ASSERT_EQUAL_PTR(dataPtr, address->memoryAddress);
  TEST_ASSERT_EQUAL_PTR(footerPtr, address->footerAddress);
}

void test_safeMalloc(){
  safeMalloc(10);
  // TEST_ASSERT_EQUAL(10, smalloc->lengthOfSpace);
}

