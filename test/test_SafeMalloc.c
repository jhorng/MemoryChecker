#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "unity.h"
#include "Smalloc.h"
#include "MemoryDescription.h"
#include "ErrorObject.h"
#include "LinkedList.h"
#include "ErrorObject.h"


extern char *headerPtr, *dataPtr, *footerPtr;

void setUp(void) {}

void tearDown(void) {}

void test_repeatPattern_given_x_pattern_with_1_times_should_have_x_in_the_memory(){
  char *memory = malloc(20);
  patternRepeat(1,"x",memory);
  TEST_ASSERT_EQUAL_HEX('x', *memory);
  TEST_ASSERT_EQUAL_HEX(NULL, *(memory+1));
  free(memory);
}

void test_repeatPattern_given_x_pattern_with_2_times_should_have_xx_in_the_memory(){
  char *memory = malloc(20);
  patternRepeat(2,CODE_PATTERN,memory);
  TEST_ASSERT_EQUAL_HEX('#', *memory);
  TEST_ASSERT_EQUAL_HEX('#', *(memory+1));
  TEST_ASSERT_EQUAL_HEX(NULL, *(memory+2));
    free(memory);
}

void test_repeatPattern_given_X_HEADER_SIZE_should_have_21_5times_only_in_the_memory(){
  char *memory = malloc(21); // This is essential for testing overflow
  int i=0;
  patternRepeat(HEADER_SIZE,CODE_PATTERN,memory);
  for(i=0;i<21;i++){
  TEST_ASSERT_EQUAL_HEX('#', *(memory+i));
}
  TEST_ASSERT_EQUAL_HEX(NULL, *(memory+21));
  free(memory);
  
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

void test_safeMalloc_returned_address_has_padding(){
  char *memory002=safeMalloc(10);
  char *memory=memory002-HEADER_SIZE,
       *memory1=memory002+10;
  int i=0;
   for(i=0;i<21;i++){
  TEST_ASSERT_EQUAL_HEX('#', *(memory+i));
}
  TEST_ASSERT_EQUAL_HEX(NULL, *(memory+21));
  for(i=0;i<21;i++){
  TEST_ASSERT_EQUAL_HEX('#', *(memory1+i));
}
  TEST_ASSERT_EQUAL_HEX(NULL, *(memory1+21)); 
  free(memory002);
}

void test_allocateAddress_pattern_(){//test padding functionality
  MemoryDescription *address2 = allocateAddress(15);
  char *memory=address2->headerAddress;
  int i=0;
  for(i=0;i<21;i++){
  TEST_ASSERT_EQUAL_HEX('#', *(memory+i));
}
  TEST_ASSERT_EQUAL_HEX(NULL, *(memory+21));
  printf("%s",address2->memoryAddress);
  char *memory1=address2->footerAddress;
  for(i=0;i<21;i++){
  TEST_ASSERT_EQUAL_HEX('#', *(memory1+i));
}
  TEST_ASSERT_EQUAL_HEX(NULL, *(memory1+21));
  free(address2);
} 





void test_5th_char_not_same_should_return_5(){
  
  char pointer[21]="####5###############";
  char i=-2;
  i=patternCheck(pointer, 21, CODE_PATTERN);
  
  TEST_ASSERT_EQUAL(5, i);
  }

void test_patterncheck_no_problem_return_neg20(){
  
  char pointer[21]="####################";
  char i=-2;
  i=patternCheck(pointer, 21, CODE_PATTERN);
  
  TEST_ASSERT_EQUAL(-20, i);
  }


