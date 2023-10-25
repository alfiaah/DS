#include<stdio.h>

int a=10,b;

void stat()
{
	static int c,d=1;
	int i;
	printf("\nIn Stack\n");
	for(i=0;i<5;i++)
	{
		printf("%d:c, %d:d\n",c++,d++);
	}
}

void reg()
{
	register int e,f=5;
	int a;
	a=e+f;
	a=a+10;
	printf("\nIn Register\n");
	printf("a:%d",a);
}

int main()
{
	int h,i=9;
	printf("Value of Local Variable h by default: %d\nValue of Local Variable i Intialized: %d\n",h,i);
	printf("Value of Global Variable b by default: %d\nValue of Global Variable a Intialized: %d\n",b,a);
	stat();
	reg();}
