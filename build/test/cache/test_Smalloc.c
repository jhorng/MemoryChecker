#include "ErrorObject.h"
#include "AllocationPool.h"
#include "CException.h"
#include "Smalloc.h"
#include "unity.h"




void setUp(void){}



void tearDown(void){}



void test_repeatPattern_given_x_pattern_with_1_times_should_have_x_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(1,"x",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_HEX32);



  UnityAssertEqualNumber((_U_SINT)(_US32)((((void *)0))), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_HEX32);

}



void test_repeatPattern_given_x_pattern_with_2_times_should_have_xx_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(2,"xx",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)((((void *)0))), (_U_SINT)(_US32)((*(memory+4))), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_HEX32);



}



void test_repeatPattern_given_xy_pattern_with_2_times_should_have_xyxy_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(2,"xy",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)((((void *)0))), (_U_SINT)(_US32)((*(memory+4))), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_HEX32);

}



void test_repeatPattern_given_xyZa_1_time_should_have_xyZa_1time_only_in_the_memory(){

  char *memory = malloc(20);

  patternRepeat(1,"xyZa",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)((((void *)0))), (_U_SINT)(_US32)((*(memory+4))), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_HEX32);

}



void test_repeatPattern_given_xyZa_6_times_should_have_xyZa_5times_only_in_the_memory(){

  char *memory = malloc(22);

  patternRepeat(6,"xyZa",memory);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+4))), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+5))), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+6))), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+7))), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+8))), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+9))), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+10))), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+11))), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+12))), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+13))), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+14))), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+15))), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+16))), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+17))), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+18))), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+19))), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)((((void *)0))), (_U_SINT)(_US32)((*(memory+20))), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_HEX32);

}



 void test_safeMalloc_if_NULL_return_NULL(){

  char *memory = (char *) _safeMalloc(0,80,"test/test_Smalloc.c");

  if ((((memory)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)81);;};

}





void test_safeMalloc_should_throw_err__size_exceed_the_DATA_SIZE(){

    ErrorObject *err;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (1){

    _safeMalloc(2000,88,"test/test_Smalloc.c");

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EXCEED_DATA_SIZE)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

 }

}



void xtest_safeMalloc_check_header_footer_pattern(){

  char *memory = (char *) _safeMalloc(20,95,"test/test_Smalloc.c");

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*memory)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+1))), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+2))), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+3))), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+4))), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+5))), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+6))), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+7))), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+8))), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+9))), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+10))), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+11))), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+12))), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+13))), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+14))), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+15))), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('x')), (_U_SINT)(_US32)((*(memory+16))), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('y')), (_U_SINT)(_US32)((*(memory+17))), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('Z')), (_U_SINT)(_US32)((*(memory+18))), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_US32)(('a')), (_U_SINT)(_US32)((*(memory+19))), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_HEX32);





}
