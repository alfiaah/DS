#include<stdio.h>

struct date
{
    int date1,month1,year1;
    int date2,month2,year2;
};

struct date d;

void read()
{
    printf("Enter the 1st Date(dd-mm-yyyy): "); 
    scanf("%d-%d-%d",&d.date1,&d.month1,&d.year1);
    printf("Enter the 2nd Date(dd-mm-yyyy): ");
    scanf("%d-%d-%d",&d.date2,&d.month2,&d.year2);
}

void disp()
{
    printf("\n1st Date: %d-%d-%d",d.date1,d.month1,d.year1);
    printf("\n2nd Date: %d-%d-%d",d.date2,d.month2,d.year2);
}

void compare()
{
    if(d.date1==d.date2&&d.month1==d.month2&&d.year1==d.year2)
    {
        printf("\nTwo Dates are Same");
    }
    else
    {
        printf("\nTwo Dates are not Same");
    }
}

int main()
{
    read();
    disp();
    compare();
}

