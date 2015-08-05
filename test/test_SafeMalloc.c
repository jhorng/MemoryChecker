#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "unity.h"
#include "Smalloc.h"
#include "MemoryDescription.h"
#include "ErrorObject.h"
#include "LinkedList.h"

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


void test_repeatPattern_given_xyZa_6_times_should_have_xyZa_5times_only_in_the_memory(){
  char *memory = malloc(21); // This is essential for testing overflow
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
  TEST_ASSERT_EQUAL_HEX(NULL, *(memory+20));
  
 
}

/**
 *    ---------         ----------
 *   / alloc /  ---->  / memDesc / ------+
 *  ---------         ----------         |
 *                                      \/
 *                                    -------
 *                                   / NULL /
 *                                  -------
 */
/* void test_linkedList_given_one_memory_description_should_return_one_memory_description(){
  addToList(createMemoryDescription(__LINE__, 400, __FILE__));

  TEST_ASSERT_EQUAL(400, alloc->head->lengthOfSpace);
  TEST_ASSERT_NULL(alloc->tail->next);
  printf("--Linked list--\n");
  printf("Next: %p\n", alloc->head->next);
  printf("Line Number: %i\n", alloc->head->lineNumber);
  printf("Length of Space: %i\n", alloc->head->lengthOfSpace);
  printf("File name: %s\n", alloc->head->fileNameMemory);
  printf("Memory: %p\n", alloc->head->memoryAddress);
  printf("Total number of linked file(s): %d\n\n", alloc->noOfLinkedDesc);
} */

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
/* void test_linkedList_given_two_memory_description_should_return_two_memory_description(){
  alloc = createAllocationPool();

  listAdd(alloc, createMemoryDescription(__LINE__, 400, __FILE__));
  listAdd(alloc, createMemoryDescription(__LINE__, 500, __FILE__));

  TEST_ASSERT_EQUAL(400, alloc->head->lengthOfSpace);
  TEST_ASSERT_EQUAL(500, alloc->head->next->lengthOfSpace);
  TEST_ASSERT_EQUAL(2, alloc->noOfLinkedDesc);
  TEST_ASSERT_NULL(alloc->tail->next);
  printf("--MemoryDescription[1]--\n");
  printf("Next[1]: %p\n", alloc->head->next);
  printf("Line Number[1]: %i\n", alloc->head->lineNumber);
  printf("Length of Space[1]: %i\n", alloc->head->lengthOfSpace);
  printf("File name[1]: %s\n", alloc->head->fileNameMemory);
  printf("Memory[1]: %p\n\n", alloc->head->memoryAddress);

  printf("--MemoryDescription[2]--\n");
  printf("Next[2]: %p\n", alloc->tail->next);
  printf("Line Number[2]: %i\n", alloc->tail->lineNumber);
  printf("Length of Space[2]: %i\n", alloc->tail->lengthOfSpace);
  printf("File name[2]: %s\n", alloc->tail->fileNameMemory);
  printf("memory[2]: %p\n\n", alloc->tail->memoryAddress);

  printf("Total number of linked file(s): %d\n\n", alloc->noOfLinkedDesc);
} */


// void test_the_function_of_allocateAddress(){
  // MemoryDescription *address = allocateAddress(10);
  // TEST_ASSERT_NOT_NULL(address);
  // TEST_ASSERT_EQUAL_PTR(headerPtr, address->headerAddress);
  // TEST_ASSERT_EQUAL_PTR(dataPtr, address->memoryAddress);
  // TEST_ASSERT_EQUAL_PTR(footerPtr, address->footerAddress);
// }

void test_allocateAddress_pattern_(){//test padding functionality
  MemoryDescription *address2 = allocateAddress(15);
  char *memory=address2->headerAddress;
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
  TEST_ASSERT_EQUAL_HEX(NULL, *(memory+20));
  
  char *memory1=address2->footerAddress;
  TEST_ASSERT_EQUAL_HEX('x', *memory1);
  TEST_ASSERT_EQUAL_HEX('y', *(memory1+1));
  TEST_ASSERT_EQUAL_HEX('Z', *(memory1+2));
  TEST_ASSERT_EQUAL_HEX('a', *(memory1+3));
  TEST_ASSERT_EQUAL_HEX('x', *(memory1+4));
  TEST_ASSERT_EQUAL_HEX('y', *(memory1+5));
  TEST_ASSERT_EQUAL_HEX('Z', *(memory1+6));
  TEST_ASSERT_EQUAL_HEX('a', *(memory1+7));
  TEST_ASSERT_EQUAL_HEX('x', *(memory1+8));
  TEST_ASSERT_EQUAL_HEX('y', *(memory1+9));
  TEST_ASSERT_EQUAL_HEX('Z', *(memory1+10));
  TEST_ASSERT_EQUAL_HEX('a', *(memory1+11));
  TEST_ASSERT_EQUAL_HEX('x', *(memory1+12));
  TEST_ASSERT_EQUAL_HEX('y', *(memory1+13));
  TEST_ASSERT_EQUAL_HEX('Z', *(memory1+14));
  TEST_ASSERT_EQUAL_HEX('a', *(memory1+15));
  TEST_ASSERT_EQUAL_HEX('x', *(memory1+16));
  TEST_ASSERT_EQUAL_HEX('y', *(memory1+17));
  TEST_ASSERT_EQUAL_HEX('Z', *(memory1+18));
  TEST_ASSERT_EQUAL_HEX('a', *(memory1+19));
  TEST_ASSERT_EQUAL_HEX(NULL, *(memory1+20));
  free(address2);
}

void test_safeMalloc(){
  safeMalloc(10);
}

void test_5th_char_not_same_should_return_5(){
  
  char pointer[21]="xyZa5yZaxyZaxyZaxyZa";
  char i=-2;
  i=patternCheck(pointer, 21, CODE_PATTERN);
  
  TEST_ASSERT_EQUAL(5, i);
  }

void test_patterncheck_no_problem_return_neg20(){
  
  char pointer[21]="xyZaxyZaxyZaxyZaxyZa";
  char i=-2;
  i=patternCheck(pointer, 21, CODE_PATTERN);
  
  TEST_ASSERT_EQUAL(-20, i);
  }

void test_patterncheck_20xA_no_problem_return_neg20(){
  
  char pointer[21]="AAAAAAAAAAAAAAAAAAAA";
  char i=-2;
  i=patternCheck(pointer, 21, "A");
  
  TEST_ASSERT_EQUAL(-20, i);
  }

void test_patterncheck_20xA_5th_not_same_return_5(){
  
  char pointer[21]="AAAA5AAAAAAAAAAAAAAA";
  char i=-2;
  i=patternCheck(pointer, 21, "A");
  
  TEST_ASSERT_EQUAL(5, i);
  }