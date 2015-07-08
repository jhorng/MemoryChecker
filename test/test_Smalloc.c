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
  TEST_ASSERT_EQUAL_HEX('y', memory);
}


void test_safeMalloc(){
  
    safeMalloc();
    
}