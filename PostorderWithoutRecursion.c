#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node tree;

tree *root=NULL;

struct stack
{
	tree *r;
	struct stack *next;
};

typedef struct stack stack;

stack *top=NULL;

void insert(int e)
{
	tree *p,*x;
	if(root==NULL)
	{
		root=(tree *)malloc(sizeof(tree));
		root->data=e;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		p=root;
		while(p!=NULL)
		{
			x=p;
			if(p->data>e)
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}
		}
		if(x->data>e)
		{
			x->left=(tree *)malloc(sizeof(tree));
			x->left->data=e;
			x->left->left=NULL;
			x->left->right=NULL;
		}
		else
		{
			x->right=(tree *)malloc(sizeof(tree));
			x->right->data=e;
			x->right->left=NULL;
			x->right->right=NULL;
		}
	}
}

void push(tree *t)
{
	stack *temp=(stack *)malloc(sizeof(stack));
	temp->r=t;
	temp->next=top;
	top=temp;
}

tree *pop()
{
	tree *t=NULL;
	if(top!=NULL)
	{
		t=top->r;
		top=top->next;
	}
	return t;
}

void postorder(tree *r)
{
	if(r==NULL)
	{
		return;
	}
	
	stack *s1=NULL;
	
	do
	{
		while(r)
		{
			if(r->right)
			{
				push(r->right);
			}
			push(r);
			r=r->left;
		}
		r=pop();
		if(r->right&&top&&r->right==top->r)
		{
			pop();
			push(r);
			r=r->right;
		}
		else
		{
			printf("%d\t",r->data);
			r=NULL;
		}
	}while(top);
}

int main()
{
	insert(100);
	insert(150);
	insert(20);
	insert(50);
	insert(250);
	insert(300);
	postorder(root);
}
