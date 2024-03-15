#include <stdio.h>

int f = -1, r = -1;
int q[5];

void enqueue(int e) // inserting an element into the queue
{
    if (((r + 1) % 5) == f) // Check if the queue is full
    {
        printf("\nQueue is full");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
        r = (r + 1) % 5;
        q[r] = e;
    }
}

void dequeue()
{
    if (f == -1)
    {
        printf("\nQueue Empty");
    }
    else
    {
        printf("\nDequeued Element is : %d", q[f]);

        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f = (f + 1) % 5;
        }
    }
}

void displayQueue()
{
    if (f == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        int i = f;
        printf("\nQueue elements: ");
        while (1)
        {
            printf("%d ", q[i]);

            if (i == r)
            {
                break;
            }

            i = (i + 1) % 5;
        }
        printf("\n");
    }
}

void process(int c)
{
    int e;
    for (c = menu(); c != 4; c = menu())
    {
        switch (c)
        {
        case 1: printf("Enter the element to be inserted: \n");
                scanf("%d",&e);
                enqueue(e);
                break;
        case 2: dequeue();
                break;
        case 3: displayQueue();
                break;
        default:printf("\nError: Invalid Choice");
                break;
        }
    }
}


int menu()
{
    int c;
   printf("\nChoices are: \n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
    scanf("%d", &c);
    return c;
}

int main()
{
    int c;
    
    process(c);
}


