
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
  int numberOfAlloc=0, numberOfFree=0;
  
  //nomadPtr4Alloc = passAllocPointer();
  //nomadPtr4Free  = passFreePointer();
  
  printf("========================\n");
  printf("Checking Allocation Pool\n");
  printf("========================\n");
  //numberOfAlloc = roamingChecker(nomadPtr4Alloc);
  
  printf("==================\n");
  printf("Checking Free Pool\n");
  printf("==================\n");
  //numberOfFree  = roamingChecker(nomadPtr4Free);
  
  
  printf("======SUMMARY======\n");
  printf("Number of Malloc Action : %d \n",numberOfAlloc);
  printf("Number of Free   Action : %d \n",numberOfFree);
  printf("===================\n");
  
  
  

}

int roamingChecker(MemoryDescription *nomadPtr){
  int resultOfHeader,resultOfSpace,resultOfFooter;
  int counter=0;
  
  printf("==========START OF LIST===========\n");
  
  while(nomadPtr->next != NULL){
    resultOfHeader = patternCheck( nomadPtr->headerAddress, HEADER_SIZE, CODE_PATTERN);
    resultOfFooter = patternCheck( nomadPtr->footerAddress, FOOTER_SIZE, CODE_PATTERN);
    
    if(nomadPtr->freeLine == 0){
      printf("File:%p:%d: note: Memory malloc-ed pending to be free.\n",nomadPtr->mallocFile,nomadPtr->mallocLine);   
    }
    else{
      resultOfSpace  = patternCheck( nomadPtr->memoryAddress, nomadPtr->dataSize, "#");
      if(resultOfSpace != PASS_TICKET){
        printf("File:%p:%d: note: Memory's datapad integrity violated @column:%d\n",nomadPtr->mallocFile,nomadPtr->mallocLine,resultOfSpace); 
      }
    }
    
    if(resultOfHeader != PASS_TICKET){
     printf("File:%p:%d: note: Memory's header integrity violated @column:%d\n",nomadPtr->mallocFile,nomadPtr->mallocLine,resultOfHeader);   
    }
    if(resultOfFooter != PASS_TICKET){
     printf("File:%p:%d: note: Memory's footer integrity violated @column:%d\n",nomadPtr->mallocFile,nomadPtr->mallocLine,resultOfFooter);   
    }
      
  counter++;
  nomadPtr=nomadPtr->next;
 
  }
  
  printf("==========END OF REPORT==========\n\n");
  return counter;
  
  
  
}