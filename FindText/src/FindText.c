#include "FindText.h"
#include "string.h"
#include <stdio.h>
//#include <malloc.h>


/**
 *find substring in string and return the location of
 *the first letter [in reverse]
 *ie.  text = Hello, my name is Alladin
 *wordToFind = lad
 *return value =20
 *
 *Input:
 * text   contains a bunch of words
 * wordToFind   is the (partial) word to find in the text
 *Return:
 *  the position of the first letter found in text.
 *  if word cannot be found in the text, -1 is returned.
 */

 
 
int findText(char *text, char *subtext){
	int length1,length2, pass=0,i=0,j;
	
	length1 = strlen(text)-1;
	length2 = strlen(subtext)-1;
	
	
	i=length1; 
	j=length2;
	
	
	while(pass == 0){
		if(text[i] == subtext[j]){
			i--; j--; pass=1;
		}
		else{
			i--; 
		}
		
		if(pass==0 && j!=length2){  //for recurring string
			i = i+(length2-j);
			j = length2;
		}
		
		if(i==-1 || j ==-1) {       //return the character
			if(pass==1) return ++i;
		}
		if(j==-1 && i >=0) break;   //any un
	    if(i== -1 || j ==-1) return i;
		pass =0;
	}
	

  return -2;
}




