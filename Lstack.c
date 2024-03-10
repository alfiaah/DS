#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node stack;
enum{PUSH=1,POP,EXIT};
stack * top=NULL;

void push(int e)
{
    stack *t=(stack*)malloc(sizeof(stack));
    t->data=e;
    t->next=top;
    top=t;
}

void pop()
{
    if(top==NULL)
    {
        printf("Empty Stack");
    }
    else
    {
        printf("\n%d",top->data);
        top=top->next;
    }
}

int menu()
{
    int ch;
    printf("\n1.PUSH\n2.POP\n3.Exit\nYour Choice: ");
    scanf("%d",&ch);
    return ch;
}

void process(int ch)
{
    int e;
    for(ch=menu();ch!=3;ch=menu())
    {
        switch(ch)
        {
            case PUSH:  printf("Enter the element to push: ");
                        scanf("%d",&e);
                        push(e);
                        break;
            case POP:   pop();
                        break;
            default:    printf("Error: Invalid Choice");
                        break;
        }
    }
}

int main()
{
    int ch;
    process(ch);
    return 0;
}

