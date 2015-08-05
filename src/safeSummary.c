
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "safeSummary.h"
#include "Sfree.h"
#include "ErrorObject.h"
#include "MemoryDescription.h"


void safeSummary(){
  MemoryDescription *nomadPtr4Alloc, *nomadPtr4Free;
  
  AllocPtr = passAllocPointer();
  FreePtr  = passFreePointer();
  
  
  roamingChecker(AllocPtr);
  roamingChecker(FreePtr);

  //if(allocationHead==NULL &&allocationTail==NULL){
    
 // }
  
}

void roamingChecker(MemoryDescription *nomadPtr){
  int resultOfHeader,resultOfSpace,resultOfFooter ;
  
  while(nomadPtr->next != NULL){
    resultOfHeader = patternCheck( nomadPtr->headerAddress, HEADER_SIZE, CODE_PATTERN);
    resultOfFooter = patternCheck( nomadPtr->footerAddress, FOOTER_SIZE, CODE_PATTERN);
    
    
    if(nomadPtr->freeLine == 0){
      printf("File:%p:%d: note: Memory malloc-ed pending to be free.\n",fileName,lineNumber);   
    }
    else{
      resultOfSpace  = patternCheck( nomadPtr->memoryAddress, nomadPtr->dataSize, "#");
      if(resultOfSpace != PASS_TICKET){
        printf("File:%p:%d: note: Memory's datapad integrity violated @column:%d",nomadPtr->fileName,nomadPtr->lineNumber,resultOfSpace); 
      }
    }
    
  if(resultOfHeader != PASS_TICKET){
     printf("File:%p:%d: note: Memory's header integrity violated @column:%d",nomadPtr->fileName,nomadPtr->lineNumber,resultOfHeader);   
    }
  if(resultOfFooter != PASS_TICKET){
     printf("File:%p:%d: note: Memory's footer integrity violated @column:%d",nomadPtr->fileName,nomadPtr->lineNumber,resultOfFooter);   
    }
      
  
  nomadPtr=nomadPtr->next;
  
    
  }
  
  
  
  
  
}