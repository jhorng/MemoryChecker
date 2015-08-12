
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "safeSummary.h"
#include "Sfree.h"
#include "ErrorObject.h"
#include "MemoryDescription.h"
#include "Smalloc.h"


void safeSummary(){
  
/*   
MemoryDescription *allocationHead = NULL;
MemoryDescription *allocationTail = NULL;

MemoryDescription *freeHead = NULL;
MemoryDescription *freeTail = NULL; */

  MemoryDescription *nomadPtr4Alloc, *nomadPtr4Free;
  
  nomadPtr4Alloc = passAllocPointer();
  nomadPtr4Free  = passFreePointer();
  
  
  roamingChecker(nomadPtr4Alloc);
  roamingChecker(nomadPtr4Free);

}

void roamingChecker(MemoryDescription *nomadPtr){
  int resultOfHeader,resultOfSpace,resultOfFooter ;
  
  while(nomadPtr->next != NULL){
    resultOfHeader = patternCheck( nomadPtr->headerAddress, HEADER_SIZE, CODE_PATTERN);
    resultOfFooter = patternCheck( nomadPtr->footerAddress, FOOTER_SIZE, CODE_PATTERN);
    
    
    if(nomadPtr->freeLine == 0){
      printf("File:%p:%d: note: Memory malloc-ed pending to be free.\n",nomadPtr->mallocFile,nomadPtr->mallocLine);   
    }
    else{
      resultOfSpace  = patternCheck( nomadPtr->memoryAddress, nomadPtr->dataSize, "#");
      if(resultOfSpace != PASS_TICKET){
        printf("File:%p:%d: note: Memory's datapad integrity violated @column:%d",nomadPtr->mallocFile,nomadPtr->mallocLine,resultOfSpace); 
      }
    }
    
  if(resultOfHeader != PASS_TICKET){
     printf("File:%p:%d: note: Memory's header integrity violated @column:%d",nomadPtr->mallocFile,nomadPtr->mallocLine,resultOfHeader);   
    }
  if(resultOfFooter != PASS_TICKET){
     printf("File:%p:%d: note: Memory's footer integrity violated @column:%d",nomadPtr->mallocFile,nomadPtr->mallocLine,resultOfFooter);   
    }
      
  
  nomadPtr=nomadPtr->next;
  
    
  }
  
  
  
  
  
}