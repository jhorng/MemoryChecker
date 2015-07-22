#include "linklist.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_module_generator_needs_to_be_implemented(void){

 UnityIgnore( ("Implement me!"), (_U_UINT)9);;

}



void test_beta(){



 linklist(100);

 linklist(101);

 linklist(102);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((linklist(3))), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

}
