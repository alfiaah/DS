#include <stdio.h>

void read(int arr[],int n)
{
    int i;
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void dispRec(int arr[],int n,int index)
{
    if(index < 0)
    {
        return;
    }
    else
    {
        printf("%d ", arr[index]);
        dispRec(arr, n, index-1);
    }
}

int main()
{
    int n,arr[10];
    printf("Enter the limit of the array: ");
    scanf("%d",&n);
    
    read(arr,n);
    
    printf("\nArray Elements are: ");
    dispRec(arr,n,n-1);
}

