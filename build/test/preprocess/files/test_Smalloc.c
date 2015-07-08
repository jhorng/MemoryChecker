#include "AllocationPool.h"
#include "Smalloc.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_repeatPattern_given_x_pattern_with_1_times_should_have_x_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(1,"x",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((memory)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_HEX32);

}





void test_safeMalloc(){



    _safeMalloc(20,"test/test_Smalloc.c");



}
