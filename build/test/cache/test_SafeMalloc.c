#include "AllocationPool.h"
#include "Smalloc.h"
#include "unity.h"


void setUp(void) {}



void tearDown(void) {}





Allocation *alloc = ((void *)0);



void test_repeatPattern_given_x_pattern_with_1_times_should_have_x_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(1,"x",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_HEX32);

}



void test_repeatPattern_given_x_pattern_with_2_times_should_have_xx_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(2,"xx",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_HEX32);

}



void test_repeatPattern_given_xy_pattern_with_2_times_should_have_xyxy_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(2,"xy",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_HEX32);

}



void test_repeatPattern_given_xyZa_1_time_should_have_xyZa_1time_only_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(1,"xyZa",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_HEX32);

}



void test_repeatPattern_given_xyZa_6_times_should_have_xyZa_5times_only_in_the_memory(){

  char *memory = malloc(22);

  patternRepeat(6,"xyZa",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+4))), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+5))), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+6))), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+7))), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+8))), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+9))), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+10))), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+11))), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+12))), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+13))), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+14))), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+15))), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+16))), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+17))), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+18))), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+19))), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_HEX32);

}















void test_createAllocationPool_given_head_and_tail_both_return_NULL(){

  Allocation *newAlloc = createAllocationPool();

  if ((((newAlloc->head)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)81);;};

  if ((((newAlloc->tail)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)82);;};

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newAlloc->noOfLinkedDesc)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

  printf("--Allocation--\nHead: %i\nTail: %i\n", newAlloc->head, newAlloc->tail);

  printf("Number of linked memoryStor description: %d\n\n", newAlloc->noOfLinkedDesc);

}









void test_createMemoryDescription_given_next_and_memory_both_return_NULL(){

  memoryDescription *newMemDesc = createMemoryDescription(92, 500, "test/test_SafeMalloc.c");

  UnityAssertEqualNumber((_U_SINT)((500)), (_U_SINT)((newMemDesc->lengthOfSpace)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

  if ((((newMemDesc->memoryStor)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)94);;};

  if ((((newMemDesc->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)95);;};

  printf("--MemoryDescription--\nMemory: %i\n", newMemDesc->memoryStor);

  printf("Next: %i\n", newMemDesc->next);

  printf("Line Number: %i\n", newMemDesc->lineNo);

  printf("Length of Space: %i\n", newMemDesc->lengthOfSpace);

  printf("File name: %s\n\n", newMemDesc->fileNameMemory);

}

void test_linkedList_given_one_memory_description_should_return_one_memory_description(){

  alloc = createAllocationPool();



  listAdd(alloc, createMemoryDescription(115, 400, "test/test_SafeMalloc.c"));



  UnityAssertEqualNumber((_U_SINT)((400)), (_U_SINT)((alloc->head->lengthOfSpace)), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

  if ((((alloc->tail->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)118);;};

  printf("--Linked list--\n");

  printf("Next: %p\n", alloc->head->next);

  printf("Line Number: %i\n", alloc->head->lineNo);

  printf("Length of Space: %i\n", alloc->head->lengthOfSpace);

  printf("File name: %s\n", alloc->head->fileNameMemory);

  printf("Memory: %p\n", alloc->head->memoryStor);

  printf("Total number of linked file(s): %d\n\n", alloc->noOfLinkedDesc);

}

void test_linkedList_given_two_memory_description_should_return_two_memory_description(){

  alloc = createAllocationPool();



  listAdd(alloc, createMemoryDescription(141, 400, "test/test_SafeMalloc.c"));

  listAdd(alloc, createMemoryDescription(142, 500, "test/test_SafeMalloc.c"));



  UnityAssertEqualNumber((_U_SINT)((400)), (_U_SINT)((alloc->head->lengthOfSpace)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((500)), (_U_SINT)((alloc->head->next->lengthOfSpace)), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((alloc->noOfLinkedDesc)), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_INT);

  if ((((alloc->tail->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)147);;};

  printf("--MemoryDescription[1]--\n");

  printf("Next[1]: %p\n", alloc->head->next);

  printf("Line Number[1]: %i\n", alloc->head->lineNo);

  printf("Length of Space[1]: %i\n", alloc->head->lengthOfSpace);

  printf("File name[1]: %s\n", alloc->head->fileNameMemory);

  printf("Memory[1]: %p\n\n", alloc->head->memoryStor);



  printf("--MemoryDescription[2]--\n");

  printf("Next[2]: %p\n", alloc->tail->next);

  printf("Line Number[2]: %i\n", alloc->tail->lineNo);

  printf("Length of Space[2]: %i\n", alloc->tail->lengthOfSpace);

  printf("File name[2]: %s\n", alloc->tail->fileNameMemory);

  printf("memory[2]: %p\n\n", alloc->tail->memoryStor);



  printf("Total number of linked file(s): %d\n\n", alloc->noOfLinkedDesc);

}
