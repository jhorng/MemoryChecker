#include <stdio.h>
#include <stdlib.h>
#include "Padding.h"

padSpace *createPadding(){
  int i;
  char check = 'a';
  
  padSpace *space;
  space -> paddingSize = 100;
  padSpace *padding = malloc(sizeof(space));
  
  for (i=0; i<space -> paddingSize; i++){
    check;
    if (check == 0){
      i--;
    }
    printf("%c", check);
  }
}