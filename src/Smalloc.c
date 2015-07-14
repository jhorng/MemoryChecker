#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Smalloc.h"

void _safeMalloc(int lineNumber, char *fileName){
  
  void *headerPtr, *dataPtr, *footerPtr;       
       
  void *space = malloc(sizeof(HEADER_SIZE+DATA_SIZE+FOOTER_SIZE));
  
  headerPtr   = space;
  dataPtr     = space+HEADER_SIZE;
  footerPtr   = dataPtr +DATA_SIZE;
  
  return;
}