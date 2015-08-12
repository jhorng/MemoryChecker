#include "unity.h"
#include "safeSummary.h"

#include "MemoryDescription.h"
#include "ErrorObject.h"
#include "LinkedList.h"
#include "Smalloc.h"
#include "Sfree.h"
void setUp(void){}

void tearDown(void){}

void test_module_generator_needs_to_be_implemented(void){
	TEST_IGNORE_MESSAGE("Implement me!");
}


void test_safeSummary(){
  
  char *fa;
  //fa=safeMalloc(20);
  safeFree(fa);
  safeSummary();
}