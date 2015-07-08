#include "AllocationPool.h"
#include "Smalloc.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test1(){

  _safeMalloc(11,"test/test_SafeMalloc.c");

}















void test_createAllocationPool_given_head_and_tail_both_return_NULL(){

  Allocation *newAlloc = createAllocationPool();

  if ((((newAlloc->head)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)22);;};

  if ((((newAlloc->tail)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)23);;};

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newAlloc->noOfLinkedDesc)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

  printf("--Allocation--\nHead: %i\nTail: %i\n", newAlloc->head, newAlloc->tail);

  printf("Number of linked memory description: %d\n\n", newAlloc->noOfLinkedDesc);

}









void test_createMemoryDesciption_given_next_and_memory_both_return_NULL(){

  memoryDesciption *newMemDesc = createMemoryDesciption(33, 500, "test/test_SafeMalloc.c");

  UnityAssertEqualNumber((_U_SINT)((500)), (_U_SINT)((newMemDesc->lengthOfSpace)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

  if ((((newMemDesc->memory)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)35);;};

  if ((((newMemDesc->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)36);;};

  printf("--MemoryDescription--\nMemory: %i\n", newMemDesc->memory);

  printf("Next: %i\n", newMemDesc->next);

  printf("Line Number: %i\n", newMemDesc->lineNo);

  printf("Length of Space: %i\n", newMemDesc->lengthOfSpace);

  printf("File name: %s\n", newMemDesc->fileName);

}



void test_linkedList_given_two_memory_description_should_return_two_memory_description(){

  Allocation *newAlloc = createAllocationPool();

  linkedList(newAlloc, createMemoryDesciption(46, 400, "test/test_SafeMalloc.c"));

  linkedList(newAlloc, createMemoryDesciption(47, 500, "test/test_SafeMalloc.c"));



}
