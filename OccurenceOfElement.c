#include<stdio.h>
int arr[10],i,ele;
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
void search(int n)
{
    int ele,m=0;
    printf("\nEnter the element to be searched for: ");
    scanf("%d",&ele);
    for(i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            printf("\nElement found at position %d",i);
            m=m+1;
        }
    }
    if(m>0)
    {
        printf("\nElement %d has %d occurence",ele,m);
    }
    else
    {
        printf("\nElement not found");
    }
}
int main()
{
    int n;
    printf("Enter the limit of the array: ");
    scanf("%d",&n);
    read(n);
    disp(n);
    search(n);
}

