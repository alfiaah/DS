#include<stdio.h>
int coeff1[10];
int i;
int read(int degree)
{
	printf("Enter the elements the polynomial: \n");
	for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("Enter the constant term:",i);
			scanf("%d",&coeff1[i]);
			break;
		}
		printf("Enter the coefficient of x^%d:",i);
		scanf("%d",&coeff1[i]);
	}
}

int disp(int degree)
{
    printf("The polynomial is: \n");
    for(i=degree;i>=0;i--)
	{
		if(i==0)
		{
			printf("%d",coeff1[i]);
			break;
		}
		printf("%dx^%d+",coeff1[i],i);
	}
}
int main()
{
	int degree;
	printf("Enter the degree of the polynomial: ");
	scanf("%d",&degree);
	read(degree);
	disp(degree);
}

