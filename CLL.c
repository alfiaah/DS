#include <stdio.h>
#include <stdlib.h>

struct node 
{
 int data;
 struct node *next;
};
typedef struct node CList;
CList *head = NULL;

void insert(int e)
{
    CList *t;
    if(head == NULL) 
    {
        head = (CList *)malloc(sizeof(CList));
        head->data = e;
        head->next = head;
    }
    else 
    {
        t = head;
        while(t->next != head) 
        {
            t = t->next;
        }
        t->next = (CList *)malloc(sizeof(CList));
        t->next->data = e;
        t->next->next = head;
    }
}

void deleteNode(int e)
{
    CList *t;
    if(head == NULL)
    {
        printf("List is empty..");
    }
    else if(head->data == e) //one element / several
    { 
        if(head->next == head) //only element and it has to be deleted
        { 
            head = NULL;
        }
        else // head data to be deleted but several elements
        { 
            t = head;
            while(t->next != head) 
            {
                t = t->next;
            }
            t->next = head->next; //last node next should point to the next of head
            head = head->next; //head is moved to the next of head
        }
    }
 else //intermediate or last node
 { 
    t = head;
    while(t->next != head) 
    {
        if(t->next->data == e) 
        {
        t->next = t->next->next;
        return;
        }
        t = t->next;
    }
    printf("Not found..");
    }
}

void disp()
{
    CList *t;
    printf("\n");
    if(head == NULL) 
    {
        printf("List is empty");
    }
    else
    {
        t = head;
        do
        {
            printf("%d\t",t->data);
            t = t->next;
        }while(t != head);
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
                    insert(n);
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

