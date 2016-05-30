/**********************************************************************
48430 Embedded C - Advanced Assignment
Name:
Student ID:
Date of submission:
A brief statement on what you could achieve (less than 50 words):


A brief statement on what you could NOT achieve (less than 50 words):


**********************************************************************/

/**********************************************************************
List of header files - you may not use any other C libraries.
List structs - you may define struct node only.
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>

/* struct node - contains
	c - a char to store an input character
	next - pointer to the next struct node or NULL (this pointer can be
	       used to construct the linked list)
Note: end of the list is indicated by a NULL pointer.
*/
struct node{
	/* TODO */
};

/**********************************************************************
Function prototypes - do NOT change the given prototypes. However you
may define your own functions if required.
**********************************************************************/
void printmenu(void);
void printlinkedlist(/* pass only ONE parameter here */);
int delhead(/* pass only ONE parameter here */);
int delvowels(/* pass only ONE parameter here */);

/**********************************************************************
Main
**********************************************************************/
/* write the main */

/**********************************************************************
Print 2 empty lines followed by the choices menu. Do NOT change this
function definition.
**********************************************************************/
void printmenu(void){
	printf("\n\n"
		"1. print input arguments (no spaces)\n"
		"2. remove first character\n"
		"3. remove vowels\n"
		"4. exit program\n");
}

/**********************************************************************
Print all nodes in a linked list of struct node type. Follow the print
format of the executable provided. Pass ONLY ONE PARAMETER to this
function.
**********************************************************************/
void printlinkedlist(/* pass only ONE parameter here */){
	
}


/**********************************************************************
Delete the head (first node) of a linked list of type struct node. Pass
ONLY ONE PARAMETER to this function.
return 0 - if the head of the linked list could be deleted successfully
return 1 - otherwise
**********************************************************************/
int delhead(/* pass only ONE parameter here */){
	
}

/**********************************************************************
Delete the vowels (a,e,i,o,u) in a sentence. Pass ONLY ONE PARAMETER to
this function.
return 0 - if all vowels were removed successfully
return 1 - otherwise
**********************************************************************/
int delvowels(/* pass only ONE parameter here */){
	
}
