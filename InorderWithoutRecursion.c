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
			if(x->data>e)
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

void inorder(tree *root)
{
	tree *t;
	for(t=root;t!=NULL;t=t->left)
	{
		push(t);
	}
	t=pop();
	while(t!=NULL)
	{
		printf("%d\t",t->data);	
		for(t=t->right;t!=NULL;t=t->left)
		{	
			push(t);
		}
		t=pop();
	}
}

int main()
{
	insert(100);
	insert(150);
	insert(20);
	insert(50);
	insert(250);
	insert(300);
	inorder(root);
}
