#include <stdio.h>
#include <stdlib.h>
#include "SafeMalloc.h"

padSpace *createPadding(){
  padSpace *space;
  space -> paddingSize = 50;
  padSpace *padding = malloc(sizeof(space));
}

