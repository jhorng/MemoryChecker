#include "unity.h"
#include "safeSummary.h"

#include "MemoryDescription.h"
#include "ErrorObject.h"
#include "LinkedList.h"
#include "Smalloc.h"
#include "Sfree.h"
void setUp(void){}

void tearDown(void){}

void xtest_safeSummary(){
  
  char *fa;
  //fa=safeMalloc(20);
  safeFree(fa);
  safeSummary();
}