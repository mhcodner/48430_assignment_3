/**********************************************************************
48430 Embedded C - Advanced Assignment
Name: Michael Codner
Student ID: 11989668
Date of submission: 06/06/2016
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
    char c;
    struct node *next;
};

typedef struct node node_t;

/**********************************************************************
Function prototypes - do NOT change the given prototypes. However you
may define your own functions if required.
**********************************************************************/
void printmenu(void);
void printlinkedlist(node_t*);
int delhead(node_t**);
int delvowels(node_t**);

/**********************************************************************
Main
**********************************************************************/
int main (int argc, char* argv[]) {
    if (argc == 1) { /* The first argument is always the name of the program */
        printf("Parse a sentence");
        return 1; /* Exit the program with status of 1 (error) if there were no arguments */
    }

    node_t* head = NULL; /* Initialise the linked list */
    head = malloc(sizeof(node_t)); /* Allocate memory for the first element */
    if (head == NULL) { /* There must be some kind of error if we can't allocate memory for the first element */
        return 1;
    }
    int i, j; /* i is the index of words in argv, j is the index of characters in each word */
    node_t* current = head; /* current is temporarily used while populating the list */
    for (i = 1; i < argc; i++) { /* Loop over all argument "words" */
        for (j = 0; argv[i][j] != '\0'; j++) { /* Loop over each character in each word */
            current->c = argv[i][j]; /* Add the character to the linked list */
            current->next = malloc(sizeof(node_t)); /* Allocate memory for the next item */
            current = current->next; /* Set current to the pointer for the next item so that we continue
                                      * adding to the list instead of changing the same item */
        }
    }
    current->next = NULL; /* Signify the end of the list with a NULL pointer */

    char choice; /* Used to keep track of the user's choice*/
    do {
        printmenu();
        printf("Enter your choice>");
        scanf("%1[^\n]", &choice); /* Read in a character to the choice variable */
        switch (choice) {
            case '1':
                printlinkedlist(head);
                break;
            case '2':
                if (head == NULL)
                    printf("Pop failed.\n"); /* Can't remove elements from an empty list */
                else
                    delhead(&head);
                break;
            case '3':
                if (head == NULL)
                    printf("Del failed.\n"); /* Can't remove elements from an empty list */
                else
                    delvowels(&head);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
        while (getchar() != '\n'); /* Clear extra characters from input stream */
    } while (choice != 4);

    return 0;
}
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
void printlinkedlist(node_t* head){
    node_t* current = head; /* Used to keep track of the current item in the list */

    while (current != NULL) { /* Loop until the end which is signified by NULL */
        printf("%c", current->c); /* Prints each character in the list */
        current = current->next; /* Set current to the pointer for the next item so that we continue
                                  * printing the list instead of printing the same item */
    }
    printf("\n");
}


/**********************************************************************
Delete the head (first node) of a linked list of type struct node. Pass
ONLY ONE PARAMETER to this function.
return 0 - if the head of the linked list could be deleted successfully
return 1 - otherwise
**********************************************************************/
int delhead(node_t** head){
    node_t* next_node = NULL; /* Initalise the temporary new head with NULL */

    if (*head == NULL) { /* Can't remove the first element from an empty list */
        return 0;
    }

    next_node = (*head)->next; /* Set our temporary new head to the value of the second item */
    free(*head); /* Free the memory for the initial head */
    *head = next_node; /* Set the head to our temporary head */

    return 1;
}

/**********************************************************************
Delete the vowels (a,e,i,o,u) in a sentence. Pass ONLY ONE PARAMETER to
this function.
return 0 - if all vowels were removed successfully
return 1 - otherwise
**********************************************************************/
int delvowels(node_t** head){
    char vowels[] = "aeiouAEIOU"; /* Array of characters for all vowels to be removed */

    int i, vowelsRemoved; /* i is the index of the vowel array, vowelsRemoved keeps track of how many were removed */
    for (i = 0, vowelsRemoved = 0; i < 10; i++) {
        /* Store head node as temp and initialise the previous head */
        node_t* temp = *head, *prev;
        char key = vowels[i]; /* key holds the current vowel to be removed */
        /* Removes occurrences of key from start of head */
        while (temp != NULL && temp->c == key)
        {
            *head = temp->next;   /* Update head to the temporary head */
            free(temp);           /* Free memory for old head */
            temp = *head;         /* Update temp to the next head */
            vowelsRemoved++;      /* Increase count of vowels removed */
        }

        /* Remove occurrences of key not at the start */
        while (temp != NULL)
        {
            /* Search for the key to be deleted, keep track of the
             previous node as we need to change 'prev->next'
             */
            while (temp != NULL && temp->c != key)
            {
                prev = temp;
                temp = temp->next;
            }

            /* If key was not present in linked list */
            if (temp == NULL) continue;

            /* Unlink the node from linked list */
            prev->next = temp->next;

            free(temp);  /* Free memory */

            /* Update Temp for next iteration of outer loop */
            temp = prev->next;
            vowelsRemoved++; /* Update count of vowels removed */
        }
    }

    return (vowelsRemoved > 0); /* Returns true for more than 0 vowels removed */
}
