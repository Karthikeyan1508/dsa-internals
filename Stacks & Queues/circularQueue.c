#include<stdio.h>
#include<stdlib.h>  
#include<conio.h>   

#define max 3

int q[10], front=0, rear=-1;

// Function prototypes
void insert();
void delet();
void display();

void main()
{
    int ch;

    clrscr();
    printf("\nCircular Queue operations\n");
    printf("1.insert\n2.delete\n3.display\n4.exit\n");

    while(1)
    {
        printf("Enter your choice:");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delet();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
}

void insert()
{
    int x;
    if ((front == 0 && rear == max - 1) || (front > 0 && rear == front - 1))
        printf("Queue is overflow\n");
    else
    {
        printf("Enter element to be inserted:");
        scanf("%d", &x);

        if (rear == max - 1 && front > 0)
            rear = 0;
        else
            rear = (rear + 1) % max;

        q[rear] = x;
    }
}

void delet()
{
    int a;
    if (front == 0 && rear == -1)
    {
        printf("Queue is underflow\n");
        getch();
        exit(0);
    }

    a = q[front];
    if (front == rear)
    {
        front = 0;
        rear = -1;
    }
    else
        front = (front + 1) % max;

    printf("Deleted element is: %d\n", a);
}

void display()
{
    int i;

    if (front == 0 && rear == -1)
    {
        printf("Queue is underflow\n");
        getch();
        exit(0);
    }

    printf("Queue elements are:");
    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
            printf(" %d", q[i]);
    }
    else
    {
        for (i = front; i < max; i++)
            printf(" %d", q[i]);

        for (i = 0; i <= rear; i++)
            printf(" %d", q[i]);
    }

    printf("\n");
    getch();
}
