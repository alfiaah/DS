#include<stdio.h>

struct poly
{
	int coeff;
	int exp;
};

typedef struct poly poly;
poly p[5];

void read(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the coefficient and exponent: ");
		scanf("%d %d",&p[i].coeff,&p[i].exp);
	}
}

void disp(int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		printf("%dx^%d",p[i].coeff,p[i].exp);
		printf("%s",p[i+1].coeff>0?"+":"-");
	}
	if(p[i].exp==0)
	{
		printf("%d",p[i].coeff);
	}
}

int main()
{
	int n;
	printf("Enter the no.of elements");
	scanf("%d",&n);
	read(n);
	disp(n);
}
