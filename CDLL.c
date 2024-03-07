#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include the string.h library for string operations

struct node
{
    char data[100]; // Modify the data part to store strings
    struct node *next;
    struct node *prev;
};

typedef struct node doblist;
doblist *head = NULL;

void insertNode(char e[])
{
    doblist *t;
    doblist *newNode = (doblist *)malloc(sizeof(doblist)); // Allocate memory for the new node
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newNode->data, e); // Copy the string data into the new node

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        t = head;
        while (t->next != head)
        {
            t = t->next;
        }
        t->next = newNode;
        newNode->next = head;
        newNode->prev = t;
        head->prev = newNode;
    }
}

void deleteNode(char e[])
{
    doblist *t;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (strcmp(head->data, e) == 0 && head->next == head)
    {
        free(head);
        head = NULL;
    }
    else if (strcmp(head->data, e) == 0)
    {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        t = head;
        head = head->next;
        free(t);
    }
    else
    {
        t = head->next;
        while (t != head)
        {
            if (strcmp(t->data, e) == 0)
            {
                break;
            }
            t = t->next;
        }
        if (t == head)
        {
            printf("Not Found\n");
        }
        else
        {
            t->prev->next = t->next;
            t->next->prev = t->prev;
            free(t);
        }
    }
}

void disp()
{
    doblist *t;
    printf("\n");
    if (head == NULL)
    {
        printf("Empty\n");
        return;
    }
    else
    {
        t = head;
        do
        {
            printf("%s\t", t->data);
            t = t->next;
        } while (t != head);
    }
}

int menu()
{
    int ch;
    printf("\n1.Insert a node\n2.Delete a node\n3.Display\n4.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void process()
{
    char str[100];
    int n;
    for (n = menu(); n != 4; n = menu())
    {
        switch (n)
        {
        case 1:
            printf("Enter the string to be inserted: ");
            scanf("%s", str);
            insertNode(str);
            break;

        case 2:
            printf("Enter the string to be deleted: ");
            scanf("%s", str);
            deleteNode(str);
            break;

        case 3:
            disp();
            break;

        default:
            printf("Error: Invalid Choice\n");
            break;
        }
    }
}

int main()
{
    process();
    return 0;
}

