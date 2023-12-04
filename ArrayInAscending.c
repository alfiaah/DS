#include<stdio.h>
int arr[10],i,j,temp;
void read(int n)
{
    printf("\nEnter the array elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void disp(int n)
{
    printf("\nThe array elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void sort(int n)
{
  for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				
			}
		}
	}
	printf("\nSorted Array Elements are: ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
int main()
{
    int n;
    printf("Enter the limit of the array: ");
    scanf("%d",&n);
    read(n);
    disp(n);
    sort(n);
}

