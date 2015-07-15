#include "AllocationPool.h"
#include "Smalloc.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_repeatPattern_given_x_pattern_with_1_times_should_have_x_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(1,"x",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_HEX32);

}



void test_repeatPattern_given_x_pattern_with_2_times_should_have_xx_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(2,"xx",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_HEX32);

}



void test_repeatPattern_given_xy_pattern_with_2_times_should_have_xyxy_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(2,"xy",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_HEX32);

}



void test_repeatPattern_given_xyZa_1_time_should_have_xyZa_1time_only_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(1,"xyZa",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_HEX32);

}



void test_repeatPattern_given_xyZa_6_times_should_have_xyZa_5times_only_in_the_memory(){

  char *memory = malloc(22);

  patternRepeat(6,"xyZa",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+4))), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+5))), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+6))), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+7))), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+8))), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+9))), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+10))), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+11))), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+12))), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+13))), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+14))), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+15))), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+16))), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+17))), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+18))), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+19))), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_HEX32);

}









void test_safeMalloc_if_NULL_return_NULL(){

    _safeMalloc(0,73,"test/test_Smalloc.c");





}
