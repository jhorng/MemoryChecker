#include "unity.h"
#include "FindText.h"


void setUp(){}



void tearDown(){}



void test_findText_Given_A_find_A_shouldReturn_0(){

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((findText("A","A"))), (((void *)0)), (_U_UINT)9, UNITY_DISPLAY_STYLE_INT);

}



void test_findText_Given_AB_find_B_shouldReturn_1(){

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((findText("AB","B"))), (((void *)0)), (_U_UINT)13, UNITY_DISPLAY_STYLE_INT);

}



void test_findText_Given_A_find_B_shouldReturn_minus1(){

 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((findText("A","P"))), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

}



void test_findText_Given_ALL_find_L_shouldReturn_2(){

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((findText("ALL","L"))), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

}



void test_findText_Given_WORLD_find_RL_shouldReturn_2(){

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((findText("WORLD","RL"))), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);

}



void test_findText_Given_WORLDRX_find_RX_shouldReturn_5(){

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((findText("WORXLDRL","RX"))), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

}



void test_findText_given_DRPOH_TV_find_POH_TV_should_return_2(){

    UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((findText("DRPOH TV", "POH TV"))), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT);

}



void test_findText_find_ED_in_ABCD_should_return_minus1(){

 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((findText("ABCD", "ED"))), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT) ;

}



void test_findText_find_DE_in_ABCD_should_return_minus1(){

 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((findText("ABCD", "DE"))), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT) ;

}



void test_findText_find_ABC_in_ABCD_should_return_0(){

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((findText("ABCD", "ABC"))), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT) ;

}



void test_findText_find_GB_in_ABCDEFGBCHI_should_return_6(){

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((findText("ABCDEFGBCHI", "GB"))), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT) ;

}



void test_findText_find_lad_in_Hello_my_name_is_Alladin_should_return_20(){

 UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((findText("Hello, my name is Alladin", "lad"))), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT) ;

}



void test_findText_find_coma_and_space_in_Hello_my_name_is_Alladin_should_return_5(){

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((findText("Hello, my name is Alladin", ", "))), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT) ;

}



void test_findText_given_RRARARATA_find_RRARA_should_return_0(){

    UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((findText("RRARARATA", "RRARA"))), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

}
