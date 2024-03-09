#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node dlist;
dlist *head = NULL;

void insertNode(int e)
{
    dlist *t;
    if(head == NULL)    
    {
        head = (dlist *)malloc(sizeof(dlist));
        head->data = e;
        head->next = NULL;
        head->prev = NULL;
    }
    else 
    {
        t = head;
        while(t->next != NULL)
        {
            t= t->next;
        }
        t->next = (dlist *)malloc(sizeof(dlist));
        t->next->data = e;
        t->next->next = NULL;
        t->next->prev = t;
    }
}
void deleteNode(int e) 
{
    dlist *t;
    if(head == NULL) // list is empty
    { 
        printf("DList is empty");
    }
    else if(head->data == e && head->next == NULL) // list has only one element to be deleted
    { 
        head = NULL;
    }
    else if(head->data == e) //first element but several elements
    { 
        head = head->next;
        head->prev = NULL;
    }
    else 
    {
        t = head;
        while(t != NULL) //traversing and searching for the node
        { 
            if(t->data == e)
            {
                break;
            }   
            t = t->next;
        }
        if(t == NULL) //case 6 not found
        { 
            printf("Not Found..");
        }
        else if(t->next == NULL)  //case 5 last node
        {
            t->prev->next = NULL;
        }
        else //case 4 intermediate node
        { 
            t->prev->next = t->next;
            t->next->prev = t->prev;
        }
    }
}

void disp() 
{
    dlist *t;
    printf("\n");
    for(t= head;t != NULL;t= t->next)
    {
        printf("%d\t",t->data);
    }
}

int menu()
{
    int ch;
    printf("\n1.Insert a node\n2.Delete a node\n3.Display\n4.Exit\nEnter your choice: ");
    scanf("%d",&ch);
    return ch;
}

void process()
{
    int n;
    for(n=menu();n!=4;n=menu())
    {
        switch(n)
        {
            case 1: printf("Enter the node to be inserted: ");
                    scanf("%d",&n);
                    insertNode(n);
                    break;
            
            case 2: printf("Enter the node to be deleted: ");
                    scanf("%d",&n);
                    deleteNode(n);
                    break;
                    
            case 3: disp();
                    break;
                    
            default:printf("Error: Invalid Choice");
                    break;
                    
        }
    }
}

int main()
{
    process();
    return 0;
}

