#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Space.h"

Space *createUserDefinedSpace(){
  int i, sizeOfSpace;
  char check = 'a';
  Space *size = malloc(sizeof(Space));
  scanf("%d", &sizeOfSpace);
  size -> mallocSize = sizeOfSpace;
  Space *userDefined = malloc(sizeof(size)); 
  
  for (i=0; i<size -> mallocSize; i++){
    check;
    if (check == 0){
      i--;
    }
  }
}
