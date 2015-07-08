#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "SafeMalloc.h"
#include "AllocationPool.h"
#include "Smalloc.h"

/* 
void SafeMalloc(Allocation *newAlloc){
  if (newAlloc->next==NULL){
    return printf("The allocation pool is empty!");
  }
  else{
    newAlloc->next = newAlloc;
  }
}
 */