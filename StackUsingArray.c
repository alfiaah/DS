#include<stdio.h>
int stack[5],top=-1;

void push(int e)
{
	if( top+1==5)
	{
		printf("Error:Stack is Full");
	}
	else
	{
		stack[++top]=e;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("Error: Stack is empty");
	}
	else
	{
		printf("Deleted Element: %d",stack[top--]);
	}
}

void disp()
{
    int i;
    if (top == -1) 
    {
        printf("Stack is Empty");
    }
    else 
    {
        printf("Stack elements are:  ");
        for ( i = top; i >= 0; i--) 
        {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

int menu()
{
	int ch;
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}

void process()
{
	int ch;
	for(ch=menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1: printf("\nEnter the element: ");
					scanf("%d",&ch);
					push(ch);
					break;
					
			case 2: pop();
					break;
					
			case 3: disp();
			        break;
					
			default: printf("Invalid Choice");
		}
	}
}

int main()
{
	process();
	return 0;
}

