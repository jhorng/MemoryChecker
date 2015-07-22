#include "linklist.h"
#include <malloc.h>
#include <stdio.h>
#include "string.h"



struct testStruct *head = NULL;
struct testStruct *curr = NULL;



struct testStruct* add_to_list(int value){
	
	struct testStruct *ptr = (struct testStruct*)malloc(sizeof(struct testStruct));
	
    if( head== NULL){
        if(ptr == NULL){
			printf("!!! fail to create node !!!");
			return NULL;
		}
		
		printf("\n creating list with <%d>",value);
		ptr->value = value;
		ptr->next = NULL;

		head = curr = ptr;
		return ptr;
    }
    printf("\n Adding node with value <%d>",value);
	
    ptr->value = value;
    ptr->next = NULL;
   
    curr->next = ptr;
    curr = ptr;
    
    return ptr;
}


int print_list(){
    struct testStruct *ptr = head;
	int nodecounter=0;

    printf("\n -------list Start------- \n");
    while(ptr != NULL){
        printf(" [%d] ",ptr->value);
        ptr = ptr->next;
		nodecounter++;
    }
	printf("\n");

    return nodecounter;
}

int linklist(int i){
	
	
	int nodecounter=-2;
    struct testStruct *ptr = NULL;

    nodecounter=print_list();

    add_to_list(i);

    nodecounter=print_list();

    return nodecounter;
}