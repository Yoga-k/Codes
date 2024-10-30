/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>



/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* createNode(int data)
{
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertAtFirst(node** head, int data)
{
    node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtPosition(node** head, int data, int pos)
{
    if(pos == 0)
    {
        insertAtFirst(head, data);
        return;
    }
    
    node* newNode = createNode(data);
    node* curr = *head;

    for(int i = 0; curr != NULL && i < (pos-1); i++)
    { 
        curr = curr->next;
    }
    if(curr == NULL)
    {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    
}

void insertAtEnd(node** head, int data)
{
    node* newNode = createNode(data);
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    node* curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;        
    }
    curr->next = newNode;
}

void deleteAtFirst(node** head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node* curr = *head;
    *head = curr->next;
    free(curr);
}

void deleteAtEnd(node** head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node* curr = *head;
    node* prev;
    
    while(curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;

    }
    prev->next = NULL;
    free(curr);
}

void deleteAtPosition(node** head, int pos)
{
    if(pos == 0)
    {
        deleteAtFirst(head);
        return;
    }
    
    node* curr = *head;
    node* prev;

    for(int i = 0; curr != NULL && i < (pos); i++)
    { 
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL)
    {
        printf("Position out of range\n");
        free(curr);
        return;
    }

    prev->next = curr->next;
    free(curr);
    
}

void deleteNode(node** head)
{

    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    node* curr = *head;
    if(curr->next == NULL)
    {
        free(curr);
        *head = NULL;
        printf("Item deleted: \n");
        return;
    }

    while(curr->next->next != NULL)
    {
        curr = curr->next;
    
    }
    free(curr->next);
    curr->next = NULL;
    printf("Item deleted: \n");


}
void displayNodes(node* head)
{
    printf("Items in the linkedlist: ");
    node* curr = head;
    while(curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int showInsertOptions()
{
    int choice;
    printf("1.Insert at the first\n");
    printf("2.Insert at the end\n");
    printf("3.Insert at the position\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    return choice;
}

int showDeleteOptions()
{
    int choice;
    printf("1.Delete at the first\n");
    printf("2.Delete at the end\n");
    printf("3.Delete at the position\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    return choice;
}

int showMenu()
{
    int choice = 0;
    printf("1.Insert \n");
    printf("2.Delete\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    node* head;
    int choice;
    do
    {
        choice = showMenu();
        if(choice == 1)
        {
            int insertChoice = showInsertOptions();
            int val;
            printf("Enter the val to be inserted: \n");
            scanf("%d", &val);
            if(insertChoice == 1)
            {
                insertAtFirst(&head, val);
            }
            else if(insertChoice == 2)
            {
                insertAtEnd(&head, val);
            }
            else if(insertChoice == 3)
            {
                int pos;
                printf("Enter the position to be inserted \n");
                scanf("%d", &pos);
                insertAtPosition(&head, val, pos);
            }
            
            printf("Element inserted\n");
        }
        else if(choice == 2)
        {
            int insertChoice = showDeleteOptions();
            int val;

            if(insertChoice == 1)
            {
                deleteAtFirst(&head);
            }
            else if(insertChoice == 2)
            {
                deleteAtEnd(&head);
            }
            else if(insertChoice == 3)
            {
                int pos;
                printf("Enter the position to be Deleted \n");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
            }
            
            printf("Element Deleted\n");

        }
        else if(choice == 3)
        {
            displayNodes(head);
        }
        
    }while(choice != 4);

    return 0;
}

