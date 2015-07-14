#include "AllocationPool.h"
#include "Smalloc.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}















void test_createAllocationPool_given_head_and_tail_both_return_NULL(){

  Allocation *newAlloc = createAllocationPool();

  if ((((newAlloc->head)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)18);;};

  if ((((newAlloc->tail)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)19);;};

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newAlloc->noOfLinkedDesc)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

  printf("--Allocation--\nHead: %i\nTail: %i\n", newAlloc->head, newAlloc->tail);

  printf("Number of linked memory description: %d\n\n", newAlloc->noOfLinkedDesc);

}









void test_createMemoryDesciption_given_next_and_memory_both_return_NULL(){

  memoryDesciption *newMemDesc = createMemoryDesciption(29, 500, "test/test_SafeMalloc.c");

  UnityAssertEqualNumber((_U_SINT)((500)), (_U_SINT)((newMemDesc->lengthOfSpace)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

  if ((((newMemDesc->memory)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)31);;};

  if ((((newMemDesc->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)32);;};

  printf("--MemoryDescription--\nMemory: %i\n", newMemDesc->memory);

  printf("Next: %i\n", newMemDesc->next);

  printf("Line Number: %i\n", newMemDesc->lineNo);

  printf("Length of Space: %i\n", newMemDesc->lengthOfSpace);

  printf("File name: %s\n\n", newMemDesc->fileNameMemory);

}

void test_linkedList_given_one_memory_description_should_return_one_memory_description(){

  Allocation *alloc = createAllocationPool();



  linkedList(alloc, createMemoryDesciption(52, 400, "test/test_SafeMalloc.c"));



  UnityAssertEqualNumber((_U_SINT)((400)), (_U_SINT)((alloc->head->lengthOfSpace)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

  if ((((alloc->head->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)55);;};

  if ((((alloc->head->memory)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)56);;};

  printf("--MemoryDescription--\nMemory: %i\n", alloc->head->memory);

  printf("Next: %i\n", alloc->head->next);

  printf("Line Number: %i\n", alloc->head->lineNo);

  printf("Length of Space: %i\n", alloc->head->lengthOfSpace);

  printf("File name: %s\n\n", alloc->head->fileNameMemory);

}



void test_linkedList_given_two_memory_description_should_return_two_memory_description(){

  Allocation *alloc = createAllocationPool();



  linkedList(alloc, createMemoryDesciption(67, 400, "test/test_SafeMalloc.c"));

  linkedList(alloc, createMemoryDesciption(68, 500, "test/test_SafeMalloc.c"));



  UnityAssertEqualNumber((_U_SINT)((400)), (_U_SINT)((alloc->head->lengthOfSpace)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((500)), (_U_SINT)((alloc->head->next->lengthOfSpace)), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT);

  if ((((alloc->tail->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)72);;};

  printf("--MemoryDescription[1]--\n");

  printf("Memory[1]: %i\n", alloc->head->memory);

  printf("Next[1]: %i\n", alloc->head->memory);

  printf("Line Number[1]: %i\n", alloc->head->lineNo);

  printf("Length of Space[1]: %i\n", alloc->head->lengthOfSpace);

  printf("File name[1]: %s\n\n", alloc->head->fileNameMemory);



  printf("--MemoryDescription[2]--\n");

  printf("Memory[2]: %i\n", alloc->head->next->memory);

  printf("Next[2]: %i\n", alloc->head->next->next);

  printf("Line Number[2]: %i\n", alloc->head->next->lineNo);

  printf("Length of Space[2]: %i\n", alloc->head->next->lengthOfSpace);

  printf("File name[2]: %s\n\n", alloc->head->next->fileNameMemory);

}
