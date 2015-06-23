#include <stdio.h>
#include <stdlib.h>
#include "Padding.h"
#include "CException.h"
#include "ErrorCode.h"

void printPaddingError(int errorCode){
    switch(errorCode){
      case ERR_SPACE_USED_EXTRA:
        printf("You have used more than enough!");
        break;
      default:
      printf("Error caught! Error code is: %d\n", errorCode);
      break;
    }
}    

padSpace *createPadding(char check){
  int i;
  CEXCEPTION_T error;
  
  padSpace *padding = malloc(sizeof(padSpace));
  padding -> paddingSize = 100;
  
  for (i=0; i<padding -> paddingSize; i++){
    if (check == 0 && check == check){
      i--;
    }
  }
  
}

/* void tryCatch(){
  char check;
  CEXCEPTION_T error;
  
  Try{
    createPadding('a');
  } Catch(error){
    printPaddingError(error);
  }
}
 */