#include<stdio.h>
#include<malloc.h>

struct node
{
	char data[100];
	struct node *left;
	struct node *right;
};

typedef struct node tree;
tree *root=NULL;

void insert(char e[100])
{
	tree *p,*x;
	if(root==NULL)
	{
		root=(tree *)malloc(sizeof(tree));
		strcpy(root->data,e);
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		p=root;
		while(p!=NULL)
		{
			x=p;
			if(strcmp(p->data,e)>0)
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}
		}
		if(strcmp(x->data,e)>0)
		{
			x->left=(tree *)malloc(sizeof(tree));
			strcpy(x->left->data,e);
			x->left->left=NULL;
			x->left->right=NULL;
		}
		else
		{
			x->right=(tree *)malloc(sizeof(tree));
			strcpy(x->right->data,e);
			x->right->left=NULL;
			x->right->right=NULL;
		}
	}
}

void inorder(tree *r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		printf("%s\t",r->data);
		inorder(r->right);
	}
}

void preorder(tree *r)
{
	if(r!=NULL)
	{
		printf("%s\t",r->data);
		preorder(r->left);
		preorder(r->right);
	}
}

void postorder(tree *r)
{
	if(r!=NULL)
	{
		postorder(r->left);
		postorder(r->right);
		printf("%s\t",r->data);
	}
}

int main()
{
	insert("ALFIA");
	insert("ALTHAF");
	insert("AFTHAB");
	insert("SAFEENA");
	insert("HAMSA");
	printf("\nInorder\n");
	inorder(root);
	printf("\nPreorder\n");
	preorder(root);
	printf("\nPostorder\n");
	postorder(root);
}
