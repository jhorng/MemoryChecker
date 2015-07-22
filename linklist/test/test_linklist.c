#include "unity.h"
#include "linklist.h"

void setUp(void){}

void tearDown(void){}

void test_module_generator_needs_to_be_implemented(void){
	TEST_IGNORE_MESSAGE("Implement me!");
}

void test_beta(){
	
	linklist(100);
	linklist(101);
	linklist(102);
	
	TEST_ASSERT_EQUAL(4,linklist(3));
}
