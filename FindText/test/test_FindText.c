#include "unity.h"
#include "FindText.h"

void setUp(){}

void tearDown(){}

void test_findText_Given_A_find_A_shouldReturn_0(){
	TEST_ASSERT_EQUAL(0,findText("A","A"));
}

void test_findText_Given_AB_find_B_shouldReturn_1(){
	TEST_ASSERT_EQUAL(1,findText("AB","B"));
}

void test_findText_Given_A_find_B_shouldReturn_minus1(){
	TEST_ASSERT_EQUAL(-1,findText("A","P"));
}

void test_findText_Given_ALL_find_L_shouldReturn_2(){
	TEST_ASSERT_EQUAL(2,findText("ALL","L"));
}

void test_findText_Given_WORLD_find_RL_shouldReturn_2(){
	TEST_ASSERT_EQUAL(2,findText("WORLD","RL"));
}

void test_findText_Given_WORLDRX_find_RX_shouldReturn_2(){
	TEST_ASSERT_EQUAL(2,findText("WORXLDRL","RX"));
}

void test_findText_given_DRPOH_TV_find_POH_TV_should_return_2(){ //spacing testing
    TEST_ASSERT_EQUAL(2, findText("DRPOH TV", "POH TV"));
}

void test_findText_find_ED_in_ABCD_should_return_minus1(){ //multi char error test with 1st char pass
	TEST_ASSERT_EQUAL(-1, findText("ABCD", "ED")) ;
}

void test_findText_find_DE_in_ABCD_should_return_minus1(){ //multi char error test 
	TEST_ASSERT_EQUAL(-1, findText("ABCD", "DE")) ;
}

void test_findText_find_ABC_in_ABCD_should_return_0(){ //appoach starting of string multi char test
	TEST_ASSERT_EQUAL(0, findText("ABCD", "ABC")) ;
}

void test_findText_find_GB_in_ABCDEFGBCHI_should_return_6(){ //long string with short substring test
	TEST_ASSERT_EQUAL(6, findText("ABCDEFGBCHI", "GB")) ;
}

void test_findText_find_lad_in_Hello_my_name_is_Alladin_should_return_20(){
	TEST_ASSERT_EQUAL(20, findText("Hello, my name is Alladin", "lad")) ;
}

void test_findText_find_coma_and_space_in_Hello_my_name_is_Alladin_should_return_5(){
	TEST_ASSERT_EQUAL(5, findText("Hello, my name is Alladin", ", ")) ;
}

void test_findText_given_RRARARATA_find_RRARA_should_return_0(){
    TEST_ASSERT_EQUAL(0, findText("RRARARATA", "RRARA"));
} 