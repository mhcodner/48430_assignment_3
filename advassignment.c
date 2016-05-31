/**********************************************************************
48430 Embedded C - Advanced Assignment
Name: Michael Codner
Student ID: 11989668
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
    if (argc == 1) {
        printf("Parse a sentence.\n");
        return 1;
    }

    node_t* head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    int i, j;
    node_t* current = head;
    for (i = 1; i < argc; i++) {
        for (j = 0; argv[i][j] != '\0'; j++) {
            current->c = argv[i][j];
            current->next = malloc(sizeof(node_t));
            current = current->next;
        }
    }
    current->next = NULL;

    char choice;
    do {
        printmenu();
        printf("Enter your choice>");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printlinkedlist(head);
                break;
            case '2':
                delhead(&head);
                break;
            case '3':
                delvowels(&head);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
        while (getchar() != '\n');
    } while (choice != 4);
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
    node_t * current = head;

    while (current != NULL) {
        printf("%c", current->c);
        current = current->next;
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
    node_t * next_node = NULL;

    if (*head == NULL) {
        return 0;
    }

    next_node = (*head)->next;
    free(*head);
    *head = next_node;

    return 1;
}

/**********************************************************************
Delete the vowels (a,e,i,o,u) in a sentence. Pass ONLY ONE PARAMETER to
this function.
return 0 - if all vowels were removed successfully
return 1 - otherwise
**********************************************************************/
int delvowels(node_t** head){
    char vowels[] = "aeiouAEIOU";

    int i;
    for (i = 0; i < 10; i++) {
        /*Store head node*/
        node_t* temp = *head, *prev;
        char key = vowels[i];
        /* If head node itself holds the key or multiple occurrences of key*/
        while (temp != NULL && temp->c == key)
        {
            *head = temp->next;   /* Changed head*/
            free(temp);           /* free old head*/
            temp = *head;         /* Change Temp*/
        }

        /* Delete occurrences other than head*/
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

            /* If key was not present in linked list*/
            if (temp == NULL) continue;

            /* Unlink the node from linked list*/
            prev->next = temp->next;

            free(temp);  /* Free memory*/

            /* Update Temp for next iteration of outer loop*/
            temp = prev->next;
        }
    }

    return 1;
}
