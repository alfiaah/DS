
#include<stdio.h>
#include<malloc.h>

struct poly1
{
	int coeff;
	int exp;
	struct poly1 *next;
};

typedef struct poly1 poly1;
poly1 *head1=NULL;

struct poly2
{
	int coeff;
	int exp;
	struct poly2 *next;
};

typedef struct poly2 poly2;

poly2 *head2=NULL;

void insertpoly1(int coeff,int exp)
{
	if(head1==NULL)
	{
		head1=(poly1 *)malloc(sizeof(poly1));
		head1->coeff=coeff;
		head1->exp=exp;
		head1->next=NULL;
	}
	else
	{
		poly1 *t=head1;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(poly1 *)malloc(sizeof(poly1));
		t->next->coeff=coeff;
		t->next->exp=exp;
		t->next->next=NULL;
	}
}

void insertpoly2(int coeff,int exp)
{
	if(head2==NULL)
	{
		head2=(poly2 *)malloc(sizeof(poly2));
		head2->coeff=coeff;
		head2->exp=exp;
		head2->next=NULL;
	}
	else
	{
		poly2 *t=head2;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(poly2 *)malloc(sizeof(poly2));
		t->next->coeff=coeff;
		t->next->exp=exp;
		t->next->next=NULL;
	}
}

void disp1()
{
	if(head1==NULL)
	{
		printf("Polynomial is not inserted\n");
	}
	else
	{
		poly1 *t=head1;
		while(t->next!=NULL)
		{
			printf("%dx^%d+",t->coeff,t->exp);
			t=t->next;
		}
		printf("%dx^%d",t->coeff,t->exp);
	}
}

void disp2()
{
	if(head2==NULL)
	{
		printf("Polynomial is not inserted\n");
	}
	else
	{
		poly2 *t=head2;
		while(t->next!=NULL)
		{
			printf("%dx^%d+",t->coeff,t->exp);
			t=t->next;
		}
		printf("%dx^%d",t->coeff,t->exp);
	}
}

void mul()
{
	int mul,expval;
	if(head1==NULL && head2==NULL)
	{
		printf("Polynomials Are Not Inserted Addition Not Possible");	
	}	
	else if(head1!=NULL && head2==NULL)
	{
		printf("\nResult: ");
		disp1();
	}
	else if(head1==NULL && head2!=NULL)
	{
		printf("\nResult: ");
		disp2();
	}
	else
	{
		poly1 *t1;
		poly2 *t2;
		printf("Result");
		while (t1 != NULL || t2 != NULL)
        {
            for(t1=head1;t1!=NULL;t1=t1->next)
            {
            	for(t2=head2;t2!=NULL;t2=t2->next)
            	{
            		mul=t1->coeff*t2->coeff;
            		expval=t1->exp+t2->exp;
            		printf("%dx^%d+",mul,expval);
				}
			}
        }
        printf("\n");
    }
}
	

int main()
{
	int ch,coeff,exp,n;
	do
	{
		printf("Choices Are: \n1.Insert\n2.Display\n3.Multiply\n4.Exit\nEnter Your Choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("Which polynomial is to be inserted (1 or 2): ");
					scanf("%d",&n);
					switch(n)
					{
						case 1:	printf("Enter the Value of 1st polynomial:\n ");
								printf("Enter the Coefficient Value: ");
								scanf("%d",&coeff);
								printf("Enter the Exponent Value: ");
								scanf("%d",&exp);
								insertpoly1(coeff,exp);
								break;
								
						case 2:	printf("Enter the Value of 2nd polynomial:\n");
								printf("Enter the Coefficient Value: ");
								scanf("%d",&coeff);
								printf("Enter the Exponent Value: ");
								scanf("%d",&exp);
								insertpoly2(coeff,exp);
								break;
								
						default: printf("\nInvalid Choice");
								 break;
					}
					break;
					
			case 2: printf("Which polynomial is to be displayed (1 or 2): ");
					scanf("%d",&n);
					switch(n)
					{
						case 1: disp1();
								break;
						case 2: disp2();
								break;
						default: printf("\nInavlid Choice");
								break;
					}
					break;
					
			case 3: mul();
					break;
			case 4: printf("Exiting");
					break;
					
			default: printf("Invalid Choice");
					 break;
		}	
	}while(ch!=4);
}
