#include "unity.h"
#include "Sfree.h"
#include "LinkedList.h"
#include "Smalloc.h"
#include "MemoryDescription.h"
#include "ErrorObject.h"
<<<<<<< HEAD
#include "CException.h"
=======
>>>>>>> 4abb9c83d10efeff51e18ec9ae9ffe3f799009a3

void setUp(void){}

void tearDown(void){}

void test_safeFree_NULL(){
  
  
  int*memory001;
  memory001=NULL;
 
  safeFree(memory001);
}
