#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Smalloc.h"

Space *createMemorySpace(){
  int i, length;
  char insertion[4];
  void *headerPtr, *footerPtr, *spacePtr;
  Space *space = malloc(sizeof(Space));
  space->headerSize = space->footerSize = 100;
  space->size = 500;
  
  headerPtr = space;
  spacePtr = space + space->headerSize;
  footerPtr = spacePtr + space->size;
  
  strcpy(insertion, "0x54");
  length = strlen(insertion);
  for (i=0; i<(space->headerSize/length); i++){
    headerPtr = footerPtr = insertion;
  }
}

