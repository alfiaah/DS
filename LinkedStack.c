#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node stack;
stack *top=NULL;

void push(int e)
{
	stack *t=(stack *)malloc(sizeof(stack));
	t->data=e;
	t->next=top;
	top=t;
}

void pop()
{
	if(top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("%d is popped out\n",top->data);
		top=top->next;
	}
}

void peek()
{
	if(top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Peek :%d\n",top->data);
	}
}

void display()
{
	if(top==NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		stack *tp=top;
		while(tp!=NULL)
		{
			printf("%d\t",tp->data);
			tp=tp->next;
		}
		printf("\n");
	}
}

int main()
{
	peek();
	push(50);
	display();
	push(65);
	display();
	peek();
	push(20);
	display();
	push(89);
	display();
	pop();
	display();
	pop();
	display();
	peek();
	pop();
	display();
	pop();
	display();
}
