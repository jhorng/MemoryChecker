#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Smalloc.h"

Space *memorySpace(){
  Space *paddingPtr1, *paddingPtr2, spacePtr;
  Space *space = malloc(sizeof(Space));
  space->headerSize = space->footerSize = 3;
  space->size = 9;
  
  paddingPtr1 = space->headerSize;
  // spacePtr = space->size;
  // paddingPtr2 = space->footerSize;
  
  // strcpy(space->headerSize, "52U");
  // strcpy(space->footerSize, "52U");
  // strcmp(space->headerSize, "52U");
  // strcmp(space->footerSize, "52U");
  
}