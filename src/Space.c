#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Space.h"

Space *createUserDefinedSpace(int mallocSize){
  int sizeOfSpace;
  Space *size;
  scanf("%d", &sizeOfSpace);
  size -> mallocSize = sizeOfSpace;
  Space *userDefined = malloc(sizeof(size)); 
}