#include<stdio.h>

#include<string.h>

int stack[20],top=-1;

char a[20];

int i;

void pop()

{

    printf("\nReversed String : ");

    for(i=top;top>=-1;top--)

    {

   	 printf("%c",stack[top]);

    }

}

void push()


{

    

    for(i=0;i<strlen(a);i++)

    {

   	 top++;

   	 stack[top]=a[i];

    }

    pop();

}



void main()

{

    printf("\nEnter the string : ");

    gets(a);

    push(a);

}

