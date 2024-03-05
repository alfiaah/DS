#include<stdio.h>
#include<malloc.h>

struct node
{
	int coeff;
	int exp;
	struct node *next;
};

typedef struct node poly;

poly *head=NULL;

void insert(int coeff,int exp)
{
	if(head==NULL)
	{
		head=(poly *)malloc(sizeof(poly));
		head->coeff=coeff;
		head->exp=exp;
		head->next=NULL;
	}
	else
	{
		poly *t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(poly *)malloc(sizeof(poly));
		t->next->coeff=coeff;
		t->next->exp=exp;
		t->next->next=NULL;
	}
}

void disp()
{
	if(head==NULL)
	{
		printf("Polynomial is not inserted\n");
	}
	else
	{
		poly *t=head;
		while(t->next!=NULL)
		{
			printf("%dx^%d+",t->coeff,t->exp);
			t=t->next;
		}
		printf("%dx^%d",t->coeff,t->exp);
	}
}

int main()
{
	int ch,coeff,exp;
	do
	{
		printf("Choices Are: \n1.Insert\n2.Display\n3.Exit\nEnter Your Choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("Enter the Coefficient Value: ");
					scanf("%d",&coeff);
					printf("Enter the Exponent Value: ");
					scanf("%d",&exp);
					insert(coeff,exp);
					break;
					
			case 2: disp();
					break;
					
			case 3: printf("Exiting");
					break;
					
			default: printf("Invalid Choice");
					 break;
		}	
	}while(ch!=3);
}
