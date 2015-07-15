#include <string.h>
#include <malloc.h>
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




void test_safeMalloc_if_NULL_return_NULL(){
    safeMalloc(0);
   // TEST_ASSERT_EQUAL();
    
}