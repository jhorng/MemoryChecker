#include "unity.h"
#include "Sfree.h"
#include "LinkedList.h"
#include "Smalloc.h"
#include "MemoryDescription.h"
#include "ErrorObject.h"
#include "CException.h"

void setUp(void){}

void tearDown(void){}

void test_safeFree_NULL(){
  
  
  int*memory001;
  memory001=NULL;
 
  safeFree(memory001);
}
