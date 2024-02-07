#include <stdio.h>
#include <string.h>  // Added to use strcmp function

struct emp
{
    int eno, dno;
    char ename[20];
    float esal;
};

struct emp e[10];

int i;

void read(int n)
{
    printf("\nEnter the Employee Details\n");
    for ( i = 0; i < n; i++)
    {
        printf("Employee : %d\n", i + 1);  // Added a newline character
        printf("Enter the Employee No: ");
        scanf("%d", &e[i].eno);
        printf("Enter the Employee Name: ");
        scanf("%s", e[i].ename);
        printf("Enter the Employee Salary: ");
        scanf("%f", &e[i].esal);
        printf("Enter the DNo: ");
        scanf("%d", &e[i].dno);
    }
}

void disp(int n)
{
    printf("\nEmployee Details are: \n");
    for ( i = 0; i < n; i++)
    {
        printf("\n%d:Employee No: %d\nEmployee Name: %s\nEmployee Salary: %f\nDNo: %d\n", i + 1, e[i].eno, e[i].ename, e[i].esal, e[i].dno);
    }
}

void search(int n)
{
    int srch, flag = 0;
    printf("\nEnter the employee no. to be searched: ");
    scanf("%d", &srch);
    for ( i = 0; i < n; i++)
    {
        if (srch == e[i].eno)
        {
            flag = 1;
            printf("\nEmployee No: %d\nEmployee Name: %s\nEmployee Salary: %f\nDNo: %d\n", e[i].eno, e[i].ename, e[i].esal, e[i].dno);
            break;
        }
    }
    if (flag == 0)
    {
        printf("\nEmployee not found");
    }
}

void sort(int n)
{
    int ch, j;
    struct emp temp;

    printf("Sort on the basis of \n(1)Name\n(2)Salary\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        for ( i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (strcmp(e[i].ename, e[j].ename) > 0)
                {
                    temp = e[i];
                    e[i] = e[j];
                    e[j] = temp;
                }
            }
        }
        printf("Employees sorted on the basis of name: ");  // Added a message for sorting by name
        for ( i = 0; i < n; i++)
        {
            printf("\nEmployee No: %d\nEmployee Name: %s\nEmployee Salary: %f\nDNo: %d\n", e[i].eno, e[i].ename, e[i].esal, e[i].dno);
        }
        break;

    case 2:
        for ( i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (e[i].esal > e[j].esal)
                {
                    temp = e[i];
                    e[i] = e[j];
                    e[j] = temp;
                }
            }
        }
        printf("Employees sorted on the basis of salary: ");
        for ( i = 0; i < n; i++)
        {
            printf("\nEmployee No: %d\nEmployee Name: %s\nEmployee Salary: %f\nDNo: %d\n", e[i].eno, e[i].ename, e[i].esal, e[i].dno);
        }
        break;
    default:
        printf("\nInvalid Choice\n");
        break;
    }
}

void delete(int *n)
{
    int emp, i, found = 0, index, temp = 0;
    printf("\nEnter the employee no to be deleted: ");
    scanf("%d", &emp);
    for (i = 0; i < *n; i++)
    {
        if (emp == e[i].eno)
        {
            found = 1;
            index = i;
            break;
        }
    }
    if (found == 1)
    {
        for (i = index; i < *n - 1; i++)
        {
            e[i] = e[i + 1];
        }
        (*n)--;
        printf("\nEmployee with Employee No: %d has been deleted\n", emp);
        disp(*n);
    }
    else
    {
        printf("\nEmployee with Employee No: %d not found\n", emp);
    }
}

void process(int n)
{
    int c;
    for (c = menu(); c != 5; c = menu())
    {
        switch (c)
        {
        case 1:
            disp(n);
            break;
        case 2:
            search(n);
            break;
        case 3:
            sort(n);
            break;
        case 4:
            delete(&n);
            break;
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
}

int menu()
{
    int c;
    printf("\nChoices are: \n1.Display\n2.Search\n3.Sort\n4.Delete\n5.Exit\nEnter your choice: ");
    scanf("%d", &c);
    return c;
}

int main()
{
    int n;
    printf("Enter the no.of Employees: ");
    scanf("%d", &n);
    read(n);
    process(n);
}

